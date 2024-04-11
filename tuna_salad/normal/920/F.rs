//spnauti-rusT {{{
use std::io::*; use std::str::{self,*}; use std::fmt::Debug;
#[allow(unused_imports)] use std::cmp::Ordering::{self,*};
#[allow(unused_imports)] use std::ops::{self,*};
#[allow(unused_imports)] use std::iter::{self,*};
#[allow(unused_imports)] use std::collections::*;
#[allow(unused_imports)] use std::cell::*;
#[allow(unused_macros)] macro_rules! min {
	($x:expr,$y:expr) => {{ let b=$y; let a=&mut$x; if b < *a {*a=b; true} else {false} }};
}
#[allow(unused_macros)] macro_rules! max {
	($x:expr,$y:expr) => {{ let b=$y; let a=&mut$x; if b > *a {*a=b; true} else {false} }};
}
#[allow(unused_macros)] macro_rules! l {
	($($v:ident),+ =$e:expr) => {$(let$v=$e;)+};
	($($v:ident),+:$t:ty=$e:expr) => {$(let$v:$t=$e;)+};
	(mut $($v:ident),+ =$e:expr) => {$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr) => {$(let mut$v:$t=$e;)+};
}
#[allow(unused_macros)] macro_rules! v {
	([$d:expr]$($s:tt)+) => {vec![v!($($s)+);$d]};
	([]) => {Vec::new()}; ([$e:expr]) => {Vec::with_capacity($e)}; (=$e:expr) => {$e};
}
#[allow(unused_macros)] macro_rules! rep { {[$c:expr]$($s:tt)+} => {for _ in 0..$c {$($s)+}} }
#[allow(dead_code)] fn reader() -> WordReaderC { WordReaderC::new() }
#[allow(dead_code)] fn writer() -> BufWriter<Stdout> { BufWriter::new(stdout()) }
struct WordReaderC {buf: Vec<u8>, pos: usize, q: std::io::StdinLock<'static>}//'
#[allow(dead_code)] impl WordReaderC {
	fn new() -> Self {
		let r = unsafe {&*Box::into_raw(Box::new(stdin()))};
		Self { q: r.lock(), buf: v!([]), pos: 0 }
	}
	fn next_line(&mut self) -> bool {
		self.buf.clear(); self.pos = 0;
		self.q.read_until(b'\n', &mut self.buf).unwrap_or(0) > 0
	}
	fn is_ws(c: u8) -> bool {
		c == b' ' || c == b'\r' || c == b'\n' || c == b'\t'
	}
	fn byte(&mut self) -> Option<u8> {
		if self.pos == self.buf.len() { if !self.next_line() { return None; } }
		self.pos += 1; Some(self.buf[self.pos - 1])
	}
	fn vb(&mut self) -> Vec<u8> {
		let mut s = v!([8]);
		let mut f = false;
		loop {
			if let Some(c) = self.byte() {
				if !Self::is_ws(c) {
					s.push(c);
					f = true;
				} else if f { break; }
			} else { break; }
		}
		s
	}
	fn vvb(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rep!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
	}
	fn s(&mut self) -> String { String::from_utf8(self.vb()).expect("invalid utf8") }
	fn i(&mut self) ->    i32 { self.p() }
	fn l(&mut self) ->    i64 { self.p() }
	fn u(&mut self) ->  usize { self.p() }
	fn f(&mut self) ->    f64 { self.p() }
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn ii(&mut self, n: usize) -> impl Iterator<Item=i32> { self.ip(n).into_iter() }
	fn iu(&mut self, n: usize) -> impl Iterator<Item=usize> { self.ip(n).into_iter() }
	fn p<T: FromStr>(&mut self) -> T where T::Err: Debug {
		let w = self.vb(); str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()
	}
	fn vp<T: FromStr>(&mut self, n: usize) -> Vec<T> where T::Err: Debug {
		(0..n).map(|_|self.p()).collect()
	}
	fn ip<T: FromStr>(&mut self, n: usize) -> impl Iterator<Item=T> where T::Err: Debug {
		self.vp(n).into_iter()
	}
}
//------------------- End rusT }}}

// Segtree base {{{
#[allow(dead_code)]
mod lazy_segtree
{
	pub struct Node<V,L> { pub v: V, pub l: Option<L>, pub b: B, pub ch: CH<Self> }
	impl<V,L> Node<V,L> {
		pub fn new(v: V, b: B) -> Self { Node { v, l: None, b, ch: None } }
		pub fn is_leaf(&self) -> bool { self.ch.is_none() }
		pub fn is_up_to_date(&self) -> bool { self.l.is_none() }
		pub fn len(&self) -> usize { self.b.1 - self.b.0 + 1 }
	}
	pub type B = (usize, usize);
	pub type CH<T> = Option<(*mut T, *mut T)>;
	pub type N<T> = Node<<T as LSTNode>::V,<T as LSTNode>::L>;
	pub trait LSTNode {
		type V: Clone; type L: Clone; type R;
		fn accum_result(res: &mut Self::V, v: &Self::V) {
			*res = Self::combine_values(res, v);
		}
		fn update_parent_value(n: &mut N<Self>) {
			assert!(n.ch.is_some());
			let (lc,rc) = n.ch.unwrap();
			n.v = Self::combine_values(unsafe {&(*lc).v}, unsafe {&(*rc).v});
		}
		fn build_parent_value(n: &mut N<Self>) {
			Self::update_parent_value(n);
		}
		fn update_lazy(n: &mut N<Self>, l: &Self::L) {
			Self::augment_lazy(n, l);
		}
		fn update_children_lazy(n: &mut N<Self>) {
			assert!(n.ch.is_some());
			let (lc,rc) = n.ch.unwrap();
			if let Some(l) = n.l.take() {
				Self::update_lazy(unsafe {&mut*lc}, &l);
				Self::update_lazy(unsafe {&mut*rc}, &l);
			}
		}
		fn def_value() -> Self::V;
		fn extract_result(res: &Self::V) -> Self::R;
		fn combine_values(_: &Self::V, _: &Self::V) -> Self::V;
		fn update_value_from_lazy(_: &mut N<Self>);
		fn augment_lazy(_: &mut N<Self>, _: &Self::L);
	}
	struct UpInfo<L> { l: usize, r: usize, lz: L }
	struct QuInfo<V> { l: usize, r: usize, res: V }
	pub struct LST<T: LSTNode> { nodes: Vec<N<T>>, size: usize }
	impl<T: LSTNode> LST<T> {
		pub fn new() -> Self {
			Self { nodes: Vec::new(), size: 0 }
		}
		pub fn init_def(&mut self, s: usize) {
			self.init(vec![T::def_value(); s]);
		}
		pub fn init(&mut self, vals: Vec<T::V>) {
			self.size = vals.len(); self.nodes.clear();
			if self.size > 0 { self.init_nodes(vals); }
		}
		pub fn update(&mut self, l: usize, r: usize, lz: T::L) {
			assert!(l <= r && r < self.size);
			Self::internal_update(unsafe {&mut*self.root()}, &UpInfo {l,r,lz});
		}
		pub fn query_val(&mut self, l: usize, r: usize) -> T::V {
			assert!(l <= r && r < self.size);
			let mut x = QuInfo { l, r, res: T::def_value() };
			Self::internal_query(unsafe {&mut*self.root()}, &mut x);
			x.res
		}
		pub fn query(&mut self, l: usize, r: usize) -> T::R {
			T::extract_result(&self.query_val(l,r))
		}
		fn seg_push(n: &mut N<T>) {
			if !n.is_up_to_date() {
				T::update_value_from_lazy(n);
				if n.ch.is_some() {
					T::update_children_lazy(n);
				}
				n.l = None;
			}
		}
		fn seg_merge(n: &mut N<T>) {
			if let Some((lc,rc)) = n.ch {
				Self::seg_push(unsafe {&mut*lc});
				Self::seg_push(unsafe {&mut*rc});
				T::update_parent_value(n);
			}
		}
		fn internal_update(n: &mut N<T>, x: &UpInfo<T::L>) {
			if x.l <= n.b.0 && n.b.1 <= x.r {
				T::update_lazy(n, &x.lz);
				Self::seg_push(n);
			} else if x.l <= n.b.1 && n.b.0 <= x.r {
				Self::seg_push(n);
				let (c0,c1)  = n.ch.unwrap();
				Self::internal_update(unsafe {&mut*c0}, x);
				Self::internal_update(unsafe {&mut*c1}, x);
				Self::seg_merge(n);
			}
		}
		fn internal_query(n: &mut N<T>, x: &mut QuInfo<T::V>) {
			if x.l <= n.b.0 && n.b.1 <= x.r {
				Self::seg_push(n);
				T::accum_result(&mut x.res, &n.v);
			} else if x.l <= n.b.1 && n.b.0 <= x.r {
				let (lc,rc) = n.ch.unwrap();
				Self::seg_push(n);
				Self::internal_query(unsafe {&mut*lc}, x);
				Self::internal_query(unsafe {&mut*rc}, x);
				Self::seg_merge(n);
			}
		}
		fn init_nodes(&mut self, vals: Vec<T::V>) {
			let sz = 2 * self.size - 1;
			self.nodes.reserve(sz);
			let mut q = Vec::new();
			q.push((0, self.size - 1));
			while let Some((l,r)) = q.pop() {
				if l == r {
					let v = vals[l].clone();
					self.nodes.push(N::<T>::new(v, (l,r)));
				} else {
					let m = l + (r - l + 1) / 2;
					q.push((m, r));
					q.push((l, m - 1));
					let id = self.nodes.len();
					let v = T::def_value();
					let p = self.nodes.as_mut_ptr();
					let lc = unsafe { p.add(id + 1) };
					let rc = unsafe { p.add(id + 2 * (m - l)) };
					self.nodes.push(N::<T> { v, l: None, b: (l,r), ch: Some((lc,rc)) });
				}
			}
			assert_eq!(self.nodes.len(), sz);
			for n in self.nodes.iter_mut().rev() {
				if !n.is_leaf() {
					T::build_parent_value(n);
				}
			}
		}
		fn root(&mut self) -> *mut N<T> {
			assert!(!self.nodes.is_empty());
			self.nodes.as_mut_ptr()
		}
	}
}//}}}
// Segtree implementation {{{
#[allow(dead_code)]
mod i1 {
	use crate::lazy_segtree::*;
	pub type V = Vec<i64>;
	pub type L = usize;
	pub type R = i64;
	pub struct I;
	impl LSTNode for I {
		type V = V; type L = L; type R = R;
		fn def_value() -> Self::V {
			vec![0]
		}
		fn extract_result(res: &Self::V) -> Self::R {
			res[0]
		}
		fn combine_values(a: &Self::V, b: &Self::V) -> Self::V {
			let an = a.len();
			let bn = b.len();
			let sz = an.max(bn);
			let mut res = v!([sz]);
			for i in 0..sz {
				res.push(a[i.min(an-1)] + b[i.min(bn-1)]);
			}
			res
		}
		fn update_value_from_lazy(n: &mut N<Self>) {
			if let Some(l) = n.l {
				let sz = n.v.len();
				rep!{[l.min(sz-1)]
					n.v.remove(0);
				}
			}
		}
		fn augment_lazy(n: &mut N<Self>, l: &Self::L) {
			if n.v.len() > 1 {
				if n.l.is_none() {
					n.l.replace(0);
				}
				let x = n.l.as_mut().unwrap();
				*x += *l;
			}
		}
	}
	impl I {
		pub fn def_value() -> V { <Self as LSTNode>::def_value() }
		pub fn extract_result(res: &V) -> R { <Self as LSTNode>::extract_result(res) }
		pub fn combine_values(a: &V, b: &V) -> V { <Self as LSTNode>::combine_values(a,b) }
	}
}
pub type LST1 = lazy_segtree::LST<i1::I>;
//}}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();
	const A: usize = 1000000;

	let mut divs = v!([A+1] = 1);
	for i in 2..=A {
		if divs[i] == 1 {
			let mut j = 1;
			let mut jj = i;
			while jj <= A {
				let mut x = j;
				let mut c = 2;
				while x % i == 0 {
					x /= i;
					c += 1;
				}
				divs[jj] *= c;
				j += 1;
				jj += i;
			}
		}
	}
	l!(n,m = rin.u());
	let mut a = v!([n]);
	rep!{[n]
		let mut x = rin.u();
		let mut v = v!([]);
		loop {
			v.push(x as i64);
			let y = divs[x];
			if y == x {
				break;
			}
			x = y;
		}
		a.push(v);
	}
	let mut st = LST1::new();
	st.init(a);
	rep!{[m]
		let t = rin.u();
		l!(l,r = rin.u()-1);
		if t == 1 {
			st.update(l,r,1);
		} else {
			let res = st.query(l,r);
			writeln!(rout, "{}", res).ok();
		}
	}
}
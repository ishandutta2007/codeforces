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
	fn graph(&mut self, n: usize, m: usize) -> Vec<Vec<usize>> {
		let mut e = v!([n][]); rep!{[m] l!(a,b = self.u()-1); e[a].push(b); e[b].push(a); } e
	}
	fn graph_w<T: Copy+FromStr>(&mut self, n: usize, m: usize) -> Vec<Vec<(usize,T)>> where T::Err: Debug {
		let mut e = v!([n][]); rep!{[m] l!(a,b = self.u()-1); let c: T = self.p(); e[a].push((b,c)); e[b].push((a,c)); } e
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
		fn update_lazy(n: &mut N<Self>, l: &mut Self::L, fw: bool) {
			Self::augment_lazy(n, l, fw);
			Self::change_lazy_from_node(n, l, fw);
		}
		fn update_children_lazy(n: &mut N<Self>) {
			assert!(n.ch.is_some());
			let (lc,rc) = n.ch.unwrap();
			if let Some(mut l) = n.l.take() {
				Self::update_lazy(unsafe {&mut*lc}, &mut l, true);
				Self::update_lazy(unsafe {&mut*rc}, &mut l, true);
			}
		}
		fn def_value() -> Self::V;
		fn extract_result(res: &Self::V) -> Self::R;
		fn combine_values(_: &Self::V, _: &Self::V) -> Self::V;
		fn reverse_value(_: &Self::V) -> Self::V;
		fn update_value_from_lazy(_: &mut N<Self>);
		fn change_lazy_from_node(_: &N<Self>, _: &mut Self::L, _: bool);
		fn augment_lazy(_: &mut N<Self>, _: &Self::L, _: bool);
	}
	struct UpInfo<'a,L> { l: usize, r: usize, lz: &'a mut L }
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
		pub fn update(&mut self, l: usize, r: usize, lz: &mut T::L, fw: bool) {
			assert!(l <= r && r < self.size);
			Self::internal_update(unsafe {&mut*self.root()}, &mut UpInfo {l,r,lz}, fw);
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
		fn internal_update(n: &mut N<T>, x: &mut UpInfo<T::L>, fw: bool) {
			if x.l <= n.b.0 && n.b.1 <= x.r {
				T::update_lazy(n, &mut x.lz, fw);
				Self::seg_push(n);
			} else if x.l <= n.b.1 && n.b.0 <= x.r {
				Self::seg_push(n);
				let (lc,rc) = n.ch.unwrap();
				let (c0,c1) = if fw {(lc,rc)} else {(rc,lc)};
				Self::internal_update(unsafe {&mut*c0}, x, fw);
				Self::internal_update(unsafe {&mut*c1}, x, fw);
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
	pub type V = (i32,i32);
	pub type L = bool;
	pub type R = i32;
	pub struct I;
	impl LSTNode for I {
		type V = V; type L = L; type R = R;
		fn def_value() -> Self::V {
			(0,0)
		}
		fn extract_result(res: &Self::V) -> Self::R {
			res.1
		}
		fn combine_values(a: &Self::V, b: &Self::V) -> Self::V {
			(a.0+b.0, a.1+b.1)
		}
		fn reverse_value(_res: &Self::V) -> Self::V {
			panic!("bruh")
		}
		fn update_value_from_lazy(n: &mut N<Self>) {
			if let Some(true) = n.l {
				n.v = (n.v.1, n.v.0);
			}
		}
		fn augment_lazy(n: &mut N<Self>, l: &Self::L, _fw: bool) {
			if n.l.is_none() {
				n.l.replace(false);
			}
			let x = n.l.as_mut().unwrap();
			*x ^= *l;
		}
		fn change_lazy_from_node(_n: &N<Self>, _l: &mut Self::L, _fw: bool) {
			// nothing
		}
	}
	impl I {
		pub fn def_value() -> V { <Self as LSTNode>::def_value() }
		pub fn extract_result(res: &V) -> R { <Self as LSTNode>::extract_result(res) }
		pub fn combine_values(a: &V, b: &V) -> V { <Self as LSTNode>::combine_values(a,b) }
		pub fn reverse_value(res: &V) -> V { <Self as LSTNode>::reverse_value(res) }
	}
}
pub type LST1 = lazy_segtree::LST<i1::I>;
//}}}

fn dfs(u: usize, e: &[Vec<usize>], dfst: &mut [(usize,usize)], t: &mut usize) {
	dfst[u].0 = *t;
	*t += 1;
	for &v in e[u].iter() {
		dfs(v, e, dfst, t);
	}
	dfst[u].1 = *t - 1;
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let n = rin.u();
	let mut e = v!([n][]);
	for i in 1..n {
		e[rin.u()-1].push(i);
	}
	let a = rin.vi(n);
	let mut dfst = v!([n] = (0,0));
	dfs(0, &e, &mut dfst, &mut 0);
	let mut b = v!([n] = (0,0));
	for i in 0..n {
		b[dfst[i].0] = if a[i] == 0 {(1,0)} else {(0,1)};
	}
	let mut st = LST1::new();
	st.init(b);
	rep!{[rin.u()]
		let t = rin.vb()[0];
		let u = rin.u()-1;
		if t == b'g' {
			let res = st.query(dfst[u].0, dfst[u].1);
			writeln!(rout, "{}", res).ok();
		} else {
			st.update(dfst[u].0, dfst[u].1, &mut true, true);
		}
	}
}
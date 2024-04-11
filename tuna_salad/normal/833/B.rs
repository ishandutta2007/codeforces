//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};}
fn rio()->(Reader,BufWriter<Stdout>){(Reader::new(),BufWriter::new(stdout()))}
struct Reader{buf:Vec<u8>,pos:usize,q:StdinLock<'static>}/*'>}*/#[allow(dead_code)]impl Reader{
	fn new()->Self{let r=unsafe{&*Box::into_raw(Box::new(stdin()))};Self{q:r.lock(),buf:v!([]),pos:0}}
	fn next_line(&mut self)->bool{self.buf.clear();self.pos=0;self.q.read_until(b'\n',&mut self.buf).unwrap_or(0)>0}
	fn byte(&mut self)->Option<u8>{
		if self.pos==self.buf.len(){if!self.next_line(){return None;}}self.pos+=1;Some(self.buf[self.pos-1])}
	fn vb(&mut self)->Vec<u8>{let mut s=v!([10]);let mut f=false;while let Some(c)=self.byte(){
		if!c.is_ascii_whitespace(){s.push(c);f=true;}else if f{break;}}s}
	fn p<T:FromStr>(&mut self)->T where T::Err:Debug{let w=self.vb();str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()}
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

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
	pub type V = i32;
	pub type L = i32;
	pub type R = i32;
	pub struct I;
	impl LSTNode for I {
		type V = V; type L = L; type R = R;
		fn def_value() -> V {
			0
		}
		fn extract_result(res: &V) -> R {
			*res
		}
		fn combine_values(a: &V, b: &V) -> V {
			(*a).max(*b)
		}
		fn reverse_value(res: &V) -> V {
			*res
		}
		fn update_value_from_lazy(n: &mut N<Self>) {
			if let Some(l) = n.l {
				n.v += l;
			}
		}
		fn augment_lazy(n: &mut N<Self>, l: &L, _fw: bool) {
			let x = n.l.get_or_insert(0);
			*x += *l;
		}
		fn change_lazy_from_node(_n: &N<Self>, _l: &mut L, _fw: bool) {
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

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,k = rin.u());
	let a = rin.vu(n);
	let mut dp0 = v!([n+1] = 0);
	rp!{[k]
		let mut st = LST1::new();
		st.init(dp0);
		let mut p = v!([n+1] = 0);
		let mut dp1 = v!([n+1]);
		dp1.push(0);
		for i in 0..n {
			st.update(p[a[i]], i, &mut 1, true);
			p[a[i]] = i+1;
			dp1.push(st.query(0,i));
		}
		dp0 = dp1;
	}
	let ans = dp0[n];
	writeln!(rout, "{}", ans).unwrap();
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};}
fn rio()->(Reader,BufWriter<Stdout>){(Reader::new(),BufWriter::new(stdout()))}
struct Reader{buf:Vec<u8>,pos:usize,x:*mut Stdin,q:StdinLock<'static>}//'
#[allow(dead_code)]impl Reader{
	fn new()->Self{let x=Box::into_raw(Box::new(stdin()));let q=unsafe{&*x}.lock();Self{x,q,buf:v!([]),pos:0}}
	fn next_line(&mut self)->bool{self.buf.clear();self.pos=0;self.q.read_until(b'\n',&mut self.buf).unwrap_or(0)>0}
	fn byte(&mut self)->Option<u8>{
		if self.pos==self.buf.len(){if!self.next_line(){return None;}}self.pos+=1;Some(self.buf[self.pos-1])}
	fn vb(&mut self)->Vec<u8>{let mut s=v!([10]);let mut f=false;while let Some(c)=self.byte(){
		if!c.is_ascii_whitespace(){s.push(c);f=true;}else if f{break;}}s}
	fn p<T:FromStr>(&mut self)->T where T::Err:Debug{let w=self.vb();str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()}
	fn u(&mut self) ->  usize { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
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
	pub type V = (bool,bool);
	pub type L = ();
	pub type R = (bool,bool);
	pub struct I;
	impl LSTNode for I {
		type V = V; type L = L; type R = R;
		fn def_value() -> V {
			(false,false)
		}
		fn extract_result(res: &V) -> R {
			*res
		}
		fn combine_values(a: &V, b: &V) -> V {
			(a.0 ^ b.0, a.1 | b.1)
		}
		fn reverse_value(res: &V) -> V {
			*res
		}
		fn update_value_from_lazy(n: &mut N<Self>) {
			if let Some(_) = n.l {
				n.v.1 = true;
			}
		}
		fn augment_lazy(n: &mut N<Self>, _l: &L, _fw: bool) {
			n.l = Some(());
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

// HLD {{{
#[allow(dead_code)]
mod hld {
	// Various Info {{{
	use crate::lazy_segtree as lst;
	use crate::i1::{self,I};
	pub type ChainData = lst::LST<I>;
	pub type Value1 = i1::V;
	pub type Update1 = i1::L;
	pub type Result1 = i1::R;
	pub enum PathType { Node, Edge }
	struct PathInfo {
		id: usize,
		start: usize,
		end: usize,
	}
	#[derive(Clone)]
	struct ChainInfo {
		id: usize,
		pos: usize
	}
	#[derive(Clone)]
	struct Node {
		sz: usize,
		dep: usize,
		chain: Option<ChainInfo>,
		par: Option<usize>
	}
	impl Node {
		fn new() -> Self {
			Self {sz: 1, dep: 0, chain: None, par: None}
		}
	}
	struct Chain {
		nodes: Vec<usize>,
		vals: ChainData
	}
	impl Chain {
		fn head(&self) -> usize {
			self.nodes[0]
		}
		fn update(&mut self, l: usize, r: usize, u: &mut Update1, fw: bool) {
			self.vals.update(l,r,u,fw);
		}
		fn query(&mut self, l: usize, r: usize) -> Value1 {
			self.vals.query_val(l,r)
		}
	}
	//}}}
	// HLD (main) {{{
	pub struct HLD {
		n: usize,
		root: usize,
		nodes: Vec<Node>,
		chains: Vec<Chain>
	}
	impl HLD {
		// private methods {{{
		fn path_up_to(&self, mut u: usize, anc: usize, include_anc: bool) -> Vec<PathInfo> {
			let mut res = Vec::new();
			let anc_ch = self.nodes[anc].chain.as_ref().unwrap();
			let ChainInfo {id: anc_ch_id, pos: anc_ch_pos} = *anc_ch;
			while u != anc {
				let &ChainInfo {id, pos} = self.nodes[u].chain.as_ref().unwrap();
				if id == anc_ch_id {
					res.push(PathInfo {
						id,
						start: anc_ch_pos + 1,
						end: pos
					});
					u = anc;
				} else {
					res.push(PathInfo {id, start: 0, end: pos});
					u = self.nodes[self.chains[id].head()].par.unwrap();
				}
			}
			if include_anc {
				res.push(PathInfo {id: anc_ch_id, start: anc_ch_pos, end: anc_ch_pos});
			}
			res
		}
		fn path_between(&self, a: usize, b: usize, pt: PathType) -> (Vec<PathInfo>,Vec<PathInfo>) {
			let include_lca = if let PathType::Node = pt {true} else {false};
			let x = self.lca(a,b);
			let y = self.path_up_to(a, x, include_lca);
			let z = self.path_up_to(b, x, false);
			(y,z)
		}
		fn dfs(u: usize, par: usize, e: &[Vec<usize>], nodes: &mut [Node], n_chs: &mut Vec<Vec<usize>>, ch_ids: &mut [usize]) {
			let mut max_sz = 0;
			let mut max_sz_node = None;
			for &v in e[u].iter() {
				if v != par {
					nodes[v].par.replace(u);
					nodes[v].dep = nodes[u].dep + 1;
					Self::dfs(v, u, e, nodes, n_chs, ch_ids);
					nodes[u].sz += nodes[v].sz;
					if max!(max_sz, nodes[v].sz) {
						max_sz_node.replace(v);
					}
				}
			}
			if let Some(v) = max_sz_node {
				let ch_id = ch_ids[v];
				ch_ids[u] = ch_id;
				n_chs[ch_id].push(u);
			} else {
				ch_ids[u] = n_chs.len();
				n_chs.push(vec![u]);
			}
		}
		//}}}
		// public methods {{{
		pub fn new(e: &[Vec<usize>], data: &[Value1], root: usize) -> Self {
			let n = e.len();
			let mut nodes = vec![Node::new(); n];
			let mut node_chains = Vec::new();
			let mut chain_ids = vec![n; n];
			Self::dfs(root, n, e, &mut nodes, &mut node_chains, &mut chain_ids);
			assert!(chain_ids.iter().all(|x| *x < n), "disconnected tree");
			let mut chains = Vec::with_capacity(node_chains.len());
			for (ch_id,mut ch_nodes) in node_chains.into_iter().enumerate() {
				let mut vals = Vec::with_capacity(ch_nodes.len());
				ch_nodes.reverse();
				for (i,&u) in ch_nodes.iter().enumerate() {
					nodes[u].chain.replace(ChainInfo {id: ch_id, pos: i});
					vals.push(data[u].clone());
				}
				let mut st = ChainData::new();
				st.init(vals);
				chains.push(Chain {nodes: ch_nodes, vals: st});
			}
			Self {n, root, nodes, chains}
		}
		pub fn lca(&self, mut a: usize, mut b: usize) -> usize {
			while a != b {
				let &ChainInfo {id:a_id, pos:a_pos} = self.nodes[a].chain.as_ref().unwrap();
				let &ChainInfo {id:b_id, pos:b_pos} = self.nodes[b].chain.as_ref().unwrap();
				if a_id == b_id {
					if a_pos > b_pos {
						a = b;
					} else {
						b = a;
					}
				} else {
					let a_head = &self.nodes[self.chains[a_id].head()];
					let b_head = &self.nodes[self.chains[b_id].head()];
					if a_head.dep >= b_head.dep {
						a = a_head.par.unwrap();
					} else {
						b = b_head.par.unwrap();
					}
				}
			}
			a
		}
		pub fn query(&mut self, a: usize, b: usize, pt: PathType) -> Result1 {
			let (mut y,mut z) = self.path_between(a, b, pt);
			y.reverse();
			z.reverse();
			let yz = vec![y, z];
			let mut yz_res = Vec::with_capacity(2);
			for p in yz {
				let mut t = I::def_value();
				for PathInfo {id, start, end} in p {
					t = I::combine_values(&t, &self.chains[id].query(start,end));
				}
				yz_res.push(t);
			}
			let z_res = yz_res.pop().unwrap();
			let y_res = I::reverse_value(&yz_res.pop().unwrap());
			let res = I::combine_values(&y_res, &z_res);
			I::extract_result(&res)
		}
		pub fn update(&mut self, a: usize, b: usize, mut v: Update1, pt: PathType) {
			let (y,mut z) = self.path_between(a, b, pt);
			z.reverse();
			let yz = vec![(y,false), (z,true)];
			for (p,fw) in yz {
				for PathInfo {id, start, end} in p {
					self.chains[id].update(start, end, &mut v, fw);
				}
			}
		}
		//}}}
	}
	//}}}
}//}}}

// Simple DSU {{{
struct DSU {
	n: usize,
	par: Vec<usize>
}
#[allow(dead_code)]impl DSU {
	fn new(n: usize) -> Self { let mut d = Self {n:0, par:Vec::new()}; d.resize(n); d }
	fn resize(&mut self, n: usize) { self.n = n; self.par.resize(n, 0); self.reset(); }
	fn reset(&mut self) { for i in 0..self.n { self.par[i] = i; } }
	fn find(&mut self, a: usize) -> usize {
		if a != self.par[a] { self.par[a] = self.find(self.par[a]); } self.par[a] }
	fn union(&mut self, mut a: usize, mut b: usize) -> bool {
		a = self.find(a); b = self.find(b); if a != b { self.par[a] = b; true } else { false } }
}//}}}

// Coordinate compression {{{
fn compress<T: Ord>(a: &[T], start_from: usize) -> (usize, Vec<usize>) {
	let n = a.len();
	let mut t = Vec::with_capacity(n);
	for i in 0..n {
		t.push(i);
	}
	t.sort_by(|x,y| a[*x].cmp(&a[*y]));
	let mut b = vec![0; n];
	let mut v = start_from;
	for i in 0..n {
		if i > 0 && a[t[i-1]] < a[t[i]] {
			v += 1;
		}
		b[t[i]] = v;
	}
	(v, b)
}//}}}

fn dfs(u: usize, par: usize, e: &[Vec<(usize,bool)>], e1: &mut [Vec<usize>], d: &mut [(bool,bool)]) {
	for &(v,c) in &e[u] {
		if v != par {
			e1[u].push(v);
			d[v] = (c, false);
			dfs(v, u, e, e1, d);
		}
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,q = rin.u());
	l!(mut ans,in_forest = v!([q] = false));
	let mut el = v!([q]);
	let mut dsu = DSU::new(n);
	for i in 0..q {
		l!(a,b = rin.u()-1);
		let c = rin.i() == 1;
		if dsu.union(a,b) {
			ans[i] = true;
			in_forest[i] = true;
		}
		el.push( (a,b,c) );
	}
	let (m,g,gi,e) = {
		let mut g = v!([n]);
		for i in 0..n {
			g.push(dsu.find(i));
		}
		let (m,g) = compress(&g, 0);
		let m = m + 1;
		let mut gg = v!([m][]);
		for i in 0..n {
			gg[g[i]].push(i);
		}
		let mut gi = v!([n] = n);
		let mut e = v!([m]);
		for gg in gg {
			let (x,y) = compress(&gg, 0);
			for i in 0..gg.len() {
				gi[gg[i]] = y[i];
			}
			e.push(v!([x+1][]));
		}
		for i in 0..q {
			if in_forest[i] {
				let (a,b,c) = el[i];
				let x = g[a];
				let ga = gi[a];
				let gb = gi[b];
				e[x][ga].push( (gb,c) );
				e[x][gb].push( (ga,c) );
			}
		}
		(m,g,gi,e)
	};
	let mut h = v!([m]);
	for i in 0..m {
		let e = &e[i];
		let k = e.len();
		let mut e1 = v!([k][]);
		let mut d = v!([k] = (false,false));
		dfs(0, 0, &e, &mut e1, &mut d);
		h.push(hld::HLD::new(&e1, &d, 0));
	}
	use hld::PathType::Edge;
	for i in 0..q {
		if !in_forest[i] {
			let (a,b,c) = el[i];
			let x = g[a];
			let a = gi[a];
			let b = gi[b];
			let h = &mut h[x];
			let res = h.query(a, b, Edge);
			if res.0 != c && !res.1 {
				ans[i] = true;
				h.update(a, b, (), Edge);
			}
		}
	}
	for x in ans {
		if x {
			writeln!(rout, "YES").unwrap();
		} else {
			writeln!(rout, "NO").unwrap();
		}
	}
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
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
	fn l(&mut self) ->    i64 { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

#[allow(dead_code)]
mod graph {
	// Dijkstra {{{
	use std::collections::BinaryHeap;
	pub type DijkstraDist = i64;
	#[derive(Debug,Clone)]
	pub struct DijkstraNode {
		pub dist: DijkstraDist,
		pub from: Option<usize>
	}
	impl DijkstraNode {
		fn new() -> Self { Self {from: None, dist: DijkstraDist::max_value()/2} }
	}
	type DijkstraNodes = Box<[DijkstraNode]>;
	type DijkstraEdges = Box<[Vec<(usize, DijkstraDist)>]>;
	#[derive(Debug)]
	pub struct Dijkstra {
		nodes: DijkstraNodes,
		edges: DijkstraEdges,
	}
	impl Dijkstra {
		pub fn new(n: usize) -> Self {
			let nodes = vec![DijkstraNode::new(); n].into_boxed_slice();
			let edges = vec![Vec::new(); n].into_boxed_slice();
			Self {nodes, edges}
		}
		pub fn reset_nodes(&mut self) { for u in self.nodes.iter_mut() { *u = DijkstraNode::new(); } }
		pub fn get_nodes(&self) -> &DijkstraNodes {&self.nodes}
		pub fn get_edges(&self) -> &DijkstraEdges {&self.edges}
		pub fn add_edge_di(&mut self, a: usize, b: usize, c: DijkstraDist) {
			assert!(a.max(b) < self.nodes.len());
			if a != b { self.edges[a].push((b,c)); }
		}
		pub fn add_edge_un(&mut self, a: usize, b: usize, c: DijkstraDist) {
			self.add_edge_di(a,b,c);
			self.add_edge_di(b,a,c);
		}
		pub fn solve_from(&mut self, start: usize) {
			let n = self.nodes.len();
			assert!(start < n);
			let mut q = BinaryHeap::new();
			let mut vis = vec![false; n];
			self.nodes[start].dist = 0;
			self.nodes[start].from = Some(start);
			q.push((0, start));
			while let Some((d, u)) = q.pop() {
				if vis[u] { continue; }
				vis[u] = true;
				for &(v,w) in &self.edges[u] {
					if min!(self.nodes[v].dist, -d + w) {
						self.nodes[v].from = Some(u);
						q.push((-self.nodes[v].dist, v));
					}
				}
			}
		}
	}//}}}
}

type T = (usize,usize,usize,usize);

fn build(
	l: usize,
	r: usize,
	z: &mut Vec<T>,
	g: &mut graph::Dijkstra,
	b: bool,
) -> usize {
	assert!(l <= r);
	if l == r {
		l
	} else {
		let id = z.len();
		z.push( (l,r,0,0) );
		let m = (l+r) / 2;
		let lc = build(l, m, z, g, b);
		let rc = build(m+1, r, z, g, b);
		z[id].2 = lc;
		z[id].3 = rc;
		if b {
			g.add_edge_di(id, lc, 0);
			g.add_edge_di(id, rc, 0);
		} else {
			g.add_edge_di(lc, id, 0);
			g.add_edge_di(rc, id, 0);
		}
		id
	}
}

fn link(
	l: usize,
	r: usize,
	id: usize,
	v: usize,
	w: i64,
	z: &[T],
	g: &mut graph::Dijkstra,
	b: bool,
) {
	let (lb,rb,lc,rc) = z[id];
	if l <= lb && rb <= r {
		if b {
			g.add_edge_di(v, id, w);
		} else {
			g.add_edge_di(id, v, w);
		}
	} else if lb <= r && l <= rb {
		link(l, r, lc, v, w, z, g, b);
		link(l, r, rc, v, w, z, g, b);
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,q = rin.u());
	if n == 1 {
		writeln!(rout, "0").unwrap();
		return;
	}
	let s = rin.u()-1;
	let mut g = graph::Dijkstra::new(3*n-2);
	let mut z = v!([n]);
	for i in 0..n {
		z.push( (i,i,0,0) );
	}
	z.reserve(2*n-2);
	let gf = build(0, n-1, &mut z, &mut g, true);
	let gt = build(0, n-1, &mut z, &mut g, false);
	assert!(gf == n);
	assert!(gt == 2*n-1);
	rp!{[q]
		let t = rin.i();
		if t == 1 {
			l!(v,u = rin.u()-1);
			let w = rin.l();
			g.add_edge_di(v, u, w);
		} else {
			l!(v,l,r = rin.u()-1);
			let w = rin.l();
			if t == 2 {
				link(l, r, gf, v, w, &z, &mut g, true);
			} else {
				link(l, r, gt, v, w, &z, &mut g, false);
			}
		}
	}
	g.solve_from(s);
	let res = g.get_nodes();
	for i in 0..n {
		let ans = match (res[i].from, res[i].dist) {
			(None,_) => -1,
			(_,d) => d,
		};
		write!(rout, "{} ", ans).unwrap();
	}
}
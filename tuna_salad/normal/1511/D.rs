//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!v{
	($(:$t:ty)?=$e:expr)=>{$e$(as$t)?};([$d:expr]$(:$t:ty)?)=>{Vec::$(<$t>::)?with_capacity($d)};
	([]$(:$t:ty)?)=>{Vec::$(<$t>::)?new()};([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};}
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
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

// Directed Eulerian
#[allow(dead_code)]
mod directed_eulerian_graph {
	// Directed graph {{{
	#[derive(Debug,Clone)]
	pub struct Digraph2 {
		n: usize,
		edge_xor: Vec<usize>,
		edges: Box<[Vec<usize>]>
	}
	impl Digraph2 {
		pub fn new(n: usize) -> Self {
			let edge_xor = Vec::new();
			let edges = vec![Vec::new(); n].into_boxed_slice();
			Self { n, edge_xor, edges }
		}
		pub fn from_edge_list(n: usize, el: &[(usize,usize)]) -> Self {
			let m = el.len();
			let mut edge_xor = Vec::with_capacity(m);
			let mut deg = vec![0; n];
			for &(a,_) in el.iter() {
				deg[a] += 1;
			}
			let mut edges = Vec::with_capacity(n);
			for i in 0..n {
				edges.push(Vec::with_capacity(deg[i]));
			}
			for e in 0..m {
				let (a,b) = el[e];
				edge_xor.push(a^b);
				edges[a].push(e);
			}
			let edges = edges.into_boxed_slice();
			Self { n, edge_xor, edges }
		}
		pub fn adj(&self, a: usize, e: usize) -> usize { self.edge_xor[e] ^ a }
		pub fn add_edge(&mut self, a: usize, b: usize) {
			assert!(a.max(b) < self.n);
			let e = self.edge_xor.len();
			self.edge_xor.push(a^b);
			self.edges[a].push(e);
		}
		pub fn all_edges_connected(&self, start_from: Option<usize>) -> bool {
			let mut q = Vec::new();
			let mut vis = vec![false; self.n];
			if let Some(start) = start_from {
				q.push(start);
			} else {
				l!(mut in_deg,out_deg = v!([self.n] = 0));
				for i in 0..self.n {
					for &e in self.edges[i].iter() {
						out_deg[i] += 1;
						in_deg[self.edge_xor[e] ^ i] += 1;
					}
				}
				let mut found = false;
				for i in 0..self.n {
					if out_deg[i] > 0 && in_deg[i] == 0 {
						q.push(i);
						found = true;
						break;
					}
				}
				if !found {
					for i in 0..self.n {
						if out_deg[i] > 0 {
							q.push(i);
							break;
						}
					}
				}
			}
			while let Some(u) = q.pop() {
				if vis[u] { continue; }
				vis[u] = true;
				for &e in self.edges[u].iter() {
					q.push(self.adj(u,e));
				}
			}
			for i in 0..self.n {
				if self.edges[i].len() > 0 && !vis[i] {
					return false;
				}
			}
			true
		}
	}
	//}}}
	// Eulerian circuit/path finding {{{
	pub fn find_circuit(g: &Digraph2, start_from: Option<usize>) -> Option<Vec<usize>> {
		let mut deg = vec![0_i32; g.n];
		for u in 0..g.n {
			for &e in g.edges[u].iter() {
				let v = g.adj(u, e);
				deg[u] += 1;
				deg[v] -= 1;
			}
		}
		if deg.into_iter().any(|x| x != 0) {
			None
		} else {
			find_path(g, start_from, start_from)
		}
	}
	pub fn find_path(g: &Digraph2, start_from: Option<usize>, end_at: Option<usize>) -> Option<Vec<usize>> {
		if g.n == 0 || !g.all_edges_connected(start_from) {
			return None;
		}
		let mut deg = vec![0_i32; g.n];
		for u in 0..g.n {
			for &e in g.edges[u].iter() {
				let v = g.adj(u, e);
				deg[u] += 1;
				deg[v] -= 1;
			}
		}
		l!(mut out1,in1 = Vec::new());
		for i in 0..g.n {
			if deg[i].abs() > 1 {
				return None;
			} else if deg[i] > 0 {
				out1.push(i);
			} else if deg[i] < 0 {
				in1.push(i);
			}
		}
		if out1.len().max(in1.len()) > 1 {
			return None;
		}
		if start_from.is_some() && out1.len() > 0 && out1[0] != start_from.unwrap() {
			return None;
		}
		if end_at.is_some() && in1.len() > 0 && in1[0] != end_at.unwrap() {
			return None;
		}
		let start = {
			if let Some(s) = start_from {
				s
			} else if out1.len() > 0 {
				out1[0]
			} else {
				let mut s = 0;
				for i in 0..g.n {
					if g.edges[i].len() > 0 {
						s = i;
						break;
					}
				}
				s
			}
		};
		let end = {
			if let Some(e) = end_at {
				e
			} else if in1.len() > 0 {
				in1[0]
			} else {
				start
			}
		};
		if out1.len().max(in1.len()) == 0 && start != end {
			return None;
		}
		let m = g.edge_xor.len();
		if m == 0 {
			return Some(vec![start])
		}
		let mut e_vis = vec![false; m];
		let mut e_num: Vec<_> = (0..g.n).map(|i| g.edges[i].len()).collect();
		let mut line = vec![None; g.n];
		let mut q = Vec::new();
		let mut walk = move |q: &mut Vec<usize>, e_num: &mut Vec<usize>, seq: &mut Vec<usize>, mut u: usize| {
			loop {
				seq.push(u);
				if e_num[u] > 0 {
					q.push(u);
				}
				let mut v_next = None;
				while e_num[u] > 0 {
					e_num[u] -= 1;
					let e = g.edges[u][e_num[u]];
					if max!(e_vis[e], true) {
						let v = g.adj(u,e);
						v_next = Some(v);
						break;
					}
				}
				if let Some(v) = v_next {
					u = v;
				} else {
					break;
				}
			}
		};
		let mut seq0 = Vec::new();
		walk(&mut q, &mut e_num, &mut seq0, start);
		while let Some(s) = q.pop() {
			if e_num[s] > 0 {
				assert!(line[s].is_none());
				line[s].replace(Vec::new());
				walk(&mut q, &mut e_num, line[s].as_mut().unwrap(), s);
			}
		}
		let mut seq = Vec::with_capacity(m + 1);
		for s in seq0 {
			fill_seq(&mut line, &mut seq, s);
		}
		assert!(seq.len() == m+1);
		assert!(*seq.last().unwrap() == end);
		Some(seq)
	}
	fn fill_seq(line: &mut Vec<Option<Vec<usize>>>, seq: &mut Vec<usize>, u: usize) {
		if let Some(l) = line[u].take() {
			for x in l {
				fill_seq(line, seq, x);
			}
		} else {
			seq.push(u);
		}
	}//}}}
}

fn main() {
	let (mut rin,mut rout) = rio();
	use directed_eulerian_graph::*;

	l!(n,k = rin.u());
	let mut g = Digraph2::new(k);
	for i in 0..k {
		for j in 0..k {
			g.add_edge(i,j);
		}
	}
	let m = k * k;
	let res = find_circuit(&g, Some(0)).unwrap();
	assert!(res.len() == m+1);
	for i in 0..n {
		let c = res[i%m] as u8 + b'a';
		write!(rout, "{}", c as char).unwrap();
	}
}
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
	fn board(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rep!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
	}
	fn framed_board(&mut self, r: usize, c: usize, f: u8) -> Vec<Vec<u8>> {
		let mut res = v!([r+2]);
		res.push( v!([c+2] = f) );
		rep!{[r]
			let mut t = self.vb();
			assert!(t.len() == c);
			t.reserve(2);
			t.insert(0,f);
			t.push(f);
			res.push(t);
		}
		res.push( v!([c+2] = f) );
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
	let mut rin = reader();
	let mut rout = writer();

	use directed_eulerian_graph::*;
	let n = rin.u();
	let s = rin.board(n,Some(3));
	let mut id = HashMap::new();
	let mut ss = v!([]);
	let mut k = 0;
	for s in s.iter() {
		for p in vec![(s[0],s[1]), (s[1],s[2])] {
			if !id.contains_key(&p) {
				id.insert(p,k);
				ss.push(p);
				k += 1;
			}
		}
	}
	let m = id.len();
	let mut g = Digraph2::new(m);
	for s in s.iter() {
		let a = id[&(s[0],s[1])];
		let b = id[&(s[1],s[2])];
		g.add_edge(a,b);
	}
	if let Some(p) = find_path(&g, None, None) {
		writeln!(rout, "YES").ok();
		write!(rout, "{}", ss[p[0]].0 as char).ok();
		for x in p {
			write!(rout, "{}", ss[x].1 as char).ok();
		}
	} else {
		writeln!(rout, "NO").ok();
	}
}
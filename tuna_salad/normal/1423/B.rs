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
		Self { q: r.lock(), buf: Vec::new(), pos: 0 }
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
		let mut s = Vec::with_capacity(8);
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

// Bipartite Matching
#[allow(dead_code)]
mod flow {
	// Hopcroft-Karp {{{
	use std::collections::*;
	struct EdgeInfo {
		a: usize,
		b: usize
	}
	struct PushInfo {
		rit: i32,
		vis: Vec<i32>,
		dep: Vec<i32>,
		q: VecDeque<usize>,
		s: Vec<usize>
	}
	impl PushInfo {
		fn new(g: &Bipartite1) -> Self {
			Self {rit: 0, vis: vec![0; g.n], dep: vec![0; g.n], q: VecDeque::new(), s: Vec::new()}
		}
	}
	pub struct Bipartite1 {
		n: usize,
		m: usize,
		l_sz: usize,
		r_sz: usize,
		e_adj: Vec<Vec<usize>>,
		e_info: Vec<EdgeInfo>,
		match_e: Vec<Option<usize>>
	}
	impl Bipartite1 {
		pub fn new(l_sz: usize, r_sz: usize, m_reserve: usize) -> Self {
			let n = l_sz + r_sz;
			let m = 0;
			let e_adj = vec![Vec::new(); n];
			let e_info = Vec::with_capacity(m_reserve);
			let match_e = vec![None; n];
			Self {n, m, l_sz, r_sz, e_adj, e_info, match_e}
		}
		pub fn adj(&self, a: usize, e: usize) -> usize {
			let x = &self.e_info[e];
			x.a ^ x.b ^ a
		}
		pub fn add_edge(&mut self, a: usize, b: usize) {
			let b = b + self.l_sz;
			self.e_adj[a].push(self.m);
			self.e_adj[b].push(self.m);
			self.e_info.push(EdgeInfo {a, b});
			self.m += 1;
		}
		pub fn matching(&mut self) -> usize {
			let mut res = 0;
			let mut p = PushInfo::new(self);
			loop {
				let s = self.bfs_push(&mut p);
				if s == 0 { break; }
				res += s;
			}
			res
		}
		pub fn get_pairs(&self) -> Vec<(usize,usize)> {
			let mut res = Vec::new();
			for u in 0..self.l_sz {
				if let Some(e) = self.match_e[u] {
					res.push((u, self.e_info[e].b - self.l_sz));
				}
			}
			res
		}
		fn dfs(&mut self, p: &mut PushInfo, x: usize) -> bool {
			if self.match_e[x].is_none() && x < self.l_sz {
				return true;
			}
			p.vis[x] = p.rit;
			if x >= self.l_sz { // x in V
				for i in 0..self.e_adj[x].len() {
					let e = self.e_adj[x][i];
					if let Some(ee) = self.match_e[x] {
						if ee == e { continue; }
					}
					let y = self.e_info[e].a;
					if p.vis[y] == p.rit-1 && p.dep[y] == p.dep[x]-1 && self.dfs(p, y) {
						self.match_e[x].replace(e);
						self.match_e[y].replace(e);
						return true;
					}
				}
			} else {
				let e = self.match_e[x].unwrap();
				let y = self.e_info[e].b;
				if p.vis[y] == p.rit-1 && p.dep[y] == p.dep[x]-1 && self.dfs(p, y) {
					return true;
				}
			}
			false
		}
		fn bfs_push(&mut self, p: &mut PushInfo) -> usize {
			p.rit += 1;
			for u in 0..self.l_sz {
				if self.match_e[u].is_none() {
					p.dep[u] = 0;
					p.vis[u] = p.rit;
					p.q.push_back(u);
				}
			}
			while let Some(x) = p.q.pop_front() {
				if self.match_e[x].is_none() && x >= self.l_sz {
					p.q.push_front(x);
					while let Some(x) = p.q.pop_front() {
						if self.match_e[x].is_none() {
							p.s.push(x);
						}
					}
					break;
				}
				if x < self.l_sz {
					for &e in self.e_adj[x].iter() {
						if let Some(ee) = self.match_e[x] {
							if ee == e { continue; }
						}
						let y = self.adj(x, e);
						if max!(p.vis[y], p.rit) {
							p.dep[y] = p.dep[x] + 1;
							p.q.push_back(y);
						}
					}
				} else {
					let e = self.match_e[x].unwrap();
					let y = self.adj(x, e);
					if max!(p.vis[y], p.rit) {
						p.dep[y] = p.dep[x] + 1;
						p.q.push_back(y);
					}
				}
			}
			p.rit += 1;
			let mut res = 0;
			for x in p.s.split_off(0) {
				if self.dfs(p, x) {
					res += 1;
				}
			}
			res
		}
	}//}}}
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,m = rin.u());
	let mut el = v!([m]);
	rep!{[m]
		l!(a,b = rin.u()-1);
		let c = rin.i();
		el.push( (c,a,b) );
	}
	el.sort();
	let mut sol = m+1;
	let mut lo = n;
	let mut hi = m;
	while lo <= hi {
		let mid = (lo + hi)/2;
		let mut g = flow::Bipartite1::new(n, n, mid);
		for i in 0..mid {
			let (_,a,b) = el[i];
			g.add_edge(a,b);
		}
		if g.matching() == n {
			sol = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	if sol > m {
		writeln!(rout, "-1").ok();
	} else {
		writeln!(rout, "{}", el[sol-1].0).ok();
	}
}
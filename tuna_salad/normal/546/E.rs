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

// Max flow
#[allow(dead_code)]
mod flow {
	// Dinic's blocking flow {{{
	pub type CapType = i32;
	const CAP_INF: CapType = 1000000000;
	pub use self::EdgeDir::*;
	#[derive(Debug,Clone,Copy)]
	pub enum EdgeDir {
		Forw(usize),
		Back(usize)
	}
	impl EdgeDir {
		pub fn inner(self) -> usize {
			match self {
				Forw(x) => x,
				Back(x) => x
			}
		}
		pub fn rev(self) -> Self {
			match self {
				Forw(x) => Back(x),
				Back(x) => Forw(x)
			}
		}
	}
	pub struct EdgeInfo {
		pub flow: CapType,
		pub cap: CapType,
		pub xor: usize,
		pub a: usize,
		pub b: usize
	}
	pub struct FlowGraph1 {
		pub n: usize,
		pub m: usize,
		pub e_adj: Vec<Vec<EdgeDir>>,
		pub e_info: Vec<EdgeInfo>
	}
	impl FlowGraph1 {
		pub fn new(n: usize, m_reserve: usize) -> Self {
			let e_adj = vec![Vec::new(); n];
			let e_info = Vec::with_capacity(m_reserve);
			Self {n, m:0, e_adj, e_info}
		}
		pub fn adj(&self, a: usize, e: usize) -> usize { self.e_info[e].xor ^ a }
		pub fn add_edge_di(&mut self, a: usize, b: usize, c: CapType) {
			assert!(a.max(b) < self.n);
			self.e_adj[a].push(Forw(self.m));
			self.e_adj[b].push(Back(self.m));
			self.e_info.push(EdgeInfo {flow: 0, cap: c, xor: a ^ b, a, b});
			self.m += 1;
		}
		pub fn add_edge_un(&mut self, a: usize, b: usize, c: CapType) {
			self.add_edge_di(a,b,c);
			self.e_info[self.m-1].flow = c;
		}
		fn blocking_flow(&mut self, s: usize, t: usize) -> CapType {
			assert!(s != t && s.max(t) < self.n);
			let mut prev = vec![None; self.n];
			prev[s].replace(Forw(self.m));
			let mut q = std::collections::VecDeque::new();
			q.push_back(s);
			while let Some(u) = q.pop_front() {
				for &e in self.e_adj[u].iter() {
					match e {
						Forw(ee) => {
							let v = self.adj(u, ee);
							if prev[v].is_none() && self.e_info[ee].cap > 0 {
								prev[v].replace(e.rev());
								q.push_back(v);
							}
						},
						Back(ee) => {
							let v = self.adj(u, ee);
							if prev[v].is_none() && self.e_info[ee].flow > 0 {
								prev[v].replace(e.rev());
								q.push_back(v);
							}
						}
					}
				}
			}
			if prev[t].is_none() { return 0; }
			let mut flows = 0;
			for &et in self.e_adj[t].iter() {
				if prev[self.adj(t, et.inner())].is_none() { continue; }
				let mut u = t;
				let mut e = et;
				let mut res = CAP_INF;
				loop {
					let ee = e.inner();
					let x = &self.e_info[ee];
					let c = match e {
						Forw(_) => x.flow,
						Back(_) => x.cap
					};
					min!(res, c);
					u = self.adj(u, ee);
					if u == s || res == 0 { break; }
					e = prev[u].unwrap();
				}
				if res == 0 {
					continue;
				}
				flows += res;
				u = t;
				e = et;
				loop {
					let (df,dc) = match e {
						Forw(_) => (-res, res),
						Back(_) => (res, -res)
					};
					let ee = e.inner();
					{
						let x = &mut self.e_info[ee];
						x.flow += df;
						x.cap += dc;
					}
					u = self.adj(u, ee);
					if u == s { break; }
					e = prev[u].unwrap();
				}
			}
			return flows;
		}
		pub fn max_flow(&mut self, s: usize, t: usize) -> CapType {
			let mut res = 0;
			loop {
				let f = self.blocking_flow(s, t);
				if f > 0 {
					res += f;
				} else {
					break;
				}
			}
			res
		}
		pub fn find_cut(&mut self, s: usize, t: usize) -> (CapType,Vec<(usize,usize)>) {
			let flows = self.max_flow(s, t);
			let mut q_put = vec![false; self.n];
			let mut q = Vec::new();
			q.push(s);
			q_put[s] = true;
			while let Some(u) = q.pop() {
				for &e in self.e_adj[u].iter() {
					let ee = e.inner();
					let v = self.adj(u, ee);
					let x = &self.e_info[ee];
					let can_go = match e {
						Forw(_) => x.cap > 0,
						Back(_) => x.flow > 0
					};
					if can_go && max!(q_put[v], true) {
						q.push(v);
					}
				}
			}
			let mut cut = Vec::new();
			for u in 0..self.n {
				if q_put[u] {
					for &e in self.e_adj[u].iter() {
						let ee = e.inner();
						if !q_put[self.adj(u,ee)] {
							let x = &self.e_info[ee];
							cut.push((x.a, x.b));
						}
					}
				}
			}
			(flows, cut)
		}
	}//}}}
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,m = rin.u());
	l!(a,b = rin.vi(n));
	let s = a.iter().sum::<i32>();
	if s != b.iter().sum::<i32>() {
		writeln!(rout, "NO").ok();
		return;
	}
	let mut g = flow::FlowGraph1::new(2*n+2, 3*n+2*m);
	let mut e = v!([m]);
	rep!{[m]
		l!(x,y = rin.u()-1);
		e.push( (x,y) );
		g.add_edge_di(x, y+n, 100);
		g.add_edge_di(y, x+n, 100);
	}
	let src = 2*n;
	let sink = src + 1;
	for i in 0..n {
		g.add_edge_di(src, i, a[i]);
		g.add_edge_di(i, i+n, a[i]);
		g.add_edge_di(i+n, sink, b[i]);
	}
	let f = g.max_flow(src, sink);
	if f != s {
		writeln!(rout, "NO").ok();
	} else {
		writeln!(rout, "YES").ok();
		let mut sol = v!([n][n] = 0);
		for i in 0..n {
			sol[i][i] = a[i];
		}
		let mut k = 0;
		for (x,y) in e {
			for (x,y) in vec![(x,y), (y,x)] {
				let f = g.e_info[k].flow;
				sol[x][x] -= f;
				sol[x][y] += f;
				k += 1;
			}
		}
		for i in 0..n {
			for j in 0..n {
				write!(rout, "{} ", sol[i][j]).ok();
			}
			writeln!(rout, "").ok();
		}
	}
}
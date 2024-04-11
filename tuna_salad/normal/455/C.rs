//spnauti-rusT {{{
use std::io::*; use std::str::{self,*}; use std::fmt::Debug;
#[allow(unused_imports)] use std::cmp::Ordering::{self,*};
#[allow(unused_imports)] use std::ops::{self,*};
#[allow(unused_imports)] use std::iter::{self,*};
#[allow(unused_imports)] use std::collections::*;
#[allow(unused_imports)] use std::cell::*;
#[allow(unused_macros)] macro_rules! m {
	($c:tt,$x:expr,$y:expr) => {{
		let b=$y; let a=&mut$x; if b$c*a {*a=b; true} else {false}
	}};
}
#[allow(unused_macros)] macro_rules! l {
	($($v:ident),+ =$e:expr) => {$(let$v=$e;)+};
	($($v:ident),+:$t:ty=$e:expr) => {$(let$v:$t=$e;)+};
	(mut $($v:ident),+ =$e:expr) => {$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr) => {$(let mut$v:$t=$e;)+};
}
#[allow(unused_macros)] macro_rules! vec_dim {
	([$d:expr]$($s:tt)+) => {vec![vec_dim!($($s)+);$d]}; (=$e:expr) => {$e};
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

fn bfs(start: usize, e: &[Vec<usize>], vis: &mut [u8], q: &mut VecDeque<(usize,i32)>, i: u8) -> (usize,i32) {
	q.push_back( (start,0) );
	vis[start] = i;
	let mut far = 0;
	let mut last = start;
	while let Some( (u,d) ) = q.pop_front() {
		last = u;
		far = d;
		for &v in e[u].iter() {
			if m!(>, vis[v], i) {
				q.push_back( (v,d+1) );
			}
		}
	}
	(last, far)
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,m,q = rin.u());
	let mut e = vec_dim!([n] = Vec::new());
	let mut dsu = DSU::new(n);
	rep!{[m]
		l!(a,b = rin.u()-1);
		e[a].push(b);
		e[b].push(a);
		dsu.union(a,b);
	}
	let mut vis = vec_dim!([n] = 0);
	let mut qq = VecDeque::new();
	let mut len = vec_dim!([n] = -1);
	for u in 0..n {
		if vis[u] == 0 {
			let a = bfs(u, &e, &mut vis, &mut qq, 1).0;
			let d = bfs(a, &e, &mut vis, &mut qq, 2).1;
			len[dsu.find(u)] = d;
		}
	}
	rep!{[q]
		let t = rin.u();
		let x = dsu.find(rin.u()-1);
		if t == 1 {
			let res = len[dsu.find(x)];
			writeln!(rout, "{}", res).ok();
		} else {
			let y = dsu.find(rin.u()-1);
			if x != y {
				let l = len[x].max(len[y]).max((len[x] + 1) / 2 + (len[y] + 1) / 2 + 1);
				dsu.union(x,y);
				len[dsu.find(x)] = l;
			}
		}
	}
}
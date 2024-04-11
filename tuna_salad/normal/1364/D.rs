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

fn dfs(u: usize, e: &[Vec<usize>], vis: &mut [bool], vert: &mut Vec<usize>) {
	vis[u] = true;
	vert.push(u);
	for &v in e[u].iter() {
		if !vis[v] {
			dfs(v, e, vis, vert);
		}
	}
}

fn dfs_cycle(u: usize, par: usize, e: &[Vec<usize>], vis: &mut [u8], cycle: &mut Vec<usize>) -> u8 {
	vis[u] = 1;
	for &v in e[u].iter() {
		if v != par {
			if vis[v] == 1 {
				cycle.push(v);
				cycle.push(u);
				return 1;
			}
			if vis[v] == 0 {
				let res = dfs_cycle(v, u, e, vis, cycle);
				if res == 1 {
					if cycle[0] == u {
						return 2;
					}
					cycle.push(u);
					return 1;
				}
				if res == 2 {
					return 2;
				}
			}
		}
	}
	vis[u] = 2;
	0
}

fn dfs_is(u: usize, par: usize, e: &[Vec<usize>], dp: &mut [(usize,usize)]) {
	let mut a = 0;
	let mut b = 1;
	for &v in e[u].iter() {
		if v != par {
			dfs_is(v, u, e, dp);
			let (aa,bb) = dp[v];
			a += aa.max(bb);
			b += aa;
		}
	}
	dp[u] = (a,b);
}

fn dfs_is2(u: usize, par: usize, e: &[Vec<usize>], dp: &[(usize,usize)], w: usize, is: &mut Vec<usize>) {
	if w == 1 {
		is.push(u);
	}
	for &v in e[u].iter() {
		if v != par {
			let ww = if w == 1 || dp[v].0 >= dp[v].1 {
				0
			} else {
				1
			};
			dfs_is2(v, u, e, dp, ww, is);
		}
	}
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,m,k = rin.u());
	let e = rin.graph(n,m);
	let mut vert = v!([n]);
	let mut vis = v!([n] = false);
	dfs(0, &e, &mut vis, &mut vert);
	vert.truncate(k);
	let mut used = v!([n] = false);
	for &v in vert.iter() {
		used[v] = true;
	}
	let mut ee = v!([n][]);
	let mut mm = 0;
	for u in 0..n {
		if used[u] {
			for &v in e[u].iter() {
				if u < v && used[v] {
					ee[u].push(v);
					ee[v].push(u);
					mm += 1;
				}
			}
		}
	}
	if mm >= k {
		let mut cycle = v!([k]);
		let mut vis = v!([n] = 0);
		dfs_cycle(vert[0], n, &ee, &mut vis, &mut cycle);
		writeln!(rout, "2").ok();
		writeln!(rout, "{}", cycle.len()).ok();
		for u in cycle {
			write!(rout, "{} ", u+1).ok();
		}
	} else {
		let mut dp = v!([n] = (0,0));
		dfs_is(vert[0], n, &ee, &mut dp);
		let mut is = v!([]);
		let w = if dp[vert[0]].0 >= dp[vert[0]].1 {0} else {1};
		dfs_is2(vert[0], n, &ee, &dp, w, &mut is);
		is.truncate((k+1) / 2);
		writeln!(rout, "1").ok();
		for u in is {
			write!(rout, "{} ", u+1).ok();
		}
	}
}
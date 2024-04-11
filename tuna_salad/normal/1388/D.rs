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

fn dfs(u: usize, e: &[Vec<usize>], e2: &mut [Vec<usize>], vis: &mut [bool], a: &mut [i64]) {
	vis[u] = true;
	for &v in e[u].iter() {
		if !vis[v] {
			dfs(v, e, e2, vis, a);
		}
		if a[v] > 0 {
			e2[v].push(u);
			a[u] += a[v];
		} else {
			e2[u].push(v);
		}
	}
}

fn dfs2(u: usize, e2: &[Vec<usize>], vis: &mut [bool], ord: &mut Vec<usize>) {
	vis[u] = true;
	for &v in e2[u].iter() {
		if !vis[v] {
			dfs2(v, e2, vis, ord);
		}
	}
	ord.push(u);
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let n = rin.u();
	let mut a = rin.vl(n);
	let mut e = vec![Vec::new(); n];
	let mut e2 = vec![Vec::new(); n];
	for i in 0..n {
		let p = rin.i();
		if p > 0 {
			let p = p as usize - 1;
			e[p].push(i);
		}
	}
	let mut vis = vec![false; n];
	for u in 0..n {
		if !vis[u] {
			dfs(u, &e, &mut e2, &mut vis, &mut a);
		}
	}
	let mut vis = vec![false; n];
	let mut ord = Vec::with_capacity(n);
	for u in 0..n {
		if !vis[u] {
			dfs2(u, &e2, &mut vis, &mut ord);
		}
	}
	let sol: i64 = a.into_iter().sum();
	writeln!(rout, "{}", sol).ok();
	ord.reverse();
	for o in ord {
		write!(rout, "{} ", o+1).ok();
	}
}
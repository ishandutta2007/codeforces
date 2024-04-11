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

fn dfs(u: usize, dep: usize, e: &[Vec<usize>], s: &[i32], nlist: &[Vec<(usize,usize)>], ans: &mut [i32], dxor: &mut [i32], dopen: &mut [Vec<usize>], sol: &mut [bool]) {
	for id in dopen[dep].drain(..) {
		ans[id] = dxor[dep];
	}
	for &(h,id) in nlist[u].iter() {
		if h <= dep {
			sol[id] = true;
		} else {
			ans[id] = -1;
			dopen[h].push( id );
		}
	}
	dxor[dep] ^= s[u];
	for &v in e[u].iter() {
		dfs(v, dep+1, e, s, nlist, ans, dxor, dopen, sol);
	}
	for &(h,id) in nlist[u].iter() {
		if h > dep {
			if ans[id] == -1 { // subtree not deep enough
				sol[id] = true;
			} else {
				let b = ans[id] ^ dxor[h];
				sol[id] = b.count_ones() < 2;
			}
		}
	}
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,q = rin.u());
	let mut e = v!([n][]);
	for i in 1..n {
		e[rin.u()-1].push(i);
	}
	let mut s = v!([n]);
	for c in rin.vb() {
		s.push(1 << (c - b'a') as i32);
	}
	let mut sol = v!([q] = false);
	let mut ans = v!([q] = -1_i32);
	let mut dxor = v!([n] = 0_i32);
	l!(mut nlist,dopen = v!([n][]));
	for i in 0..q {
		l!(v,h = rin.u()-1);
		nlist[v].push( (h,i) );
	}
	dfs(0, 0, &e, &s, &nlist, &mut ans, &mut dxor, &mut dopen, &mut sol);
	for s in sol {
		if s {
			writeln!(rout, "Yes").ok();
		} else {
			writeln!(rout, "No").ok();
		}
	}
}
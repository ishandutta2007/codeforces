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

fn dp(dp0: &[Vec<f64>], n: usize, t1: usize, t2: usize) -> Option<f64> {
	if t1 < t2 {
		None
	} else {
		let a = dp0[n][t1-t2];
		if a > 1e-50 {
			Some(a)
		} else {
			None
		}
	}
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,t = rin.u());
	let mut p = vec![0.0; n];
	let mut ti = vec![0; n];
	for i in 0..n {
		p[i] = rin.u() as f64 / 100.0;
		ti[i] = rin.u();
	}
	let mut dp0 = vec![vec![0.0; t+1]; n+1];
	dp0[0][0] = 1.0;
	for i in 1..=n {
		let pn = p[i-1];
		let tn = ti[i-1];
		let tn_1 = (1.0 - pn).powi((tn - 1) as i32);
		let pn_tn = pn * tn_1;
		let mut f = 0.0;
		for j in 1..=t {
			f *= 1.0 - pn;
			if let Some(v) = dp(&dp0, i-1, j, tn) {
				f -= pn_tn * v;
			}
			if let Some(v) = dp(&dp0, i-1, j, 1) {
				f += pn * v;
			}
			let res = f + if let Some(v) = dp(&dp0, i-1, j, tn) {
				// writeln!(rout, "n {} t {} : dp {}  tn {}  p{}", i, j, v, tn, tn_1).ok();
				tn_1 * v
			} else {
				0.0
			};
			dp0[i][j] = res;
		}
	}
	let mut sol = 0.0;
	for i in 1..=n {
		for j in 1..=t {
			if let Some(v) = dp(&dp0, i, j, 0) {
				sol += v;
			}
		}
	}
	writeln!(rout, "{:.9}", sol).ok();
}
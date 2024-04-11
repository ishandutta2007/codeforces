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

fn main() {
	let mut rin = reader();
	let mut rout = writer();
	const INF: i32 = 10000000;

	let n = rin.u();
	let mut a = Vec::with_capacity(n);
	rep!{[n]
		a.push(rin.vi(n));
	}
	let mut dp = vec_dim!([n][2][n][n] = -INF);
	dp[0][0][0][0] = a[0][0];
	for i in 0..n {
		let (a,dp0,dp1) = {
			let a = &a[i];
			let (dp_prev_1, dp_now_1) = dp.split_at_mut(i);
			let (dp_now, _) = dp_now_1.split_first_mut().unwrap();
			let (dp0,dp_now) = dp_now.split_first_mut().unwrap();
			let (dp1,_) = dp_now.split_first_mut().unwrap();
			if let Some( (dp_prev,_) ) = dp_prev_1.split_last() {
				for j in 0..n {
					for k in j..n {
						let mut z = dp_prev[0][j][k].max(dp_prev[1][j][k]) + a[j];
						if j != k {
							z += a[k];
						}
						dp0[j][k] = z;
					}
				}
			}
			(a,dp0,dp1)
		};
		for j in 0..n {
			dp1[j][j] = dp0[j][j];
			for k in j+1..n {
				let mut z = dp0[j+1][k];
				let x = if j+1 < k {a[j+1]} else {0};
				m!(>, z, dp0[j][k] + x);
				dp0[j+1][k] = z;
				dp1[j][k] = dp0[j][k];
			}
		}
		for j in 0..n {
			if j+1 < n {
				m!(>, dp1[j+1][j+1], dp1[j][j] + a[j+1]);
			}
			for k in j..n-1 {
				m!(>, dp1[j][k+1], dp1[j][k] + a[k+1]);
			}
		}
	}
	let sol = dp[n-1][1][n-1][n-1];
	writeln!(rout, "{}", sol).ok();
}
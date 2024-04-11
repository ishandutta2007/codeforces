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

// Simple Segtree {{{
mod simple_full_segtree {
	pub type V = i32;
	pub type R = usize;
	#[derive(Clone)]
	pub struct Val {
		g: i32,
		min: i32,
		n_min: usize
	}
	fn gcd(a: i32, b: i32) -> i32 {
		if b == 0 {a} else {gcd(b, a%b)}
	}
	impl Val {
		pub fn default() -> Self {
			Self {g: 0, min: 1000000001, n_min: 0}
		}
		pub fn new(v: V) -> Self {
			Self {g: v, min: v, n_min: 1}
		}
		pub fn combine(a: &Self, b: &Self) -> Self {
			let g = gcd(a.g, b.g);
			let min = a.min.min(b.min);
			let n_min = if min == a.min {a.n_min} else {0} + if min == b.min {b.n_min} else {0};
			Self {g, min, n_min}
		}
		pub fn result(&self) -> R {
			if self.min == self.g {
				self.n_min
			} else {
				0
			}
		}
	}
	pub struct Tree {
		n: usize,
		base: usize,
		values: Box<[Val]>
	}
	#[allow(dead_code)]
	impl Tree {
		pub fn new(init: &[V]) -> Self {
			let n = init.len();
			let mut base = 1;
			while base < n {
				base <<= 1;
			}
			let mut values = vec![Val::default(); base*2];
			for i in 0..n {
				values[base + i] = Val::new(init[i]);
			}
			for i in (1..base).rev() {
				values[i] = Val::combine(&values[i+i], &values[i+i+1]);
			}
			let values = values.into_boxed_slice();
			Self {n, base, values}
		}
		fn query_sub(&self, ql: usize, qr: usize, l: usize, r: usize, id: usize, val: &mut Val) {
			if r < ql || qr < l { return; }
			if ql <= l && r <= qr {
				*val = Val::combine(val, &self.values[id]);
			} else if ql <= r && l <= qr {
				let m = (l+r) >> 1;
				self.query_sub(ql, qr, l, m, id+id, val);
				self.query_sub(ql, qr, m+1, r, id+id+1, val);
			}
		}
		pub fn query(&self, ql: usize, qr: usize) -> Val {
			assert!(ql <= qr && qr < self.n);
			let mut res = Val::default();
			self.query_sub(ql, qr, 0, self.base-1, 1, &mut res);
			res
		}
	}
}//}}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let n = rin.u();
	let a = rin.vi(n);
	let st = simple_full_segtree::Tree::new(&a);
	rep!{[rin.u()]
		l!(l,r = rin.u()-1);
		let res = r-l+1 - st.query(l,r).result();
		writeln!(rout, "{}", res).ok();
	}
}
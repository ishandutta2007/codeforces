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

// Field (mod prime) {{{
const P5: i32 = 1_000_000_007;
const P6: i64 = P5 as i64;
#[derive(Debug,Clone,Copy,PartialEq,Eq,PartialOrd,Ord,Default)] struct Field(i32);
#[allow(dead_code)] impl Field {
	fn new<T: Into<i64>>(a: T) -> Self { Self(Self::cv(a)) }
	fn new_unchecked(a: i32) -> Self { Self(a) }
	fn hi(mut a: i32) -> i32 { if a >= P5 { a -= P5; } a }
	fn lo(mut a: i32) -> i32 { if a < 0 { a += P5; } a }
	fn cv<T: Into<i64>>(a: T) -> i32 { Self::lo((a.into() % P6) as i32) }
	fn inv(self) -> Self { self.pow(P5-2) }
	fn pow<T: Into<i64>>(self, b: T) -> Self {
		let b = b.into(); if b == 0 { Self(1) } else {
			let mut res = self.pow(b/2); res *= res; if b % 2 == 1 {res *= self;} res
		}
	}
}
impl Add for Field { type Output = Self; fn add(self, a: Self) -> Self::Output { Self(Self::hi(self.0 + a.0)) }}
impl Sub for Field { type Output = Self; fn sub(self, a: Self) -> Self::Output { Self(Self::lo(self.0 - a.0)) }}
impl Mul for Field { type Output = Self; fn mul(self, a: Self) -> Self::Output { Self(Self::cv(self.0 as i64 * a.0 as i64)) }}
impl Div for Field { type Output = Self; fn div(self, a: Self) -> Self::Output { self * a.inv() }}
impl Neg for Field { type Output = Self; fn neg(self) -> Self::Output { Self(Self::lo(-self.0)) }}
impl AddAssign for Field { fn add_assign(&mut self, a: Self) { *self = *self + a; } }
impl SubAssign for Field { fn sub_assign(&mut self, a: Self) { *self = *self - a; } }
impl MulAssign for Field { fn mul_assign(&mut self, a: Self) { *self = *self * a; } }
impl DivAssign for Field { fn div_assign(&mut self, a: Self) { *self = *self / a; } }
use std::fmt::{Display, Formatter, Result};
impl Display for Field { fn fmt(&self, f: &mut Formatter) -> Result { write!(f, "{}", self.0) } }
impl Sum<Self> for Field { fn sum<I>(i: I) -> Self where I: Iterator<Item = Self> { i.fold(Field(0), |a,b| a + b) } }
impl<'a> Sum<&'a Self> for Field { fn sum<I>(i: I) -> Self where I: Iterator<Item = &'a Self> { i.fold(Field(0), |a,&b| a + b) }}//'
impl Product<Self> for Field { fn product<I>(i: I) -> Self where I: Iterator<Item = Self> { i.fold(Field(1), |a,b| a * b) }}
impl<'a> Product<&'a Self> for Field { fn product<I>(i: I) -> Self where I: Iterator<Item = &'a Self> { i.fold(Field(1), |a,&b| a * b) }}//'
//}}}
// Z-Algorithm {{{
fn z_fn(s: &[u8]) -> Vec<i32> {
	let n = s.len();
	assert!(n > 0);
	l!(mut l,r = 0);
	let mut z = vec![0; n];
	z[0] = -1;
	for i in 1..n {
		if i <= r && z[i-l] < (r as i32) - (i as i32) +1 {
			z[i] = z[i-l];
		} else {
			l = i;
			m!(>, r, l);
			while r < n && s[r-l] == s[r] {
				r += 1;
			}
			z[i] = (r as i32) - (l as i32);
			r -= 1;
		}
	}
	z
}//}}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,m = rin.u());
	let p = rin.vb();
	let pn = p.len();
	let pi = pn as i32;
	let a = rin.vi(m);
	let z = z_fn(&p);
	for i in 1..m {
		let x = a[i] - a[i-1];
		if x < pi && x + z[x as usize] < pi {
			writeln!(rout, "0").ok();
			return;
		}
	}
	let mut d = vec![0_i32; n + 1];
	for x in a {
		let x = x as usize;
		d[x-1] += 1;
		d[x-1+pn] -= 1;
	}
	let mut c = 0;
	let mut e = 0;
	for i in 0..n {
		e += d[i];
		if e == 0 {
			c += 1;
		}
	}
	let sol = Field(26).pow(c);
	writeln!(rout, "{}", sol).ok();
}
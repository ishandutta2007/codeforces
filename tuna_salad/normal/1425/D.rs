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

// Field (mod prime) {{{
mod field {
	use std::ops::*;
	pub const Z0: Field = Field(0);
	pub const Z1: Field = Field(1);
	const P5: i32 = 1_000_000_007;
	const P6: i64 = P5 as i64;
	#[derive(Debug,Clone,Copy,PartialEq,Eq,PartialOrd,Ord,Default)] pub struct Field(i32);
	#[allow(dead_code)] impl Field {
		pub fn new<T: Into<i64>>(a: T) -> Self { Self(Self::cv(a)) }
		pub fn new_unchecked(a: i32) -> Self { Self(a) }
		fn hi(mut a: i32) -> i32 { if a >= P5 { a -= P5; } a }
		fn lo(mut a: i32) -> i32 { if a < 0 { a += P5; } a }
		fn cv<T: Into<i64>>(a: T) -> i32 { Self::lo((a.into() % P6) as i32) }
		pub fn inv(self) -> Self { self.pow(P5-2) }
		pub fn pow<T: Into<i64>>(self, b: T) -> Self {
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
}
#[allow(unused_imports)] use field::{Field, Field as Z, Z0, Z1};
//}}}
// Binomial Coefficient (C(n,r)) {{{
#[derive(Debug,Clone)]
struct Cnr {
	n: usize,
	f: Box<[Field]>,
	fi: Box<[Field]>
}
#[allow(dead_code)]
impl Cnr {
	fn new(n: usize) -> Self {
		let mut f = Vec::with_capacity(n+1);
		f.push(Z1);
		for i in 1..=n {
			f.push(f[i-1] * Field::new(i as i32));
		}
		let mut fi = vec![Z1; n+1];
		fi[n] = f[n].inv();
		for i in (0..n).rev() {
			fi[i] = fi[i+1] * Field::new(i as i32 + 1);
		}
		let f = f.into_boxed_slice();
		let fi = fi.into_boxed_slice();
		Self {n, f, fi}
	}
	fn cnr(&self, n: usize, r: usize) -> Field {
		if r > n {
			Z0
		} else {
			self.f[n] * self.fi[r] * self.fi[n-r]
		}
	}
}//}}}

const A: i32 = 1000;

fn calc(psum: &[Vec<i32>], x: i32, y: i32) -> i32 {
	let x = x.min(A).max(0) as usize;
	let y = y.min(A).max(0) as usize;
	psum[x][y]
}

fn calc_rect(psum: &[Vec<i32>], x1: i32, y1: i32, x2: i32, y2: i32) -> i32 {
	calc(psum, x2, y2) + calc(psum, x1-1, y1-1) - calc(psum, x2, y1-1) - calc(psum, x1-1, y2)
}

fn calc_rect_r(psum: &[Vec<i32>], x: i32, y: i32, r: i32) -> i32 {
	calc_rect(psum, x-r, y-r, x+r, y+r)
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();
	const A1: usize = 1001;

	l!(n,m = rin.u());
	let r = rin.i();
	let (snakes, psum) = {
		let mut psum = v!([A1][A1] = 0_i32);
		let mut s = v!([n]);
		rep!{[n]
			l!(x,y,b = rin.i());
			s.push( (x,y,Z::new(b)) );
			psum[x as usize][y as usize] += 1;
		}
		for i in 1..A1 {
			for j in 1..A1 {
				psum[i][j] += psum[i][j-1];
			}
			for j in 1..A1 {
				psum[i][j] += psum[i-1][j];
			}
		}
		(s,psum)
	};
	let f = Cnr::new(n);
	let all = f.cnr(n,m);
	let mut sol = Z0;
	let mut each_in = v!([n]);
	for i in 0..n {
		let (x,y,b) = snakes[i];
		let e = calc_rect_r(&psum, x, y, r);
		each_in.push(e);
		sol += (all - f.cnr(n - e as usize,m)) * b * b;
	}
	for i in 0..n {
		let (x1,y1,b1) = snakes[i];
		let e1 = each_in[i];
		for j in i+1..n {
			let (x2,y2,b2) = snakes[j];
			let e2 = each_in[j];
			let xmin = x1.max(x2) - r;
			let xmax = x1.min(x2) + r;
			let ymin = y1.max(y2) - r;
			let ymax = y1.min(y2) + r;
			let ee = if xmin <= xmax && ymin <= ymax {
				calc_rect(&psum, xmin, ymin, xmax, ymax)
			} else {
				0
			};
			let w = all - f.cnr(n - e1 as usize, m) - f.cnr(n - e2 as usize, m) + f.cnr(n - (e1 + e2 - ee) as usize, m);
			sol += Z::new(2) * w * b1 * b2;
		}
	}
	writeln!(rout, "{}", sol).ok();
}
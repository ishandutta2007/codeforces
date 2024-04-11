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
// DSU with sizes {{{
struct DSU {
	n: usize,
	par: Vec<usize>,
	sz: Vec<usize>
}
#[allow(dead_code)]impl DSU {
	fn new(n: usize) -> Self { let mut d = Self {n:0, par:Vec::new(), sz:Vec::new()}; d.resize(n); d }
	fn resize(&mut self, n: usize) { self.n = n; self.par.resize(n, 0); self.sz.resize(n, 1); self.reset(); }
	fn reset(&mut self) { for i in 0..self.n { self.par[i] = i; self.sz[i] = 1; } }
	fn find(&mut self, a: usize) -> usize {
		if a != self.par[a] { self.par[a] = self.find(self.par[a]); } self.par[a] }
	fn union(&mut self, mut a: usize, mut b: usize) -> bool {
		a = self.find(a); b = self.find(b); if a != b { self.par[a] = b; self.sz[b] += self.sz[a]; true } else { false } }
}//}}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,m = rin.u());
	let mut dsu = DSU::new(n);
	rep!{[m]
		l!(a,b = rin.u()-1);
		if a > 0 && b > 0 {
			dsu.union(a,b);
		}
	}
	let mut a = v!([]);
	for i in 1..n {
		if i == dsu.find(i) {
			a.push(dsu.sz[i] + 1);
		}
	}
	// writeln!(rout, "{:?}", a).ok();
	let s = a.len();
	let sz = 2*m;
	let mid = sz/2;
	let mut sol = Z0;
	{
		let mut dp0 = v!([s+1][sz+1] = Z0);
		dp0[0][mid] = Z1;
		for i in 0..s {
			let x = a[i];
			for j in x..=sz-x {
				let z = dp0[i][j];
				if z != Z0 {
					dp0[i+1][j-x] += z;
					dp0[i+1][j+x] += z;
				}
			}
		}
		sol += dp0[s][mid];
	}
	{
		let mut dp = v!([2][sz+1][2] = Z0);
		dp[0][mid][0] = Z1;
		for i in 0..s {
			let (dps1,dps2) = dp.split_at_mut(1);
			let (dp0,dp1) = if (i & 1) == 0 {(&mut dps1[0], &mut dps2[0])} else {(&mut dps2[0], &mut dps1[0])};
			let x = a[i];
			for j in x..=sz-x {
				for k in 0..=1 {
					let z = dp0[j][k];
					if z != Z0 {
						dp1[j-x][k] += z;
						dp1[j+x][k] += z;
						if k == 0 {
							dp1[j+x-1][1] += z;
							dp1[j-x+1][1] += z;
						}
					}
				}
			}
			for j in 0..=sz {
				dp0[j][0] = Z0;
				dp0[j][1] = Z0;
			}
		}
		sol += dp[s&1][mid][1] * Z::new(2);
	}
	{
		let mut dp2 = v!([s+1][sz+1] = Z0);
		dp2[0][mid] = Z1;
		for i in 0..s {
			let x = a[i];
			for j in x..=sz-x {
				let z = dp2[i][j];
				if z != Z0 {
					dp2[i+1][j-x] += z;
					dp2[i+1][j] += z;
					dp2[i+1][j+x] += z;
				}
			}
		}
		let mut dp = v!([2][sz+1] = Z0);
		dp[0][mid] = Z1;
		for i in 0..s {
			let (dps1,dps2) = dp.split_at_mut(1);
			let (dp0,dp1) = if (i & 1) == 0 {(&mut dps1[0], &mut dps2[0])} else {(&mut dps2[0], &mut dps1[0])};
			let x = a[s-1-i];
			for j in x..=sz-x {
				let z = dp0[j];
				if z != Z0 {
					dp1[j-x] += z;
					dp1[j] += z;
					dp1[j+x] += z;
				}
			}
			let xx = (x - 2) as i32;
			let i2 = s-1-i;
			for j in 1..sz {
				if dp0[j] != Z0 {
					let jj = j as i32;
					for k in -xx..=xx {
						if 0 <= jj + k && jj + k <= sz as i32 {
							let z = dp0[j] * dp2[i2][(jj + k) as usize];
							sol += z + z;
						}
					}
				}
			}
			for j in 0..=sz {
				dp0[j] = Z0;
			}
		}
	}
	writeln!(rout, "{}", sol).ok();
}
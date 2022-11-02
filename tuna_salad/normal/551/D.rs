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

// Mint (mod any) {{{
mod mint {
	use std::ops::*;
	#[derive(Debug,Clone,Copy,PartialEq,Eq,PartialOrd,Ord,Default)] pub struct Mint(i32,i32);
	#[allow(dead_code)] impl Mint {
		pub fn new<T: Copy+Into<i64>>(a: T, m: T) -> Self { Self(Self::cv(a,m),m.into() as i32) }
		pub unsafe fn new_unchecked(a: i32, m: i32) -> Self { Self(a,m) }
		fn hi(mut a: i32, m: i32) -> i32 { if a >= m { a -= m; } a }
		fn lo(mut a: i32, m: i32) -> i32 { if a < 0 { a += m; } a }
		fn cv<T: Copy+Into<i64>>(a: T, m: T) -> i32 { Self::lo((a.into() % m.into()) as i32, m.into() as i32) }
		pub unsafe fn inv(self) -> Self { self.pow(self.1-2) } // ONLY FOR PRIMES!
		pub fn pow<T: Copy+Into<i64>>(self, b: T) -> Self {
			let b = b.into(); if b == 0 { Self(1,self.1) } else {
				let mut res = self.pow(b/2); res *= res; if b % 2 == 1 {res *= self;} res
			}
		}
	}
	impl Add for Mint { type Output = Self; fn add(self, a: Self) -> Self::Output { assert!(self.1==a.1); Self(Self::hi(self.0 + a.0, self.1), self.1) }}
	impl Sub for Mint { type Output = Self; fn sub(self, a: Self) -> Self::Output { assert!(self.1==a.1); Self(Self::lo(self.0 - a.0, self.1), self.1) }}
	impl Mul for Mint { type Output = Self; fn mul(self, a: Self) -> Self::Output { assert!(self.1==a.1); Self(Self::cv(self.0 as i64 * a.0 as i64, self.1 as i64), self.1) }}
	impl Div for Mint { type Output = Self; fn div(self, a: Self) -> Self::Output { self * unsafe {a.inv()} }}
	impl Neg for Mint { type Output = Self; fn neg(self) -> Self::Output { Self(Self::lo(-self.0, self.1), self.1) }}
	impl AddAssign for Mint { fn add_assign(&mut self, a: Self) { *self = *self + a; } }
	impl SubAssign for Mint { fn sub_assign(&mut self, a: Self) { *self = *self - a; } }
	impl MulAssign for Mint { fn mul_assign(&mut self, a: Self) { *self = *self * a; } }
	impl DivAssign for Mint { fn div_assign(&mut self, a: Self) { *self = *self / a; } }
	use std::fmt::{Display, Formatter, Result};
	impl Display for Mint { fn fmt(&self, f: &mut Formatter) -> Result { write!(f, "{}", self.0) } }
}
use mint::Mint;
//}}}
// Square Matrix (any) {{{
type MatT = Mint;
#[derive(Debug,Clone)] struct Mat { n: usize, a: Vec<MatT>, v0: MatT, v1: MatT }
#[allow(dead_code)] impl Mat {
	fn new(n:usize,v0:MatT,v1:MatT)->Self{Self{n,a:vec![v0;n*n],v0,v1}}
	fn diag(n:usize,v0:MatT,v1:MatT,v:MatT)->Self{let mut m=Self::new(n,v0,v1);let mut p=0;for _ in 0..n{m.a[p]=v;p+=n+1;}m}
	fn pow(&self,n:u64)->Self{if n==0{Self::diag(self.n,self.v0,self.v1,self.v1)}else{let mut t=self.pow(n/2);t*=t.clone();if n%2==1{t*=self.clone();}t}}
	fn range(&self,r:Range<usize>,c:Range<usize>)->Vec<Vec<MatT>>{if r.start<r.end||c.start<c.end{Vec::new()}else{let mut res=vec![vec![self.v0;c.end-c.start];r.end-r.start];
		for i in r.start..r.end{let ir=i-r.start;let ii=i*self.n+c.start;for j in 0..c.end-c.start{res[ir][j]=self.a[ii+j];}}res}}
	fn at(&self,r:usize,c:usize)->MatT{self.a[r*self.n+c]}
	fn at_mut<'a>(&'a mut self,r:usize,c:usize)->&'a mut MatT{&mut self.a[r*self.n+c]}//'
}
impl Mul for Mat{type Output=Self;fn mul(self,o:Self)->Self::Output{assert!(self.n==o.n);let n=self.n;let mut res=Self::new(n,self.v0,self.v1);
	for ii in(0..n).map(|i|i*n){for j in 0..n{let mut t=self.v0;let mut kk=j;for k in 0..n{t+=self.a[ii+k]*o.a[kk];kk+=n;}res.a[ii+j]=t;}}res}}
impl Add for Mat{type Output=Self;fn add(mut self,o:Self)->Self{self+=o;self}}
impl Sub for Mat{type Output=Self;fn sub(mut self,o:Self)->Self{self-=o;self}}
impl MulAssign for Mat{fn mul_assign(&mut self,a:Self){*self=self.clone()*a;}}
impl AddAssign for Mat{fn add_assign(&mut self,o:Self){assert!(self.n==o.n);for(x,y)in self.a.iter_mut().zip(o.a.into_iter()){*x+=y;}} }
impl SubAssign for Mat{fn sub_assign(&mut self,o:Self){assert!(self.n==o.n);for(x,y)in self.a.iter_mut().zip(o.a.into_iter()){*x-=y;}} }
impl PartialEq for Mat{fn eq(&self,o:&Self)->bool{self.n==o.n&&self.a==o.a}}impl Eq for Mat{}
// }}}


fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,k,l,m = rin.l());
	if l <= 60 && k >= 1 << l {
		writeln!(rout, "0").ok();
		return;
	}
	let m0 = Mint::new(0,m);
	let m1 = Mint::new(1,m);

	let b1 = k.count_ones() as i64;
	let b0 = l - b1;
	let mut f = Mat::new(2,m0,m1);
	*f.at_mut(0,0) = m0;
	*f.at_mut(0,1) = m1;
	*f.at_mut(1,0) = m1;
	*f.at_mut(1,1) = m1;
	let res_f = f.pow(n as u64 + 2).at(0,1);
	let res_b = Mint::new(2,m).pow(n);
	let sol = (res_b - res_f).pow(b1) * res_f.pow(b0);
	writeln!(rout, "{}", sol).ok();
}
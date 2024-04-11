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

// 2D Geometry {{{
mod geometry {
	use std::ops::*;
	use std::f64::consts::*;
	#[derive(Debug,Clone,Copy,PartialEq)] pub struct Pt2 {pub x: f64, pub y: f64}
	#[derive(Debug,Clone,Copy,PartialEq)] pub struct Vec2 {pub dx: f64, pub dy: f64}
	#[allow(dead_code)] impl Pt2 {
		pub fn new(x: f64, y: f64) -> Self { Self {x,y} }
		pub fn origin() -> Self { Self::new(0.0,0.0) }
		pub fn dist_sqr(self, o: Self) -> f64 { (self - o).len_sqr() }
		pub fn dist(self, o: Self) -> f64 { (self - o).len() }
		pub fn linterp(self, o: Self, r: f64) -> Self { self + (o - self).scale(r) }
		pub fn rotate_rad_about(self, o: Self, rad: f64) -> Self { o + (self - o).rotate_rad(rad) }
		pub fn rotate_deg_about(self, o: Self, deg: f64) -> Self { o + (self - o).rotate_deg(deg) }
	}
	#[allow(dead_code)] impl Vec2 {
		pub fn new(dx: f64, dy: f64) -> Self { Self {dx,dy} }
		pub fn dot(self, o: Self) -> f64 { self.dx*o.dx + self.dy*o.dy }
		pub fn cross(self, o: Self) -> f64 { self.dx*o.dy - self.dy*o.dx }
		pub fn rotate_rad(self, rad: f64) -> Self {
			let (s,c) = rad.sin_cos();
			Self {dx: c * self.dx - s * self.dy, dy: s * self.dx + c * self.dy}
		}
		pub fn rotate_deg(self, deg: f64) -> Self { self.rotate_rad(deg / 180.0 * PI) }
		pub fn scale(self, s: f64) -> Self { Self {dx: self.dx * s, dy: self.dy * s} }
		pub fn len_sqr(self) -> f64 { self.dot(self) }
		pub fn len(self) -> f64 { self.len_sqr().sqrt() }
		pub fn angle_rad(self) -> f64 { self.dy.atan2(self.dx) }
		pub fn angle_deg(self) -> f64 { self.angle_rad() * 180.0 * FRAC_1_PI }
		pub fn normalize(self) -> Self { self.scale(1.0 / self.len()) }
	}
	impl Add for Vec2 { type Output = Self; fn add(self, o: Self) -> Self::Output { Self::new(self.dx+o.dx, self.dy+o.dy) }}
	impl Add<Pt2> for Vec2 { type Output = Pt2; fn add(self, o: Pt2) -> Self::Output { o + self }}
	impl Add<Vec2> for Pt2 { type Output = Pt2; fn add(self, o: Vec2) -> Self::Output { Pt2::new(self.x+o.dx, self.y+o.dy) }}
	impl AddAssign for Vec2 { fn add_assign(&mut self, o: Self) { self.dx += o.dx; self.dy += o.dy; }}
	impl AddAssign<Vec2> for Pt2 { fn add_assign(&mut self, o: Vec2) { self.x += o.dx; self.y += o.dy; }}
	impl Neg for Vec2 { type Output = Self; fn neg(self) -> Self::Output { Self::new(-self.dx, -self.dy) }}
	impl Sub for Pt2 { type Output = Vec2; fn sub(self, o: Self) -> Self::Output { Vec2::new(self.x-o.x, self.y-o.y) }}
	impl Sub for Vec2 { type Output = Self; fn sub(self, o: Self) -> Self::Output { self + -o }}
	impl Sub<Vec2> for Pt2 { type Output = Pt2; fn sub(self, o: Vec2) -> Self::Output { self + -o }}
	impl From<Pt2> for Vec2 { fn from(p: Pt2) -> Vec2 { Vec2 {dx: p.x, dy: p.y} }}
	impl From<Vec2> for Pt2 { fn from(v: Vec2) -> Pt2 { Pt2 {x: v.dx, y: v.dy} }}
	pub fn intersect(p1: Pt2, v1: Vec2, p2: Pt2, v2: Vec2) -> Option<(f64,f64,Pt2)> {
		let c = v2.cross(v1);
		if c.abs() < 1e-15 { return None; }
		let d = p1 - p2;
		let s = d.cross(v2) / c;
		let t = d.cross(v1) / c;
		let q = p1 + v1.scale(s);
		Some( (s,t,q) )
	}
	pub fn center_from_3(p: &[Pt2]) -> Option<Pt2> {
		assert!(p.len() >= 3);
		let bisect = |p: Pt2, q: Pt2| -> (Pt2,Vec2) {
			let m = p.linterp(q, 0.5);
			let a = p.rotate_deg_about(m, 90.0);
			(a, m-a)
		};
		let (a1,v1) = bisect(p[0],p[1]);
		let (a2,v2) = bisect(p[1],p[2]);
		if let Some( (_,_,c) ) = intersect(a1,v1,a2,v2) {
			Some(c)
		} else {
			None
		}
	}
}//}}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let mut p = Vec::new();
	rep!{[3]
		l!(x,y = rin.f());
		p.push( geometry::Pt2::new(x,y) );
	}
	let center = geometry::center_from_3(&p).unwrap();
	let angles = p.iter().map(|q| (*q - center).angle_deg() / 360.0).collect::<Vec<_>>();
	let diff = vec![angles[1] - angles[0], angles[2] - angles[0]];
	let mut sol = (1.0, 0.0);
	for n in 3..=100 {
		let mut di = diff.iter().map(|&a| {
			let x = a * n as f64;
			let y = x.round();
			(x-y).abs()
		});
		let d0 = di.next().unwrap();
		let d1 = di.next().unwrap();
		let d = d0.max(d1);
		if d + 1e-6 < sol.0 {
			let ang = 360.0 / n as f64;
			let v = p[2] - center;
			let area = v.cross(v.rotate_deg(ang)) * n as f64 / 2.0;
			sol = (d, area);
		}
	}
	writeln!(rout, "{:.9}", sol.1).ok();
}
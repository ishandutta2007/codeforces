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
		Self { q: r.lock(), buf: v!([]), pos: 0 }
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
		let mut s = v!([8]);
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
	fn vvb(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rep!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
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
	fn graph(&mut self, n: usize, m: usize) -> Vec<Vec<usize>> {
		let mut e = v!([n][]); rep!{[m] l!(a,b = self.u()-1); e[a].push(b); e[b].push(a); } e
	}
	fn graph_w<T: Copy+FromStr>(&mut self, n: usize, m: usize) -> Vec<Vec<(usize,T)>> where T::Err: Debug {
		let mut e = v!([n][]); rep!{[m] l!(a,b = self.u()-1); let c: T = self.p(); e[a].push((b,c)); e[b].push((a,c)); } e
	}
}
//------------------- End rusT }}}

// 2D Geometry (integer) {{{
mod geometry {
	use std::ops::*;
	#[derive(Debug,Clone,Copy,PartialEq)] pub struct Pt2 {pub x: i64, pub y: i64}
	#[derive(Debug,Clone,Copy,PartialEq)] pub struct Vec2 {pub dx: i64, pub dy: i64}
	#[allow(dead_code)] impl Pt2 {
		pub fn new(x: i64, y: i64) -> Self { Self {x,y} }
		pub fn origin() -> Self { Self::new(0,0) }
		pub fn dist_sqr(self, o: Self) -> i64 { (self - o).len_sqr() }
		pub fn rotate_90_about(self, o: Self) -> Self { o + (self - o).rotate_90() }
	}
	#[allow(dead_code)] impl Vec2 {
		pub fn new(dx: i64, dy: i64) -> Self { Self {dx,dy} }
		pub fn dot(self, o: Self) -> i64 { self.dx*o.dx + self.dy*o.dy }
		pub fn cross(self, o: Self) -> i64 { self.dx*o.dy - self.dy*o.dx }
		pub fn rotate_90(self) -> Self { Self {dx: -self.dy, dy: self.dx} }
		pub fn len_sqr(self) -> i64 { self.dot(self) }
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
}//}}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	use geometry::Pt2;
	rep!{[rin.u()]
		l!(mut p,h = v!([4]));
		rep!{[4]
			l!(a,b,c,d = rin.l());
			p.push( Pt2::new(a,b) );
			h.push( Pt2::new(c,d) );
		}
		let mut sol = 100;
		for b in 0..1<<8 {
			let mut res = 0;
			let mut pp = p.clone();
			for i in 0..4 {
				let c = (b >> (2*i)) & 3;
				res += c;
				rep!{[c]
					pp[i] = pp[i].rotate_90_about(h[i]);
				}
			}
			let mut d = v!([6]);
			for i in 0..4 {
				for j in i+1..4 {
					d.push( (pp[i] - pp[j]).len_sqr() );
				}
			}
			d.sort();
			if d[0] == d[3] && d[4] == d[5] && d[0] > 0 {
				min!(sol, res);
			}
		}
		if sol == 100 {
			writeln!(rout, "-1").ok();
		} else {
			writeln!(rout, "{}", sol).ok();
		}
	}
}
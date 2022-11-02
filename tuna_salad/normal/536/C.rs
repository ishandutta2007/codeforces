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

fn turn_ok(a: &(i32,i32,Vec<usize>), b: &(i32,i32,Vec<usize>), c: &(i32,i32,Vec<usize>)) -> bool {
	let f = |a: &(i32,i32,_)| (1.0 / a.0 as f64, 1.0 / a.1 as f64);
	let a = f(a);
	let b = f(b);
	let c = f(c);
	let p = (b.0 - a.0, b.1 - a.1);
	let q = (c.0 - a.0, c.1 - a.1);
	p.0 * q.1 - p.1 * q.0 < 0.0
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let n = rin.u();
	let mut p = Vec::with_capacity(n);
	l!(mut max_xy,max_yx = (0,0));
	let mut h = HashMap::new();
	for i in 0..n {
		l!(x,y = rin.i());
		let e = h.entry((x,y)).or_insert(Vec::new());
		e.push(i);
	}
	for ((x,y),id) in h {
		p.push((x,y,id));
		let f = |s: &mut (i32,i32), x0, y0| {
			if m!(>, s.0, x0) {
				s.1 = 0;
			}
			if s.0 == x0 {
				m!(>, s.1, y0);
			}
		};
		f(&mut max_xy, x, y);
		f(&mut max_yx, y, x);
	}
	p.retain(|&(x,y,_)| {
		((x,y) == max_xy || y > max_xy.1) && ((y,x) == max_yx || x > max_yx.1)
	});
	p.sort();
	let mut st = Vec::new();
	for (x,y,i) in p {
		while st.len() > 1 {
			let l = st.len();
			if turn_ok(&st[l-2], &st[l-1], &(x,y,Vec::new())) {
				break;
			}
			st.pop();
		}
		st.push((x,y,i));
	}
	let mut sol = Vec::with_capacity(st.len());
	for (_,_,mut i) in st {
		sol.append(&mut i);
	}
	sol.sort();
	for x in sol {
		write!(rout, "{} ", x+1).ok();
	}
}
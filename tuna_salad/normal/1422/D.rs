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

// Coordinate compression {{{
fn compress<T: Ord>(a: &[T], start_from: usize) -> (usize, Vec<usize>) {
	let n = a.len();
	let mut t = Vec::with_capacity(n);
	for i in 0..n {
		t.push(i);
	}
	t.sort_by(|x,y| a[*x].cmp(&a[*y]));
	let mut b = vec![0; n];
	let mut v = start_from;
	for i in 0..n {
		if i > 0 && a[t[i-1]] < a[t[i]] {
			v += 1;
		}
		b[t[i]] = v;
	}
	(v, b)
}//}}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(_n,m = rin.u());
	l!(mut xx,yy,p = v!([m+2]));
	rep!{[m+2]
		l!(x,y = rin.i());
		xx.push(x);
		yy.push(y);
		p.push( (x,y,0,0) );
	}
	let (xn,xx) = compress(&xx, 0);
	let (yn,yy) = compress(&yy, 0);
	for i in 0..m+2 {
		p[i].2 = xx[i];
		p[i].3 = yy[i];
	}
	let xn = xn + 1;
	let yn = yn + 1;
	let mut xx = v!([xn] = 0);
	let mut yy = v!([yn] = 0);
	let mut xlist = v!([xn][]);
	let mut ylist = v!([yn][]);
	for i in 0..m+2 {
		xx[p[i].2] = p[i].0;
		yy[p[i].3] = p[i].1;
	}
	for i in 2..m+2 {
		xlist[p[i].2].push(i);
		ylist[p[i].3].push(i);
	}
	let mut e = v!([2+xn+yn][]);
	e[1].push( (0, (p[0].0-p[1].0).abs() + (p[0].1-p[1].1).abs()) );
	for i in 2..m+2 {
		let (x,y,xc,yc) = p[i];
		let x_id = 2+xc;
		let y_id = 2+xn+yc;
		let d1 = (x-p[1].0).abs() + (y-p[1].1).abs();
		e[1].push( (x_id, d1) );
		e[1].push( (y_id, d1) );
		e[x_id].push( (0, (x-p[0].0).abs()) );
		e[y_id].push( (0, (y-p[0].1).abs()) );
		e[x_id].push( (y_id, 0) );
		e[y_id].push( (x_id, 0) );
	}
	for i in 1..xn {
		let x0_id = 2+i-1;
		let x1_id = 2+i;
		let dx = xx[i] - xx[i-1];
		e[x0_id].push( (x1_id, dx) );
		e[x1_id].push( (x0_id, dx) );
	}
	for i in 1..yn {
		let y0_id = 2+xn+i-1;
		let y1_id = 2+xn+i;
		let dy = yy[i] - yy[i-1];
		e[y0_id].push( (y1_id, dy) );
		e[y1_id].push( (y0_id, dy) );
	}
	let mut dist = v!([2+xn+yn] = -1);
	let mut q = BinaryHeap::new();
	q.push( (0,1) );
	while let Some( (d,u) ) = q.pop() {
		if dist[u] >= 0 {
			continue;
		}
		dist[u] = -d;
		if u == 0 {
			break;
		}
		for &(v,w) in e[u].iter() {
			if dist[v] == -1 {
				q.push( (d-w, v) );
			}
		}
	}
	writeln!(rout, "{}", dist[0]).ok();
}
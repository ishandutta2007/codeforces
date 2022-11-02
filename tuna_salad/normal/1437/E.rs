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
	fn board(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rep!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
	}
	fn framed_board(&mut self, r: usize, c: usize, f: u8) -> Vec<Vec<u8>> {
		let mut res = v!([r+2]);
		res.push( v!([c+2] = f) );
		rep!{[r]
			let mut t = self.vb();
			assert!(t.len() == c);
			t.reserve(2);
			t.insert(0,f);
			t.push(f);
			res.push(t);
		}
		res.push( v!([c+2] = f) );
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

// Fenwick Tree {{{
mod fenwick {
	type V = i32;
	pub struct Tree {
		n: usize,
		pub arr: Box<[V]>
	}
	impl Tree {
		pub fn new(n: usize) -> Self {
			let arr = vec![-1000000; n + 1].into_boxed_slice();
			Self { n, arr }
		}
		pub fn add(&mut self, p: usize, v: V) {
			let mut p = p as i32;
			let n = self.n as i32;
			while p <= n {
				max!(self.arr[p as usize], v);
				p += p & -p;
			}
		}
		pub fn sum(&self, p: usize) -> V {
			let mut p = p as i32;
			let mut res = -1000000;
			while p > 0 {
				max!(res, self.arr[p as usize]);
				p -= p & -p;
			}
			res
		}
	}
}//}}}
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

fn solve(a: &[i32]) -> usize {
	let n = a.len();
	let (k,b) = compress(a,1);
	let mut ft = fenwick::Tree::new(k);
	ft.add(b[0], 1);
	for &x in b[1..n-1].iter() {
		let y = ft.sum(x) + 1;
		ft.add(x, y);
	}
	let res = ft.sum(b[n-1]) + 1;
	n - res as usize
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,k = rin.u());
	let mut a = v!([n+2]);
	a.push(0);
	for i in 1..=n {
		a.push(rin.i() + (n-i) as i32);
	}
	a.push(1001000000);
	let mut b = v!([k+2]);
	b.push(0);
	rep!{[k]
		b.push(rin.u());
	}
	b.push(n+1);
	let k = k+2;
	for i in 1..k {
		if a[b[i]] < a[b[i-1]] {
			writeln!(rout, "-1").ok();
			return;
		}
	}
	let mut sol = 0;
	for i in 1..k {
		sol += solve(&a[b[i-1]..=b[i]]);
	}
	writeln!(rout, "{}", sol).ok();
}
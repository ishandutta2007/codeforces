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

fn main() {
	let mut rin = reader();
	let mut rout = writer();
	const B: usize = 300;
	const BN: usize = 400;

	let n = rin.u();
	assert!(n <= B*BN);
	let a = rin.vu(n);
	let mut pos = v!([n+2][]);
	for i in 0..n {
		pos[a[i]].push(i);
	}
	if pos[1].len() == n {
		writeln!(rout, "1").ok();
		return;
	}
	let mut q = v!([BN][]);
	let mut push = |l: usize, r: usize, x: usize| {
		// println!("insert query {} {} {}", l, r, x);
		q[l/B].push( (r,l,x) );
	};
	for i in 1..=n {
		let p = &pos[i+1];
		let m = p.len();
		if m == 0 {
			push(0,n-1,i);
		} else {
			if p[0] != 0 {
				push(0, p[0]-1, i);
			}
			for j in 1..m {
				if p[j-1]+1 < p[j] {
					push(p[j-1]+1, p[j]-1, i);
				}
			}
			if p[m-1] != n-1 {
				push(p[m-1]+1, n-1, i);
			}
		}
	}
	drop(push);
	let mut res = v!([n+2] = 0);
	l!(mut l,r,c = 0);
	l!(mut first,forw = true);
	let mut freq = v!([n+2] = 0);
	let mut h = BinaryHeap::new();
	let clear = |h: &mut BinaryHeap<i32>, f: &[usize]| {
		loop {
			let x = (-h.peek().unwrap()) as usize;
			if f[x] > 0 {
				h.pop();
			} else {
				break;
			}
		}
	};
	let insert = |h: &mut BinaryHeap<i32>, f: &mut [usize], x: usize| -> usize {
		f[x] += 1;
		clear(h, f);
		(-h.peek().unwrap()) as usize
	};
	let remove = |h: &mut BinaryHeap<i32>, f: &mut [usize], x: usize| -> usize {
		f[x] -= 1;
		if f[x] == 0 {
			h.push( -(x as i32) );
		}
		(-h.peek().unwrap()) as usize
	};
	for i in 1..=n+1 {
		h.push( -(i as i32) );
	}
	for q in q.iter_mut() {
		if q.len() == 0 { continue; }
		q.sort();
		if !forw {
			q.reverse();
		}
		forw = !forw;
		if first {
			first = false;
			let (rr,ll,_) = q[0];
			for i in ll..=rr {
				c = insert(&mut h, &mut freq, a[i]);
			}
			l = ll;
			r = rr;
		}
		for &(rr,ll,x) in q.iter() {
			while ll < l {
				l -= 1;
				c = insert(&mut h, &mut freq, a[l]);
			}
			while r < rr {
				r += 1;
				c = insert(&mut h, &mut freq, a[r]);
			}
			while l < ll {
				c = remove(&mut h, &mut freq, a[l]);
				l += 1;
			}
			while rr < r {
				c = remove(&mut h, &mut freq, a[r]);
				r -= 1;
			}
			max!(res[x], c);
		}
	}
	let mut sol = 1;
	while res[sol] > sol {
		sol += 1;
	}
	writeln!(rout, "{}", sol+1).ok();
}
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

fn dfs(u: usize, par: usize, e: &[Vec<usize>], a: &[i64], cc: &mut Vec<i64>, sol: &mut [i64], t: &mut [(usize,usize)]) -> (usize,i64,usize,HashMap<i64,usize>) {
	let mut sz = 1;
	let mut rr = Vec::with_capacity(e[u].len());
	let mut ss = Vec::with_capacity(e[u].len());
	cc.push(a[u]);
	t[u].0 = cc.len() - 1;
	for &v in e[u].iter() {
		if v != par {
			let (s1,r1,f1,h1) = dfs(v, u, e, a, cc, sol, t);
			rr.push( (v,r1,f1,h1) );
			ss.push( (s1,rr.len()-1) );
			sz += s1;
		}
	}
	let add = |x: i64, res: &mut i64, freq: &mut usize, h: &mut HashMap<_,_>| {
		let e = h.entry(x).or_insert(0);
		*e += 1;
		if *e > *freq {
			*freq = *e;
			*res = 0;
		}
		if *e == *freq {
			*res += x;
		}
	};
	let mut res = 0;
	let mut freq = 0;
	let mut h = HashMap::new();
	if ss.len() > 0 {
		ss.sort();
		let id = ss.pop().unwrap().1;
		std::mem::swap(&mut h, &mut rr[id].3);
		{
			let (_,r1,f1,_) = rr[id];
			res = r1;
			freq = f1;
		}
		for (_,id) in ss {
			let v = rr[id].0;
			for &c in cc[t[v].0..=t[v].1].iter() {
				add(c, &mut res, &mut freq, &mut h);
			}
		}
	}
	add(a[u], &mut res, &mut freq, &mut h);
	sol[u] = res;
	t[u].1 = cc.len() - 1;
	(sz, res, freq, h)
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let n = rin.u();
	let a = rin.vl(n);
	let mut e = vec![Vec::new(); n];
	rep!{[n-1]
		l!(a,b = rin.u()-1);
		e[a].push(b);
		e[b].push(a);
	};
	let mut cc = Vec::with_capacity(n);
	let mut sol = vec![-1; n];
	let mut t = vec![(n,n); n];
	dfs(0, n, &e, &a, &mut cc, &mut sol, &mut t);
	for s in sol {
		write!(rout, "{} ", s).ok();
	}
}
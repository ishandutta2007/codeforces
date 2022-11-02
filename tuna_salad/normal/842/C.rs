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
}
//------------------- End rusT }}}

fn gcd(a: usize, b: usize) -> usize {
	if b == 0 {a} else {gcd(b, a%b)}
}

fn dfs0(u: usize, par: usize, e: &[Vec<usize>], a: &[usize], sol0: &mut [usize]) {
	assert!(u != 0);
	sol0[u] = gcd(a[u], sol0[par]);
	for &v in e[u].iter() {
		if v != par {
			dfs0(v, u, e, a, sol0);
		}
	}
}

fn dfs1(u: usize, par: usize, mut dep: usize, e: &[Vec<usize>], a: &[usize], divs: &[Vec<usize>], sol1: &mut [usize], freq: &mut [usize], mode: &mut BTreeSet<(usize,usize)>, f: &mut [u8]) {
	assert!(u != 0);
	let mut div = v!([]);
	let mut is_new = true;
	if f[a[u]] == 2 {
		is_new = false;
	} else {
		f[a[u]] += 1;
		dep += 1;
		for &x in divs[a[u]].iter() {
			if freq[x] > 0 && freq[x] + 2 >= dep {
				div.push(x);
				mode.remove( &(freq[x],x) );
				freq[x] += 1;
				mode.insert( (freq[x],x) );
			}
		}
	}
	for d in dep-1..=dep {
		if let Some( &(_,x) ) = mode.range((d,0)..(d+1,0)).rev().next() {
			max!(sol1[u], x);
		}
	}
	for &v in e[u].iter() {
		if v != par {
			dfs1(v, u, dep, e, a, divs, sol1, freq, mode, f);
		}
	}
	if is_new {
		f[a[u]] -= 1;
		for x in div {
			mode.remove( &(freq[x],x) );
			freq[x] -= 1;
			mode.insert( (freq[x],x) );
		}
	}
}

fn divisors(a: usize) -> Vec<usize> {
	let mut res = v!([]);
	let mut i = 1;
	while i*i < a {
		if a % i == 0 {
			res.push(i);
			res.push(a/i);
		}
		i += 1;
	}
	if i*i == a {
		res.push(i);
	}
	res
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();
	const A: usize = 200000;

	let n = rin.u();
	let a = rin.vu(n);
	let mut e = v!([n][]);
	rep!{[n-1]
		l!(u,v = rin.u()-1);
		e[u].push(v);
		e[v].push(u);
	}
	let mut sol0 = v!([n] = 0);
	for &v in e[0].iter() {
		dfs0(v, 0, &e, &a, &mut sol0);
	}
	let mut divs = v!([A+1][]);
	for &x in a.iter() {
		if divs[x].is_empty() {
			divs[x] = divisors(x);
		}
	}
	let mut freq = v!([A+1] = 0);
	let mut mode = BTreeSet::new();
	for &x in divs[a[0]].iter() {
		mode.insert( (1,x) );
		freq[x] = 1;
	}
	let mut sol1 = v!([n] = 0);
	let mut f = v!([A+1] = 0);
	f[a[0]] = 1;
	sol1[0] = a[0];
	for &v in e[0].iter() {
		dfs1(v, 0, 1, &e, &a, &divs, &mut sol1, &mut freq, &mut mode, &mut f);
	}
	for i in 0..n {
		let res = sol0[i].max(sol1[i]);
		write!(rout, "{} ", res).ok();
	}
}
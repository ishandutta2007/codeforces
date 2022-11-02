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

const A: usize = 2000000;
const A_SQRT: usize = 1500;

fn factorize(ppd: (usize, &[usize], &[usize]), mut x: usize) -> Vec<usize> {
	let mut res = Vec::new();
	while x > 1 {
		let d = ppd.2[x];
		res.push(ppd.1[d]);
		x /= d;
	}
	res.sort();
	res.dedup();
	res
}

fn dfs(u: usize, par: usize, depth: usize, e: &[Vec<usize>], f: &[Vec<usize>], ppd: (usize, &[usize], &[usize]), ans: &mut [i32], tab: &mut [(usize,usize)]) {
	let mut a = Vec::with_capacity(f[u].len());
	{
		l!(mut d,m = 0);
		for &i in f[u].iter() {
			let x = tab[i];
			tab[i] = (depth, u);
			if m!(>, d, x.0) {
				m = x.1;
			}
			a.push(x);
		}
		if d == 0 {
			ans[u] = -1;
		} else {
			ans[u] = m as i32 + 1;
		}
	}
	for &v in e[u].iter() {
		if v != par {
			dfs(v, u, depth+1, e, f, ppd, ans, tab);
		}
	}
	for &i in f[u].iter().rev() {
		tab[i] = a.pop().unwrap();
	}
}
fn calc(u: usize, par: usize, e: &[Vec<usize>], f: &[Vec<usize>], ppd: (usize, &[usize], &[usize]), ans: &mut [i32]) {
	let mut tab = vec![(0,0); A+1];
	dfs(u, par, 1, e, f, ppd, ans, &mut tab);
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,q = rin.u());
	let a = rin.vu(n);
	l!(mut e,f = vec![Vec::new(); n]);
	rep!{[n-1]
		l!(a,b = rin.u()-1);
		e[a].push(b);
		e[b].push(a);
	};
	let ppd = {
		let mut div = vec![0; A + 1];
		let mut pos = vec![0; A + 1];
		let mut np = 0;
		for x in 2..=A {
			if div[x] == 0 {
				pos[x] = np;
				np += 1;
				div[x] = x;
				if x <= A_SQRT {
					let mut y = x * x;
					while y <= A {
						div[y] = x;
						y += x;
					}
				}
			}
		}
		(np, pos, div)
	};
	let ppd = (ppd.0, &ppd.1[..], &ppd.2[..]);
	for i in 0..n {
		f[i] = factorize(ppd, a[i]);
	}
	let mut ans = vec![-1; n];
	calc(0, n, &e, &f, ppd, &mut ans);
	rep!{[q]
		let t = rin.u();
		let v = rin.u()-1;
		if t == 1 {
			writeln!(rout, "{}", ans[v]).ok();
		} else {
			f[v] = factorize(ppd, rin.u());
			calc(0, n, &e, &f, ppd, &mut ans);
		}
	};
}
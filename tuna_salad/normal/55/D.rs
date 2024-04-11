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

const M: usize = 2520;
const U: usize = 48;

fn gcd(a: usize, b: usize) -> usize {
	if b == 0 {a} else {gcd(b, a%b)}
}

fn calc(a: i64) -> i64 {
	if a <= 9 { return a; }
	let s = format!("{}", a);
	let n = s.len();
	let mut b = v!([n]);
	for c in s.bytes() {
		b.push( (c - b'0') as usize );
	}
	let mut u_to = v!([U][10] = 0);
	let mut uuu = v!([M+1] = U);
	let mut uu = v!([U]);
	for i in 0..1<<8 {
		let mut x = 1;
		for j in 0..8 {
			if i & (1<<j) > 0 {
				x *= (j+2) / gcd(x, j+2);
			}
		}
		uu.push(x);
	}
	uu.sort();
	uu.dedup();
	assert!(U == uu.len());
	for i in 0..U {
		uuu[uu[i]] = i;
	}
	for i in 0..U {
		let u = uu[i];
		for d in 0..=9 {
			if d <= 1 {
				u_to[i][d] = i;
			} else {
				let x = u * d / gcd(u,d);
				u_to[i][d] = uuu[x];
			}
		}
	}
	let mut m_to = v!([M][10] = 0);
	for m in 0..M {
		for d in 0..=9 {
			m_to[m][d] = (m*10+d) % M;
		}
	}
	let mut dp0 = v!([3][U][M] = 0_i64);
	let wh = |d: usize, x: usize| -> usize {
		if d < x {
			0
		} else if d == x {
			1
		} else {
			2
		}
	};
	for i in 0..=9 {
		dp0[wh(i,b[0])][u_to[0][i]][i] = 1;
	}
	for i in 1..n {
		let b = b[i];
		let mut dp1 = v!([3][U][M] = 0_i64);
		for j in 0..U {
			for k in 0..M {
				let x = dp0[0][j][k];
				if x > 0 {
					for d in 0..=9 {
						dp1[0][u_to[j][d]][m_to[k][d]] += x;
					}
				}
			}
		}
		for j in 0..U {
			for k in 0..M {
				let x = dp0[1][j][k];
				if x == 0 { continue; }
				for d in 0..=9 {
					dp1[wh(d,b)][u_to[j][d]][m_to[k][d]] += x;
				}
			}
		}
		dp0 = dp1;
	}
	let mut res = -1;
	for l in 0..=1 {
		for j in 0..U {
			let dd = uu[j];
			let mut k = 0;
			while k < M {
				res += dp0[l][j][k];
				k += dd;
			}
		}
	}
	res
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	rep!{[rin.u()]
		l!(l,r = rin.l());
		let sol = calc(r) - calc(l-1);
		writeln!(rout, "{}", sol).ok();
	}
}
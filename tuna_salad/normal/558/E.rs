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

	l!(n,q = rin.u());
	let s = rin.vb();
	let mut a = BTreeMap::new();
	for i in 0..n {
		let mut t = v!([26] = 0);
		t[(s[i] - b'a') as usize] = 1;
		a.insert((i,i), (1,t));
	}
	rep!{[q]
		l!(l,r = rin.u()-1);
		let k = rin.u();
		let mut q = v!([]);
		let mut qq = v!([]);
		for (&(ll,rr),_) in a.range((l,l)..) {
			if r < ll {
				break;
			}
			q.push( (ll,rr) );
		}
		for x in q.drain(..) {
			qq.push( (x, a.remove(&x).unwrap()) );
		}
		for (&(ll,rr),_) in a.range(..(l,l)).rev() {
			if rr < l {
				break;
			}
			q.push( (ll,rr) );
		}
		for x in q.drain(..) {
			qq.push( (x, a.remove(&x).unwrap()) );
		}
		let mut t = v!([26] = 0);
		for ((ll,rr),(kk,mut tt)) in qq {
			if ll < l {
				let mut ttt = v!([26] = 0);
				assert!(l <= rr);
				let mut x = l - ll;
				if kk == 1 {
					for i in 0..26 {
						if tt[i] >= x {
							tt[i] -= x;
							ttt[i] += x;
							break;
						} else {
							let z = tt[i];
							x -= z;
							ttt[i] = z;
							tt[i] = 0;
						}
					}
				} else {
					for i in (0..26).rev() {
						if tt[i] >= x {
							tt[i] -= x;
							ttt[i] += x;
							break;
						} else {
							let z = tt[i];
							x -= z;
							ttt[i] = z;
							tt[i] = 0;
						}
					}
				}
				a.insert((ll,l-1), (kk,ttt));
			}
			if r < rr {
				let mut ttt = v!([26] = 0);
				assert!(ll <= r);
				let mut x = rr - r;
				if kk == 0 {
					for i in 0..26 {
						if tt[i] >= x {
							tt[i] -= x;
							ttt[i] += x;
							break;
						} else {
							let z = tt[i];
							x -= z;
							ttt[i] = z;
							tt[i] = 0;
						}
					}
				} else {
					for i in (0..26).rev() {
						if tt[i] >= x {
							tt[i] -= x;
							ttt[i] += x;
							break;
						} else {
							let z = tt[i];
							x -= z;
							ttt[i] = z;
							tt[i] = 0;
						}
					}
				}
				a.insert((r+1,rr), (kk,ttt));
			}
			for i in 0..26 {
				t[i] += tt[i];
			}
		}
		a.insert((l,r), (k,t));
	}
	for (_,(k,t)) in a {
		if k == 1 {
			for i in 0..26 {
				rep!{[t[i]]
					write!(rout, "{}", (b'a' + i as u8) as char).ok();
				}
			}
		} else {
			for i in (0..26).rev() {
				rep!{[t[i]]
					write!(rout, "{}", (b'a' + i as u8) as char).ok();
				}
			}
		}
	}
}
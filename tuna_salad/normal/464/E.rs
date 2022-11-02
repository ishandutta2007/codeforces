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

// Field (mod prime) {{{
const P5: i32 = 1_000_000_007;
const P6: i64 = P5 as i64;
#[derive(Debug,Clone,Copy,PartialEq,Eq,PartialOrd,Ord,Default)] struct Field(i32);
#[allow(dead_code)] impl Field {
	fn new<T: Into<i64>>(a: T) -> Self { Self(Self::cv(a)) }
	fn new_unchecked(a: i32) -> Self { Self(a) }
	fn hi(mut a: i32) -> i32 { if a >= P5 { a -= P5; } a }
	fn lo(mut a: i32) -> i32 { if a < 0 { a += P5; } a }
	fn cv<T: Into<i64>>(a: T) -> i32 { Self::lo((a.into() % P6) as i32) }
	fn inv(self) -> Self { self.pow(P5-2) }
	fn pow<T: Into<i64>>(self, b: T) -> Self {
		let b = b.into(); if b == 0 { Self(1) } else {
			let mut res = self.pow(b/2); res *= res; if b % 2 == 1 {res *= self;} res
		}
	}
}
impl Add for Field { type Output = Self; fn add(self, a: Self) -> Self::Output { Self(Self::hi(self.0 + a.0)) }}
impl Sub for Field { type Output = Self; fn sub(self, a: Self) -> Self::Output { Self(Self::lo(self.0 - a.0)) }}
impl Mul for Field { type Output = Self; fn mul(self, a: Self) -> Self::Output { Self(Self::cv(self.0 as i64 * a.0 as i64)) }}
impl Div for Field { type Output = Self; fn div(self, a: Self) -> Self::Output { self * a.inv() }}
impl Neg for Field { type Output = Self; fn neg(self) -> Self::Output { Self(Self::lo(-self.0)) }}
impl AddAssign for Field { fn add_assign(&mut self, a: Self) { *self = *self + a; } }
impl SubAssign for Field { fn sub_assign(&mut self, a: Self) { *self = *self - a; } }
impl MulAssign for Field { fn mul_assign(&mut self, a: Self) { *self = *self * a; } }
impl DivAssign for Field { fn div_assign(&mut self, a: Self) { *self = *self / a; } }
use std::fmt::{Display, Formatter, Result};
impl Display for Field { fn fmt(&self, f: &mut Formatter) -> Result { write!(f, "{}", self.0) } }
impl Sum<Self> for Field { fn sum<I>(i: I) -> Self where I: Iterator<Item = Self> { i.fold(Field(0), |a,b| a + b) } }
impl<'a> Sum<&'a Self> for Field { fn sum<I>(i: I) -> Self where I: Iterator<Item = &'a Self> { i.fold(Field(0), |a,&b| a + b) }}//'
impl Product<Self> for Field { fn product<I>(i: I) -> Self where I: Iterator<Item = Self> { i.fold(Field(1), |a,b| a * b) }}
impl<'a> Product<&'a Self> for Field { fn product<I>(i: I) -> Self where I: Iterator<Item = &'a Self> { i.fold(Field(1), |a,&b| a * b) }}//'
//}}}

struct Node {
	ch: Option<(usize,usize)>,
	len: usize,
	next0: usize,
	h: Field,
}
struct PST {
	nodes: Vec<Node>,
	pow2: Vec<Field>,
	sz: usize,
	r0: usize,
	n1: usize
}
#[allow(dead_code)]
impl PST {
	fn combine(&mut self, lc: usize, rc: usize) -> usize {
		let pst = &self.nodes;
		let ret = pst.len();
		let ch = Some((lc, rc));
		let len = pst[lc].len + pst[rc].len;
		let next0 = if pst[lc].next0 < pst[lc].len {
			pst[lc].next0
		} else {
			pst[lc].len + pst[rc].next0
		};
		let h = pst[lc].h + self.pow2[pst[lc].len] * pst[rc].h;
		self.nodes.push(Node {ch, len, next0, h});
		ret
	}
	fn new(sz: usize) -> (Self,usize) {
		let mut pow2 = Vec::with_capacity(sz+1);
		let mut a = Field(1);
		rep!{[sz+1]
			pow2.push(a);
			a *= Field(2);
		};
		let mut pst = Self {nodes: Vec::new(), pow2, sz, n1: 0, r0: 0};
		let n0 = pst.build(0, sz-1);
		pst.r0 = n0;
		pst.n1 = n0 + 1;
		let h = pst.pow2[0];
		pst.nodes.push(Node {ch: None, len: 1, next0: 1, h});
		assert!(pst.nodes.len() == pst.n1 + 1);
		(pst, n0)
	}
	fn build(&mut self, l: usize, r: usize) -> usize {
		if l < r {
			let m = (l+r) / 2;
			let lc = self.build(l, m);
			let rc = self.build(m+1, r);
			self.combine(lc, rc)
		} else {
			let ret = self.nodes.len();
			self.nodes.push(Node {ch: None, len: 1, next0: 0, h: Field(0)});
			ret
		}
	}
	fn find_next0(&self, id: usize, l: usize, r: usize, w: usize) -> usize {
		if r < w {
			return w;
		}
		if l >= w {
			return l + self.nodes[id].next0;
		}
		let m = (l+r) / 2;
		let (lc,rc) = self.nodes[id].ch.unwrap();
		let a = self.find_next0(lc, l, m, w);
		if a <= m {
			a
		} else {
			self.find_next0(rc, m+1, r, w)
		}
	}
	fn add_carry(&mut self, id: usize, id0: usize, l: usize, r: usize, al: usize, ar: usize) -> usize {
		if r < al || ar < l {
			id
		} else if al <= l && r < ar {
			id0
		} else if l == r {
			assert!(r == ar);
			self.n1
		} else {
			let (lc1, rc1) = self.nodes[id].ch.unwrap();
			let (lc0, rc0) = self.nodes[id0].ch.unwrap();
			let m = (l+r) / 2;
			let lc = self.add_carry(lc1, lc0, l, m, al, ar);
			let rc = self.add_carry(rc1, rc0, m+1, r, al, ar);
			self.combine(lc, rc)
		}
	}
	fn add(&mut self, id: usize, w: usize) -> usize {
		let rr = self.sz - 1;
		let r0 = self.r0;
		let p = self.find_next0(id, 0, rr, w);
		self.add_carry(id, r0, 0, rr, w, p)
	}
	fn cmp(&self, id1: usize, id2: usize) -> Ordering {
		let s1 = &self.nodes[id1];
		let s2 = &self.nodes[id2];
		if s1.h == s2.h {
			Ordering::Equal
		} else if s1.len == 1 {
			s1.next0.cmp(&s2.next0)
		} else {
			let (lc1,rc1) = s1.ch.unwrap();
			let (lc2,rc2) = s2.ch.unwrap();
			let x = self.cmp(rc1, rc2);
			if let Ordering::Equal = x {
				self.cmp(lc1, lc2)
			} else {
				x
			}
		}
	}
}

const B: usize = 100100;
static mut ZZ: *mut PST = 0 as *mut PST;
fn ref_z() -> &'static PST {//'
	unsafe {&*ZZ}
}
struct Z(usize);
impl PartialEq for Z {
	fn eq(&self, other: &Self) -> bool {
		let t = ref_z();
		if let Ordering::Equal = t.cmp(self.0, other.0) {
			true
		} else {
			false
		}
	}
}
impl Eq for Z {}
impl PartialOrd for Z {
	fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
		let t = ref_z();
		Some(t.cmp(other.0, self.0))
	}
}
impl Ord for Z {
	fn cmp(&self, other: &Self) -> Ordering {
		self.partial_cmp(other).unwrap()
	}
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let n = rin.u();
	let mut e = vec![Vec::new(); n];
	rep!{[rin.u()]
		l!(a,b = rin.u()-1);
		let c = rin.u();
		e[a].push((b,c));
		e[b].push((a,c));
	};
	l!(s,t = rin.u()-1);

	let mut dist = Vec::with_capacity(n+1);
	let (mut pst, n0) = PST::new(B);
	unsafe {
		ZZ = &mut pst as *mut _;
	}
	let n_inf = pst.add(n0, B-2);
	dist.push(n0);
	rep!{[n] dist.push(n_inf); };
	let mut q = BinaryHeap::new();
	let mut vis = vec![false; n];
	let mut from = vec![n; n];
	q.push((Z(n0), s, n));
	while let Some((Z(id),u,par)) = q.pop() {
		if !m!(>, vis[u], true) { continue; }
		dist[u] = id;
		from[u] = par;
		for &(v,w) in e[u].iter() {
			if !vis[v] {
				let x = pst.add(id, w);
				q.push((Z(x),v,u));
			}
		}
	}
	if let Ordering::Equal = pst.cmp(n_inf, dist[t]) {
		writeln!(rout, "-1").ok();
	} else {
		writeln!(rout, "{}", pst.nodes[dist[t]].h).ok();
		let mut path = vec![t];
		let mut u = t;
		while u != s {
			u = from[u];
			path.push(u);
		}
		path.reverse();
		writeln!(rout, "{}", path.len()).ok();
		for u in path {
			write!(rout, "{} ", u+1).ok();
		}
	}
}
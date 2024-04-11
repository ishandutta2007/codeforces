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

// Field (mod prime) {{{
mod field {
	use std::ops::*;
	pub const Z0: Field = Field(0);
	pub const Z1: Field = Field(1);
	const P5: i32 = 1_000_000_007;
	const P6: i64 = P5 as i64;
	#[derive(Debug,Clone,Copy,PartialEq,Eq,PartialOrd,Ord,Default)] pub struct Field(pub i32);
	#[allow(dead_code)] impl Field {
		pub fn new<T: Into<i64>>(a: T) -> Self { Self(Self::cv(a)) }
		pub fn new_unchecked(a: i32) -> Self { Self(a) }
		fn hi(mut a: i32) -> i32 { if a >= P5 { a -= P5; } a }
		fn lo(mut a: i32) -> i32 { if a < 0 { a += P5; } a }
		fn cv<T: Into<i64>>(a: T) -> i32 { Self::lo((a.into() % P6) as i32) }
		pub fn inv(self) -> Self { self.pow(P5-2) }
		pub fn pow<T: Into<i64>>(self, b: T) -> Self {
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
}
#[allow(unused_imports)] use field::{Field, Field as Z, Z0, Z1};
//}}}

// Persistent Segtree
#[allow(dead_code)]
mod persistent_segtree {
	// Persistent segtree {{{
	use crate::field::{Field as Z, Z1};
	pub type Val = Z;
	#[derive(Debug,Clone,Copy)]
	pub struct Node {
		val: Val,
		lc: Option<usize>,
		rc: Option<usize>
	}
	impl Node {
		fn new(val: Val) -> Self {
			Self {val, lc: None, rc: None}
		}
		fn combine(a: &Node, b: &Node) -> Self {
			Self::new(Self::combine_val(a.val, b.val))
		}
		fn combine_val(x: Val, y: Val) -> Val {
			x * y
		}
		fn def_val() -> Val {
			Z1
		}
	}
	pub struct Tree {
		nodes: Vec<Node>,
		root: usize,
		n: usize
	}
	impl Tree {
		pub fn from_leaves(leaves: &Vec<Val>) -> Self {
			let mut t = Self {nodes: Vec::new(), root: 0, n: 0};
			t.n = leaves.len();
			t.root = t.build0(leaves, 0, t.n - 1);
			t
		}
		pub fn new(n: usize) -> Self {
			Self::from_leaves(&vec![Z1;n])
		}
		fn build0(&mut self, leaves: &Vec<Val>, l: usize, r: usize) -> usize {
			if l == r {
				self.nodes.push(Node::new(leaves[l]));
			} else {
				let m = (l+r)/2;
				let nl = self.build0(leaves, l, m);
				let nr = self.build0(leaves, m+1, r);
				self.combine_nodes(nl, nr);
			}
			self.nodes.len() - 1
		}
		fn combine_nodes(&mut self, nl: usize, nr: usize) -> usize {
			let id = self.nodes.len();
			self.nodes.push(Node::combine(&self.nodes[nl], &self.nodes[nr]));
			let t = &mut self.nodes[id];
			t.lc.replace(nl);
			t.rc.replace(nr);
			id
		}
		pub fn get_root(&self) -> usize {
			self.root
		}
		pub fn query(&self, start: Option<usize>, ql: usize, qr: usize) -> Val {
			let s = start.unwrap_or(self.root);
			self.query0(s, 0, self.n-1, ql, qr)
		}
		fn query0(&self, id: usize, l: usize, r: usize, ql: usize, qr: usize) -> Val {
			if qr < l || r < ql { return Node::def_val() }
			if ql <= l && r <= qr { return self.nodes[id].val }
			let m = (l+r)/2;
			let info = self.nodes[id];
			let vl = self.query0(info.lc.unwrap(), l, m, ql, qr);
			let vr = self.query0(info.rc.unwrap(), m+1, r, ql, qr);
			Node::combine_val(vl, vr)
		}
		pub fn update(&mut self, root: usize, a: &[(usize,Val)]) -> usize {
			self.root = self.update0(root, 0, self.n-1, a);
			self.root
		}
		fn update0(&mut self, id: usize, l: usize, r: usize, a: &[(usize,Val)]) -> usize {
			// println!("update0  id {}  lr {} {}  a {:?}", id, l, r, a);
			assert!(l <= r);
			let an = a.len();
			if an == 0 || r < a[0].0 || a[an-1].0 < l {
				id
			} else {
				if l == r {
					let val = self.nodes[id].val * a[0].1;
					self.nodes.push(Node::new(val));
				} else {
					let info = self.nodes[id];
					let m = (l+r)/2;
					let mut i = 0;
					while i < an && a[i].0 <= m {
						i += 1;
					}
					let nl = self.update0(info.lc.unwrap(), l, m, &a[..i]);
					let nr = self.update0(info.rc.unwrap(), m+1, r, &a[i..]);
					self.combine_nodes(nl, nr);
				}
				self.nodes.len() - 1
			}
		}
	}//}}}
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();
	const A: usize = 200000;

	let n = rin.u();
	let a = rin.vu(n);
	let inv = {
		let mut inv = v!([A+1]);
		inv.push(Z0);
		for i in 1..=A {
			inv.push(Z::new(i as i32).inv());
		}
		inv
	};
	let mut pos = v!([A+1] = 0);
	let mut pst = persistent_segtree::Tree::new(n);
	let mut roots = v!([n+1] = 0);
	roots[n] = pst.get_root();
	for i in (0..n).rev() {
		let mut x = a[i];
		let mut p = v!([]);
		for j in 2.. {
			if j * j > x {
				break;
			}
			let mut c = 1;
			while x % j == 0 {
				c *= j;
				x /= j;
				if pos[c] > 0 {
					p.push( (pos[c],j) );
				}
				pos[c] = i;
			}
		}
		if x > 1 {
			if pos[x] > 0 {
				p.push( (pos[x],x) );
			}
			pos[x] = i;
		}
		p.sort();
		let m = p.len();
		let mut div = v!([m+1]);
		div.push( (i,Z::new(a[i] as i32)) );
		let mut j = 0;
		while j < m {
			let mut k = j+1;
			let mut c = p[j].1;
			while k < m && p[j].0 == p[k].0 {
				c *= p[k].1;
				k += 1;
			}
			div.push( (p[j].0,inv[c]) );
			j = k;
		}
		roots[i] = pst.update(roots[i+1], &div);
	}
	let mut last = 0;
	rep!{[rin.u()]
		l!(l,r = (last + rin.u()) % n);
		let (l,r) = (l.min(r), l.max(r));
		let res = pst.query(Some(roots[l]), 0, r);
		writeln!(rout, "{}", res).ok();
		last = res.0 as usize;
	}
}
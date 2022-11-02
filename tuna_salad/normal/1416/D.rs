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

// Simple DSU {{{
struct DSU {
	n: usize,
	par: Vec<usize>
}
#[allow(dead_code)]impl DSU {
	fn new(n: usize) -> Self { let mut d = Self {n:0, par:Vec::new()}; d.resize(n); d }
	fn resize(&mut self, n: usize) { self.n = n; self.par.resize(n, 0); self.reset(); }
	fn reset(&mut self) { for i in 0..self.n { self.par[i] = i; } }
	fn find(&mut self, a: usize) -> usize {
		if a != self.par[a] { self.par[a] = self.find(self.par[a]); } self.par[a] }
	fn union(&mut self, mut a: usize, mut b: usize) -> bool {
		a = self.find(a); b = self.find(b); if a != b { self.par[a] = b; true } else { false } }
}//}}}
// Simple Segtree {{{
mod simple_full_segtree {
	pub type V = (i32,usize);
	pub type U = V;
	pub type R = V;
	#[derive(Clone)]
	pub struct Val {
		val: V
	}
	impl Val {
		pub fn default() -> Self {
			Self::new((0,0))
		}
		pub fn new(v: V) -> Self {
			Self {val: v}
		}
		pub fn combine(a: &Self, b: &Self) -> Self {
			Self::new(a.val.max(b.val))
		}
		pub fn update(&mut self, u: U) {
			self.val = u;
		}
		pub fn result(&self) -> R {
			self.val
		}
	}
	pub struct Tree {
		n: usize,
		base: usize,
		values: Box<[Val]>
	}
	#[allow(dead_code)]
	impl Tree {
		pub fn new(init: &[V]) -> Self {
			let n = init.len();
			let mut base = 1;
			while base < n {
				base <<= 1;
			}
			let mut values = vec![Val::default(); base*2];
			for i in 0..n {
				values[base + i] = Val::new(init[i]);
			}
			for i in (1..base).rev() {
				values[i] = Val::combine(&values[i+i], &values[i+i+1]);
			}
			let values = values.into_boxed_slice();
			Self {n, base, values}
		}
		pub fn update(&mut self, p: usize, u: U) {
			assert!(p < self.n);
			let mut p = p + self.base;
			self.values[p].update(u);
			p >>= 1;
			while p > 0 {
				self.values[p] = Val::combine(&self.values[p+p], &self.values[p+p+1]);
				p >>= 1;
			}
		}
		fn query_sub(&self, ql: usize, qr: usize, l: usize, r: usize, id: usize, val: &mut Val) {
			if r < ql || qr < l { return; }
			if ql <= l && r <= qr {
				*val = Val::combine(val, &self.values[id]);
			} else if ql <= r && l <= qr {
				let m = (l+r) >> 1;
				self.query_sub(ql, qr, l, m, id+id, val);
				self.query_sub(ql, qr, m+1, r, id+id+1, val);
			}
		}
		pub fn query(&self, ql: usize, qr: usize) -> Val {
			assert!(ql <= qr && qr < self.n);
			let mut res = Val::default();
			self.query_sub(ql, qr, 0, self.base-1, 1, &mut res);
			res
		}
		pub fn query_all(&self) -> Val {
			self.values[1].clone()
		}
	}
}//}}}

fn dfs(u: usize, e: &[Vec<usize>], dfst: &mut [(usize,usize)], t: &mut usize) {
	dfst[u].0 = *t;
	*t += 1;
	for &v in e[u].iter() {
		assert!(dfst[v] == (1,0));
		dfs(v, e, dfst, t);
	}
	dfst[u].1 = *t-1;
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,m,q = rin.u());
	let p = rin.vi(n);
	let mut el = v!([m]);
	let mut e = v!([n][]);
	for i in 0..m {
		l!(a,b = rin.u()-1);
		el.push( (a,b,q) );
		e[a].push( (b,i) );
		e[b].push( (a,i) );
	}
	let mut qq = v!([q]);
	for i in 0..q {
		let t = rin.u();
		let x = rin.u()-1;
		qq.push( (t,x) );
		if t == 2 {
			el[x].2 = i;
		}
	}
	let mut dsu = DSU::new(n*2);
	for i in 0..m {
		let (a,b,t) = el[i];
		if t == q {
			dsu.union(a,b);
		}
	}
	let mut heads = v!([n*2] = 0);
	let mut de = v!([n*2][]);
	for u in 0..n {
		let v = dsu.find(u);
		if v != u {
			de[v].push(u);
		} else {
			heads[u] = u;
		}
	}
	let mut nn = n;
	let mut qt = v!([q] = None);
	for i in (0..q).rev() {
		let (t,x) = qq[i];
		if t == 2 {
			let (a,b,_) = el[x];
			let aa = heads[dsu.find(a)];
			let bb = heads[dsu.find(b)];
			if aa != bb {
				dsu.union(a,b);
				dsu.union(a,nn);
				heads[dsu.find(a)] = nn;
				de[nn].push(aa);
				de[nn].push(bb);
				qt[i].replace(nn);
				nn += 1;
			}
		}
	}
	let mut dfst = v!([n*2] = (1,0));
	let mut t = 0;
	for i in (0..nn).rev() {
		if dfst[i] == (1,0) {
			dfs(i, &de, &mut dfst, &mut t);
		}
	}
	let mut intervals = BTreeSet::new();
	for i in 0..nn {
		if i == heads[dsu.find(i)] {
			let (s,e) = dfst[i];
			intervals.insert( (e,s) );
		}
	}
	let mut z = v!([nn] = (0,0));
	for i in 0..n {
		z[dfst[i].0] = (p[i],i);
	}
	// writeln!(rout, "z : {:?}", z).ok();
	// for i in 0..nn {
	// 	writeln!(rout, "{} : {:?}", i, dfst[i]).ok();
	// }
	// writeln!(rout, "intervals : {:?}", intervals).ok();
	use std::ops::Bound::*;
	let mut st = simple_full_segtree::Tree::new(&z);
	for i in 0..q {
		let (t,x) = qq[i];
		if t == 1 {
			let (r,l) = *intervals.range((Included( (dfst[x].0,0) ),Unbounded)).next().unwrap();
			let (v,pos) = st.query(l,r).result();
			// writeln!(rout, "query {} {} : {} {}", l, r, v, pos).ok();
			if v > 0 {
				st.update(dfst[pos].0, (0,0));
			}
			writeln!(rout, "{}", v).ok();
		} else if let Some(id) = qt[i] {
			assert!(de[id].len() == 2);
			let a = de[id][0];
			let b = de[id][1];
			intervals.remove( &(dfst[id].1,dfst[id].0) );
			intervals.insert( (dfst[a].1,dfst[a].0) );
			intervals.insert( (dfst[b].1,dfst[b].0) );
		}
	}
}
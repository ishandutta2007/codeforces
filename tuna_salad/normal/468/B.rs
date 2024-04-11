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

// DSU with sizes {{{
struct DSU {
	n: usize,
	par: Vec<usize>,
	sz: Vec<usize>
}
#[allow(dead_code)]impl DSU {
	fn new(n: usize) -> Self { let mut d = Self {n:0, par:Vec::new(), sz:Vec::new()}; d.resize(n); d }
	fn resize(&mut self, n: usize) { self.n = n; self.par.resize(n, 0); self.sz.resize(n, 1); self.reset(); }
	fn reset(&mut self) { for i in 0..self.n { self.par[i] = i; self.sz[i] = 1; } }
	fn find(&mut self, a: usize) -> usize {
		if a != self.par[a] { self.par[a] = self.find(self.par[a]); } self.par[a] }
	fn union(&mut self, mut a: usize, mut b: usize) -> bool {
		a = self.find(a); b = self.find(b); if a != b { self.par[a] = b; self.sz[b] += self.sz[a]; true } else { false } }
}//}}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let n = rin.u();
	l!(a,b = rin.i());
	let mut p = Vec::with_capacity(n);
	let mut h = HashMap::new();
	for i in 0..n {
		let x = rin.i();
		p.push(x);
		h.insert(x, i);
	}
	if a == b {
		let mut i = 0;
		let mut j = n-1;
		let mut ok = true;
		p.sort();
		loop {
			if p[i] + p[j] != a {
				ok = false;
				break;
			}
			if i == j || i+1 == j {
				break;
			}
			i += 1;
			j -= 1;
		}
		if ok {
			writeln!(rout, "YES").ok();
			rep!{[n]
				write!(rout, "0 ").ok();
			};
			writeln!(rout, "").ok();
		} else {
			writeln!(rout, "NO").ok();
		}
		return;
	}

	let h = h;
	let mut e = vec![[None,None]; n];
	let mut dsu = DSU::new(n);
	for (i,&x) in p.iter().enumerate() {
		for (j,y) in vec![(0,a),(1,b)] {
			if x < y {
				if let Some(&k) = h.get(&(y-x)) {
					e[i][j].replace(k);
					dsu.union(i,k);
				}
			}
		}
	}
	let mut g_heads = vec![Vec::new(); n];
	for i in 0..n {
		l!(mut has_self_loop,is_end = false);
		for j in 0..2 {
			let k = e[i][j].unwrap_or(n);
			if k == i {
				has_self_loop = true;
				is_end = true;
			} else if k == n {
				is_end = true;
			}
		}
		if is_end {
			let s = dsu.find(i);
			g_heads[s].push( (i,has_self_loop) );
		}
	}
	for i in 0..n {
		if i != dsu.par[i] { continue; }
		if dsu.sz[i] % 2 == 1 && g_heads[i].iter().all(|&(_,sl)| !sl) {
			writeln!(rout, "NO").ok();
			return;
		}
	}
	let mut vis = vec![false; n];
	let mut sol = vec![2; n];
	for s in 0..n {
		if dsu.par[s] != s { continue; }
		let start = if dsu.sz[s] % 2 == 0 || !g_heads[s][0].1 {
			g_heads[s][0].0
		} else {
			g_heads[s].last().unwrap().0
		};
		let mut u = start;
		let mut path = Vec::new();
		while !vis[u] {
			vis[u] = true;
			path.push(u);
			for j in 0..2 {
				let v = e[u][j].unwrap_or(u);
				if v != u && !vis[v] {
					u = v;
					break;
				}
			}
		}
		assert!(path.len() == dsu.sz[s]);
		path.reverse();
		while path.len() > 1 {
			let u = path.pop().unwrap();
			let v = path.pop().unwrap();
			let z = if p[u] + p[v] == a {0} else {1};
			sol[u] = z;
			sol[v] = z;
		}
		if let Some(u) = path.pop() {
			sol[u] = if p[u] * 2 == a {0} else {1};
		}
	}
	writeln!(rout, "YES").ok();
	for s in sol {
		write!(rout, "{} ", s).ok();
	}
}
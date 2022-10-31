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

// Online LCA on Unweighted Tree
#[allow(dead_code)]
mod lca {
	// Online LCA {{{
	pub struct TreeOnline {
		n: usize,
		nk: usize,
		up: Vec<Vec<usize>>,
		dep: Vec<usize>
	}
	impl TreeOnline {
		pub fn from_edge_list(l: &[(usize,usize)], root: Option<usize>) -> Self {
			let n = l.len() + 1;
			let mut e = vec![Vec::new(); n];
			for &(a,b) in l.iter() {
				e[a].push(b);
				e[b].push(a);
			}
			Self::from_adj_list(e,root)
		}
		pub fn from_adj_list(e: Vec<Vec<usize>>, root: Option<usize>) -> Self {
			let n = e.len();
			let nk = n.next_power_of_two().trailing_zeros() as usize + 1;
			let mut dep = vec![n; n];
			let mut up = vec![vec![0; n]; nk];
			let mut st = Vec::new();
			let root = root.unwrap_or(0);
			dep[root] = 0;
			up[0][root] = root;
			st.push(root);
			while let Some(u) = st.pop() {
				for &v in e[u].iter() {
					if dep[v] == n {
						dep[v] = dep[u] + 1;
						up[0][v] = u;
						st.push(v);
					}
				}
			}
			assert!(dep.iter().all(|&a| a < n), "tree not connected");
			for k in 1..nk {
				for i in 0..n {
					up[k][i] = up[k-1][up[k-1][i]];
				}
			}
			Self {n, nk, up, dep}
		}
		pub fn lca(&self, mut a: usize, mut b: usize) -> usize {
			if self.dep[a] < self.dep[b] {
				std::mem::swap(&mut a, &mut b);
			}
			let dd = self.dep[a] - self.dep[b];
			for i in 0..self.nk {
				if (dd & (1<<i)) > 0 {
					a = self.up[i][a];
				}
			}
			for i in (0..self.nk).rev() {
				let x = self.up[i][a];
				let y = self.up[i][b];
				if x != y {
					a = x;
					b = y;
				}
			}
			if a == b {a} else {self.up[0][a]}
		}
		pub fn dist(&self, a: usize, b: usize) -> usize {
			self.dep[a] + self.dep[b] - 2*self.dep[self.lca(a,b)]
		}
		pub fn go_up(&self, mut a: usize, k: usize) -> usize {
			for i in 0..self.nk {
				if (k & (1<<i)) > 0 {
					a = self.up[i][a];
				}
			}
			a
		}
		pub fn par(&self, a: usize) -> usize { self.up[0][a] }
	}//}}}
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let n = rin.u();
	let mut e = v!([n][]);
	rep!{[n-1]
		l!(a,b = rin.u()-1);
		e[a].push(b);
		e[b].push(a);
	}
	let lca = lca::TreeOnline::from_adj_list(e, None);
	rep!{[rin.u()]
		l!(x,y,a,b = rin.u()-1);
		let k = rin.u();
		let mut res = false;
		let mut f = |d: usize| {
			if d <= k && (d ^ k) % 2 == 0 {
				res = true;
			}
		};
		f(lca.dist(a,b));
		for (x,y) in vec![(x,y),(y,x)] {
			f(lca.dist(a,x) + 1 + lca.dist(b,y));
		}
		drop(f);

		if res {
			writeln!(rout, "YES").ok();
		} else {
			writeln!(rout, "NO").ok();
		}
	}
}
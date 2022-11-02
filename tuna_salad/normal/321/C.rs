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
#[allow(unused_macros)] macro_rules! vec_dim {
	([$d:expr]$($s:tt)+) => {vec![vec_dim!($($s)+);$d]}; (=$e:expr) => {$e};
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

fn dfs(u: usize, depth: i32, e: &[Vec<usize>], vis: &mut [i32], sz: &mut [usize], nodes: &mut Vec<usize>) {
	vis[u] = depth;
	sz[u] = 1;
	nodes.push(u);
	for &v in e[u].iter() {
		if vis[v] != -1 && vis[v] != depth {
			dfs(v, depth, e, vis, sz, nodes);
			sz[u] += sz[v];
		}
	}
}
fn centroid_decom(e: &[Vec<usize>]) -> Vec<u8> {
	let n = e.len();
	l!(mut vis,sz = vec_dim!([n] = 0));
	let mut res = vec_dim!([n] = b'?');
	let mut nodes = Vec::with_capacity(n);
	for depth in 1.. {
		let mut found = false;
		for u in 0..n {
			if vis[u] != -1 && vis[u] != depth {
				found = true;
				dfs(u, depth, e, &mut vis, &mut sz, &mut nodes);
				let s = sz[u];
				let mut sz_min = n;
				let mut id = u;
				for u in nodes.drain(..) {
					let mut sz_max = 0;
					for &v in e[u].iter() {
						if vis[v] != -1 {
							let sz1 = if sz[v] > sz[u] {s - sz[u]} else {sz[v]};
							m!(>, sz_max, sz1);
						}
					}
					if m!(<, sz_min, sz_max) {
						id = u;
					}
				}
				res[id] = b'A' + depth as u8 - 1;
				vis[id] = -1;
			}
		}
		if !found {
			break;
		}
	}
	res
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	let n = rin.u();
	let mut e = vec_dim!([n] = Vec::new());
	rep!{[n-1]
		l!(a,b = rin.u()-1);
		e[a].push(b);
		e[b].push(a);
	}
	let sol = centroid_decom(&e);
	for s in sol {
		write!(rout, "{} ", s as char).ok();
	}
}
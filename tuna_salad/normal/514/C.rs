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

// Trie {{{
#[allow(dead_code)]
mod trie {
	pub type Mark = bool;
	const MARK_DEF: Mark = false;
	pub type Val = ();
	const VAL_DEF: () = ();
	const NEXT_SIZE: usize = 3;
	#[derive(Clone)]
	pub struct Node {
		pub mark: Mark,
		pub val: Val,
		next: Box<[Option<Node>]>
	}
	impl Node {
		pub fn default() -> Self {
			let next = vec![None; NEXT_SIZE].into_boxed_slice();
			Self {mark: MARK_DEF, val: VAL_DEF, next}
		}
		pub fn new(mark: Mark, val: Val) -> Self {
			let mut res = Self::default();
			res.mark = mark;
			res.val = val;
			res
		}
		pub fn go(&self, p: usize) -> Option<&Self> {
			self.next[p].as_ref()
		}
		pub fn go_mut(&mut self, p: usize) -> Option<&mut Self> {
			self.next[p].as_mut()
		}
		pub fn go_new(&mut self, p: usize) -> &mut Self {
			if self.next[p].is_none() {
				self.next[p].replace(Self::default());
			}
			self.go_mut(p).unwrap()
		}
	}
	pub struct Trie {
		pub root: Node
	}
	impl Trie {
		pub fn new() -> Self {
			Self {root: Node::default()}
		}
		pub fn insert_word(&mut self, word: &[usize], mark: Mark, val: Val) {
			let mut n = &mut self.root;
			for &w in word.iter() {
				// let t = unsafe{&mut * (n as *mut Node)};
				// n = t.go_new(w);
				n = n.go_new(w);
			}
			n.mark = mark;
			n.val = val;
		}
		fn find0(n: &Node, word: &[usize], pos: usize, diff: bool) -> bool {
			if pos == word.len() {
				return diff;
			}
			if let Some(t) = n.go(word[pos]) {
				if Self::find0(t, word, pos+1, diff) {
					return true;
				}
			}
			if !diff {
				for c in 0..3 {
					if c != word[pos] {
						if let Some(t) = n.go(c) {
							if Self::find0(t, word, pos+1, true) {
								return true;
							}
						}
					}
				}
			}
			false
		}
		pub fn find1(&self, word: &[usize]) -> bool {
			Self::find0(&self.root, word, 0, false)
		}
	}
}//}}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,m = rin.u());
	let mut t = trie::Trie::new();
	for i in 0..n+m {
		let s: Vec<usize> = rin.vb().into_iter().map(|x| (x - b'a') as usize).collect();
		if i < n {
			t.insert_word(&s,true,());
		} else {
			if t.find1(&s) {
				writeln!(rout, "YES").ok();
			} else {
				writeln!(rout, "NO").ok();
			}
		}
	};
}
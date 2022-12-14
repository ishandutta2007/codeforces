use std::io::{self, prelude::*};

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
	let num_node: usize=input.token();
	let num_edge: usize=input.token();
	let mut add=vec![Vec::<usize>::new(); num_node];
	for _ in 0..num_edge{
		let mut u: usize=input.token();
		let mut v: usize=input.token();
		u-=1; v-=1;
		add[u].push(v); add[v].push(u);
	}

	let desired: Vec<usize>=(0..num_node).map(|_| {
		let x: usize=input.token();
		x-1
	}).collect();
	for node in 0..num_node{
		let mut desired_adjacent=add[node].iter().map(|&other| desired[other]).collect::<Vec<_>>();
		desired_adjacent.sort();
		desired_adjacent.dedup();
		let mex=desired_adjacent.iter().enumerate().find(|&(index, &value)| index!=value)
			.unwrap_or((desired_adjacent.len(), &0)).0;
		if mex!=desired[node]{
			write!(w, "-1\n").unwrap();
			return;
		}
	}
	let mut result=desired.iter().enumerate().collect::<Vec<_>>();
	result.sort_by_key(|&(_node, desired_topic)| desired_topic);
	for (node, _desired_topic) in &result{
		write!(w, "{} ", node+1).unwrap();
	}
	write!(w, "\n").unwrap();
}

fn main() {
	let stdin = io::stdin();
	let stdout = io::stdout();
	let input = FastInput::from(stdin.lock());
	let writer = io::BufWriter::new(stdout.lock());
	solve(input, writer);
}

trait TokenStream<T> {
	fn token(&mut self) -> T;
}

struct FastInput<R> {
	stdin: R,
	pos: usize,
}

impl<R: BufRead> From<R> for FastInput<R> {
	fn from(r: R) -> Self {
		FastInput { stdin: r, pos: 0 }
	}
}

impl<R: BufRead> TokenStream<u8> for FastInput<R> {
	fn token(&mut self) -> u8 {
		loop {
			if let Ok(buf) = self.stdin.fill_buf() {
				while self.pos < buf.len() {
					self.pos += 1;
					if buf[self.pos - 1] > 32 {
						return buf[self.pos - 1];
					}
				}
				if self.pos == 0 {
					return 0;
				}
			} else {
				return 0;
			}
			self.stdin.consume(self.pos);
			self.pos = 0;
		}
	}
}

impl<R: BufRead> TokenStream<Vec<u8>> for FastInput<R> {
	fn token(&mut self) -> Vec<u8> {
		let mut ans = Vec::new();
		let mut parse_token = false;
		loop {
			if let Ok(buf) = self.stdin.fill_buf() {
				if !parse_token {
					while self.pos < buf.len() && buf[self.pos] <= 32 {
						self.pos += 1;
					}
				}
				while self.pos < buf.len() && buf[self.pos] > 32 {
					parse_token = true;
					ans.push(buf[self.pos]);
					self.pos += 1;
				}
				if self.pos != buf.len() || self.pos == 0 {
					return ans;
				}
			}
			self.stdin.consume(self.pos);
			self.pos = 0;
		}
	}
}

macro_rules! impl_token_stream_u {
	($($t:ident),+) => {$(
		impl<R: BufRead> TokenStream<$t> for FastInput<R> {
			fn token(&mut self) -> $t {
				let mut ans = 0;
				let mut parse_token = false;
				loop {
					if let Ok(buf) = self.stdin.fill_buf() {
						if !parse_token {
							while self.pos < buf.len() && buf[self.pos] <= 32 {
								self.pos += 1;
							}
						}
						while self.pos < buf.len() && buf[self.pos] > 32 {
							parse_token = true;
							ans = ans * 10 + (buf[self.pos] - b'0') as $t;
							self.pos += 1;
						}
						if self.pos != buf.len() || self.pos == 0 {
							return ans;
						}
					}
					self.stdin.consume(self.pos);
					self.pos = 0;
				}
			}
		}
	)+}
}
macro_rules! impl_token_stream_i {
	($($t:ident),+) => {$(
		impl<R: BufRead> TokenStream<$t> for FastInput<R> {
			fn token(&mut self) -> $t {
				let mut ans = 0;
				let mut minus = false;
				let mut parse_token = false;
				loop {
					if let Ok(buf) = self.stdin.fill_buf() {
						if !parse_token {
							while self.pos < buf.len() && buf[self.pos] <= 32 {
								self.pos += 1;
							}
						}
						while self.pos < buf.len() && buf[self.pos] > 32 {
							parse_token = true;
							if buf[self.pos] == b'-' {
								minus = true;
							} else {
								ans = ans * 10 + (buf[self.pos] - b'0') as $t;
							}
							self.pos += 1;
						}
						if self.pos != buf.len() || self.pos == 0 {
							return if minus { -ans } else { ans };
						}
					}
					self.stdin.consume(self.pos);
					self.pos = 0;
				}
			}
		}
	)+}
}

impl_token_stream_u!(usize);
impl_token_stream_i!(i32);
impl_token_stream_i!(i64);
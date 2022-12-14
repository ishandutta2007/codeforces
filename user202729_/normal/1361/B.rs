// oops misread the value limit (seriously? again?...)

use std::io::{self, prelude::*};

const MOD: u32=1000000007;

#[derive(Copy, Clone)]
struct Number{
	value: u32,
	huge: bool
}

impl std::ops::Mul<Number> for Number{
	type Output=Self;
	fn mul(self, other: Self)->Self{
		let tmp=self.value as u64*other.value as u64;
		return Self{value: (tmp%MOD as u64) as u32, huge: tmp>=MOD as u64||self.huge||other.huge};
	}
}

impl Number{
	fn pow(self, mut exponent: u32)->Self{
		let mut base=self;
		let mut result=Number{value: 1, huge: false};
		loop{
			if (exponent&1)!=0{ result=result*base }
			exponent>>=1;
			if exponent==0{ return result }
			base=base*base
		}
	}
}

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
	let num_test: usize=input.token();
	for _ in 0..num_test{
		let number: usize=input.token();
		let base: u32=input.token();
		let mut k: Vec<u32>=(0..number).map(|_| input.token()).collect();
		if base==1{
			write!(w, "{}\n", number%2).unwrap();
			continue;
		}

		let base=Number{value: base, huge: false};

		k.sort_unstable_by(|x, y| y.cmp(x));
		let mut result=Number{value: 0, huge: false};
		{
			let mut last=0;
			let mut lastk=k[0];
			for i in (1..k.len()).filter(|&i| k[i]!=k[i-1]).chain(std::iter::once(k.len())){
				let (value, count)=(k[i-1], (i-last) as u32);
				last=i;
				debug_assert!(lastk>=value);
				let delta=lastk-value;
				lastk=value;

				if delta!=0&&result.value!=0{
					result=result*base.pow(delta);
				}

				// these `.value` manipulation are ugly...
				// but they saves some huge check.
				if result.huge{
					debug_assert!(count<MOD);
					result.value=result.value+MOD-count;
					if result.value>=MOD{result.value%=MOD;}
				}else{
					if result.value>count{
						result.value-=count;
					}else{
						result.value=(result.value+count)%2;
					}
				}
			}

			result=result*base.pow(lastk);
		}

		write!(w, "{}\n", result.value).unwrap();
	}
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
impl_token_stream_u!(u32);
impl_token_stream_i!(i32);
impl_token_stream_i!(i64);
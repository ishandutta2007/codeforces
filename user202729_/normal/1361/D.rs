// :(
// 4c59d23180f8b417db796661ae93f991212d15915aba76bc110b5f82abf49487



use std::io::{self, prelude::*};
use std::collections::HashMap;
use std::cmp::{Ordering};

fn gcd(a: i32, b: i32)->i32{
	if b==0{a}else{gcd(b, a%b)}
}

#[derive(PartialEq, Eq, Copy, Clone, Hash)]
struct Point(i32, i32);

fn float_compare(a: &f64, b: &f64)->Ordering{
	if let Some(x)=a.partial_cmp(b){
		x
	}else{
		unsafe{std::hint::unreachable_unchecked()}
	}
}

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
	let number: usize=input.token();
	let num_remain: usize=input.token();
	if num_remain<=1{
		write!(w, "0\n").unwrap();
		return;
	}

	let mut points=HashMap::<Point, Vec<f64>>::new();
	for _ in 0..number{
		let x=input.token();
		let y=input.token();
		if x==0&&y==0{continue}
		let g=gcd(x, y).abs();
		points.entry(Point(x/g, y/g)).or_insert_with(|| Vec::new()).push(
			((x as f64).powi(2)+(y as f64).powi(2)).sqrt()
			);
	}

	let chains: Vec<_>=points.into_iter().map(|(_key, mut value)|{
		value.sort_unstable_by(float_compare);
		value
	}).collect();

	let iterator: Option<usize>=chains.iter().position(|chain| chain.len()>=number-num_remain+num_remain/2);
	let longer_chain=iterator!=None&&num_remain!=number;
	let mut data=Vec::<f64>::new();
	let mut longer_chain_result=0f64;

	for (chain_index, chain) in chains.iter().enumerate(){
		for (index, item) in chain.iter().enumerate(){
			let mut num_below=chain.len()-index;

			if longer_chain&& chain_index==iterator.unwrap()&&num_below>num_remain/2{
				let num_blank=number-num_remain;
				if num_below<=num_remain/2+num_blank{
					continue
				}else{
					num_below-=num_blank
				}
			}

			let value=item*(num_remain as f64+1.-num_below as f64*2.);

			if longer_chain{
				longer_chain_result+=value
			}else{
				data.push(value)
			}
		}
	}

	if num_remain==number{
		write!(w, "{:.}\n", data.iter().sum::<f64>()).unwrap();
		return
	}
	if longer_chain{
		write!(w, "{:.}\n", longer_chain_result).unwrap();
		return
	}

	data.sort_unstable_by(float_compare);
	write!(w, "{:.}\n", &data[data.len()-num_remain..].iter().sum::<f64>()).unwrap();
}

fn main() {
	let stdin = io::stdin();
	let stdout = io::stdout();
	let input = FastInput::from(stdin.lock());
	let writer = io::BufWriter::new(stdout.lock());
	solve(input, writer);
}

trait TokenStream<T> {
	fn token1(&mut self) -> T;
}

struct FastInput<R> {
	stdin: R,
	pos: usize,
}

impl<R: BufRead> FastInput<R> {
	fn token<T>(&mut self) -> T where FastInput<R>: TokenStream<T> { self.token1() }
}

impl<R: BufRead> From<R> for FastInput<R> {
	fn from(r: R) -> Self {
		FastInput { stdin: r, pos: 0 }
	}
}

impl<R: BufRead> TokenStream<u8> for FastInput<R> {
	fn token1(&mut self) -> u8 {
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
	fn token1(&mut self) -> Vec<u8> {
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
			fn token1(&mut self) -> $t {
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
			fn token1(&mut self) -> $t {
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
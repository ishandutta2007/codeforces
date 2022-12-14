use std::io::{self, prelude::*};

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
	let number: usize=input.token();
	let mut add=vec![Vec::<usize>::new(); 1000001];
	let primes=(2usize..1001).filter(|&x| (2..x).all(|y| x%y!=0)).collect::<Vec<usize>>();

	for _ in 0..number{
		let mut a: usize=input.token();
		for x in primes.iter().map(|x| x*x){
			while a%x==0{a/=x}
		}

		if a==1{
			write!(w, "1\n").unwrap();
			return;
		}
		let &x=primes.iter().find(|&x| a%x==0).unwrap_or(&a);
		let y=a/x;
		add[x].push(y); add[y].push(x);
	}

	let mut queue=Vec::<usize>::new();
	let mut distance=vec![std::usize::MAX; 1000001];
	let mut parent=vec![std::usize::MAX; 1000001];

	let mut result=std::usize::MAX;
	for &x in std::iter::once(&1usize).chain(&primes) {
		queue.clear();
		queue.push(x); distance[x]=0;
		let mut front=0usize;
		while front!=queue.len(){
			let node=queue[front];
			front+=1;

			let distance_node=distance[node];
			if distance_node*2+1>=result{ continue }

			let mut seen_parent=false;
			for &other in &add[node]{
				if other<x{continue}
				let distance_other=distance[other];
				if distance_other==std::usize::MAX{
					distance[other]=distance_node+1;
					parent[other]=node;
					queue.push(other);
				}else{
					if other!=parent[node]||seen_parent{
						result=std::cmp::min(result, distance_node+distance_other+1);
					}
					if other==parent[node]{
						seen_parent=true;
					}
				}
			}
		}

		for &node in &queue{
			distance[node]=std::usize::MAX;
			parent[node]=std::usize::MAX;
		}
	}


	if result==std::usize::MAX{
		write!(w, "-1\n").unwrap();
	}else{
		write!(w, "{}\n", result).unwrap();
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
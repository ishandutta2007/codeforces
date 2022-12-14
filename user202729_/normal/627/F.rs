// *practice competitive programming, not Rust*

use std::io::{self, prelude::*};
use std::cmp::{min, max};

struct Graph{
	add: Vec<Vec<usize>>,
	start: Vec<usize>,
	target: Vec<usize>,
}
struct WorkResult{
	par: Vec<usize>,
	//depth: Vec<usize>,
}
impl Graph{
	fn work(add: &Vec<Vec<usize>>, result: &mut WorkResult, node: usize, par: usize){
		result.par[node]=par;
		for &other in &add[node]{
			if other!=par{
				Graph::work(add, result, other, node);
			}
		}
	}
}

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
	let number: usize=input.token();
	let mut graph=Graph{add: vec![Vec::<_>::new(); number],
		start: (0..number).map(|_| input.token()).collect(),
		target: (0..number).map(|_| input.token()).collect(),
		};
	for _ in 1..number{
		let first=input.token::<usize>()-1;
		let sec=input.token::<usize>()-1;
		graph.add[first].push(sec);
		graph.add[sec].push(first);
	}

	let mut result=WorkResult{par: vec![0; number]};
	let start_empty=graph.start.iter().position(|&x| x==0).unwrap();
	Graph::work(&graph.add, &mut result, start_empty, std::usize::MAX);
	let par=result.par;

	let target_empty=graph.target.iter().position(|&x| x==0).unwrap();
	let distance={
		let mut cur=target_empty;
		let mut distance=0;
		loop{
			let last=cur;
			cur=par[cur];
			if cur==std::usize::MAX{break}
			debug_assert!(graph.target[last]==0);
			debug_assert!(graph.target[cur]!=0);
			graph.target.swap(cur, last); // rust has way way way too many functions that appears to be only useful in one instance?
			distance+=1;
		}
		distance
	};
	if graph.start==graph.target{
		write!(w, "0 {}\n", distance).unwrap();
		return;
	}

	let indices: Vec<_>=(0..number)
		.filter(|&x| graph.start[x]!=graph.target[x]&&(
				graph.add[x].iter().filter(|&&y| y!=par[x]).all(|&y| graph.start[y]==graph.target[y])
		))
		.collect();
	debug_assert!(!indices.is_empty());
	if indices.len()>=3{
		write!(w, "-1\n").unwrap();
		return;
	}
	let root_path=|x: usize| std::iter::successors(Some(x), |&x| match par[x]{
		std::usize::MAX => None,
		y => Some(y)
	});
	let (a, b)=if indices.len()==1{
		(indices[0], root_path(indices[0])
			.find(|&x| graph.start[x]==graph.target[x])
			.unwrap())
	}else{
		(indices[0], indices[1])
	};

	let root_path_v=|x: usize| root_path(x).collect::<Vec<_>>();

	// >.< (give up writing functional style code and just write "ugly" imperative code)
	let separate_path=|a: usize, b: usize|{
		let mut path1=root_path_v(a);
		let mut path2=root_path_v(b);
		debug_assert!(a!=b);
		while path1.last()==path2.last(){ path1.pop(); path2.pop(); }
		(path1, path2)
	};
	let distance_=|a: usize, b: usize|{
		if a==b{return 0;}
		let (path1, path2)=separate_path(a, b);
		return path1.len()+path2.len();
	};


	let (path1, path2)=separate_path(a, b);


	let path=path1.iter().chain(path2.iter().rev());
	let path_vector: Vec<_>=path.clone().cloned().collect();
	let start_path: Vec<_>=path.clone().map(|&x| graph.start[x]).collect();
	let target_path: Vec<_>=path.map(|&x| graph.target[x]).collect();
	debug_assert!(start_path!=target_path);
	let rotate=target_path.iter().position(|&x| x==start_path[0]).unwrap();
	// v (bad?)
	if target_path[rotate..]!=start_path[..start_path.len()-rotate]||
		target_path[..rotate]!=start_path[start_path.len()-rotate..]{
		write!(w, "-1\n");
		return;
	}

	debug_assert!(rotate!=0);
	
	write!(w, "{} {} {}\n", min(a, b)+1, max(a, b)+1, 
		min(
			distance_(start_empty, a)+1+(distance_(a, b)+1)*(rotate-1)+distance_(b, target_empty),
			distance_(start_empty, b)+1+(distance_(a, b)+1)*(start_path.len()-rotate-1)+distance_(a, target_empty),
		)
	);
	// ^ TODO try swapping `rotate` and `start_path.len()-rotate` here
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
	fn token<T>(&mut self) -> T where FastInput<R>: TokenStream<T> {
		self.token1()
	}
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
impl_token_stream_i!(i32);
impl_token_stream_i!(i64);
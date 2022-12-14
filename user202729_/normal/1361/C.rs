





use std::io::{self, prelude::*};

#[derive(Clone, Copy)]
struct Edge{node: usize, index: usize}

struct Graph{
	add: Vec<Vec<usize>>,
	edges: Vec<Edge>, // complement: ^1
	// deleted: node==std::usize::MAX
}

type Path=Vec<Edge>;

impl Graph{
	fn new(number: usize)->Self{
		Graph{add: vec![vec![]; number], edges: vec![]}
	}

	fn add_edge(&mut self, first: usize, sec: usize, forward_index: usize){
		self.add[first].push(self.edges.len());
		self.edges.push(Edge{node: sec, index: forward_index});
		self.add[sec].push(self.edges.len());
		self.edges.push(Edge{node: first, index: forward_index^1});
	}

	fn find_circuit(&mut self)->Option<Path>{ // will delete all edges
		if self.add.iter().any(|x| x.len()%2!=0){return None}

		let start_node=self.add.iter().enumerate().find(|&(_index, value)| !value.is_empty()).unwrap().0;
		let mut last_node: usize=start_node;
		let mut temp=Vec::<(usize, Edge)>::new();
		let mut result=Path::new();

		let get_edge=|graph: &mut Self, node: usize|->Option<usize>{
			let it=&mut graph.add[node];
			loop{
				if let Some(&last)=it.last(){
					if graph.edges[last].node==std::usize::MAX{
						it.pop();
					}else{
						return Some(last)
					}
				}else{
					return None
				}
			}
		};

		loop{
			if let Some(edge_index)=get_edge(self, last_node){
				// follow that edge, delete it in the graph
				debug_assert!(self.edges[edge_index].node!=std::usize::MAX);
				debug_assert!(self.edges[edge_index^1].node==last_node);
				let next_edge=self.edges[edge_index];
				self.edges[edge_index].node=std::usize::MAX;
				self.edges[edge_index^1].node=std::usize::MAX;

				temp.push((last_node, next_edge));
				last_node=next_edge.node;
			}else{
				if let Some(&(node, edge))=temp.last(){
					result.push(edge);
					temp.pop();
					last_node=node;
				}else{ break }
			}
		}

		Some(result)
	}
}

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
	let number: usize=input.token();
	let data: Vec<[usize; 2]>=(0..number).map(|_| [input.token(), input.token()]).collect();

	let mut result=0u32;
	let mut result_path=Path::new();

	let mut check=|num_bit: u32|->bool{
		if num_bit>20{return false}

		let mut graph=Graph::new(1<<num_bit);
		let mask=(1<<num_bit)-1;
		for (index, &[first, sec]) in data.iter().enumerate(){
			graph.add_edge(first&mask, sec&mask, index<<1);
		}
		if let Some(path)=graph.find_circuit(){
			if path.len()==number{
				result_path=path;
				return true;
			}
		}
		false
	};

	for step in (0..20).rev().map(|x| 1u32<<x){
		if check(result+step){
			result+=step;
		}
	}
	write!(w, "{}\n", result).unwrap();
	if result==0{
		for node in 1..=number*2{
			write!(w, "{} ", node).unwrap();
		}
	}else{
		for edge in &result_path{
			write!(w, "{} {} ", (edge.index^1)+1, edge.index+1).unwrap();
		}
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
impl_token_stream_u!(u32);
impl_token_stream_i!(i32);
impl_token_stream_i!(i64);
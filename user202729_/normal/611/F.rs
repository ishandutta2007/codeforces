// Still slow solution.
// (weird copy paste error?...)
use std::io::{self, prelude::*};
use std::cmp::{min, max};

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
	let ncommand:i32=input.token();
	let height:i32=input.token();
	let width:i32=input.token();
	let commands:Vec<u8>=input.token();
	debug_assert!(commands.len()==(ncommand as usize));

	#[derive(PartialEq, Eq, Copy, Clone)]
	struct Point(i32, i32);
	#[derive(PartialEq, Eq, Copy, Clone)]
	struct Rectangle(Point, Point);

	let mut bound=Rectangle(Point(0, 0), Point(0, 0)); // inclusive
	let mut cur=Point(0, 0);
	let mut changes=vec![(bound,0usize)];
	for (index, ch) in commands.iter().enumerate(){
		match ch{
			b'R'=>{cur.0+=1}
			b'L'=>{cur.0-=1}
			b'U'=>{cur.1+=1}
			b'D'=>{cur.1-=1}
			_=>{ debug_assert!(false); unsafe{ std::hint::unreachable_unchecked(); }}
		}
		let old_bound=bound;
		bound.0 .0=min(bound.0 .0, cur.0);
		bound.0 .1=min(bound.0 .1, cur.1);
		bound.1 .0=max(bound.1 .0, cur.0);
		bound.1 .1=max(bound.1 .1, cur.1);  // this is no worse than the ".first.second" mess. I should name stuff properly instead
		// ^ could be more efficient...

		if bound!=old_bound{
			changes.push((bound, index+1));
		}
	}
	if cur==Point(0, 0){
		if bound.1 .0-bound.0 .0+1<=width&&bound.1 .1-bound.0 .1+1<=height{
			write!(w,"-1\n");
			return;
		}
	}else{
		let loop_size=changes.len();
		let step=cur;
		let mut base_index=commands.len();
		'outer: loop{
			for i in 0..loop_size{
				let (rectangle, index)=changes[i];
				let old_bound=bound;
				bound.0 .0=min(bound.0 .0, rectangle.0 .0+cur.0);
				bound.0 .1=min(bound.0 .1, rectangle.0 .1+cur.1);
				bound.1 .0=max(bound.1 .0, rectangle.1 .0+cur.0);
				bound.1 .1=max(bound.1 .1, rectangle.1 .1+cur.1);

				if bound!=old_bound{ // * this check is not necessary?
					changes.push((bound, index+base_index));
				}
				if bound.1 .0-bound.0 .0+1>width||bound.1 .1-bound.0 .1+1>height{break 'outer}
				//changes.back().0 .1 .0-changes.back().0 .0 .0+1<=width&&changes.back().0 .1 .1-changes.back().0 .0 .1+1<=height
			}

			base_index+=commands.len();
			cur.0+=step.0; cur.1+=step.1;
		}
	}

	let mut result=0i32;
	let modulus=1000000007;
	for index in 1..{
		let (prev_rectangle, prev_index)=changes[index-1];
		let a=width-prev_rectangle.1 .0+prev_rectangle.0 .0;
		let b=height-prev_rectangle.1 .1+prev_rectangle.0 .1;
		if a==0||b==0{break}
		result=(((result as i64)+(a as i64)*(b as i64)%modulus*((changes[index].1-prev_index) as i64))%modulus) as i32;
		// ^ (isn't this too much cast?)
	}

	write!(w,"{}\n", result);
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
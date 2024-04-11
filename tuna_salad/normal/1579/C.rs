//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!v{
	($(:$t:ty)?=$e:expr)=>{$e$(as$t)?};([$d:expr]$(:$t:ty)?)=>{Vec::$(<$t>::)?with_capacity($d)};
	([]$(:$t:ty)?)=>{Vec::$(<$t>::)?new()};([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};}
fn rio()->(Reader,BufWriter<Stdout>){(Reader::new(),BufWriter::new(stdout()))}
struct Reader{buf:Vec<u8>,pos:usize,x:*mut Stdin,q:StdinLock<'static>}//'
#[allow(dead_code)]impl Reader{
	fn new()->Self{let x=Box::into_raw(Box::new(stdin()));let q=unsafe{&*x}.lock();Self{x,q,buf:v!([]),pos:0}}
	fn next_line(&mut self)->bool{self.buf.clear();self.pos=0;self.q.read_until(b'\n',&mut self.buf).unwrap_or(0)>0}
	fn byte(&mut self)->Option<u8>{
		if self.pos==self.buf.len(){if!self.next_line(){return None;}}self.pos+=1;Some(self.buf[self.pos-1])}
	fn vb(&mut self)->Vec<u8>{let mut s=v!([10]);let mut f=false;while let Some(c)=self.byte(){
		if!c.is_ascii_whitespace(){s.push(c);f=true;}else if f{break;}}s}
	fn p<T:FromStr>(&mut self)->T where T::Err:Debug{let w=self.vb();str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()}
	fn board(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rp!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
	}
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

mod range2 {
	type C = i8;
	type U = usize;
	pub struct B {
		cur: [C;2],
		high: [C;2],
	}
	impl B {
		pub fn new(c0: C, c1: C, h0: C, h1: C) -> Self {
			Self {cur: [c0,c1], high: [h0,h1]}
		}
		pub fn new_u(c0: U, c1: U, h0: U, h1: U) -> Self {
			Self::new(c0 as C, c1 as C, h0 as C, h1 as C)
		}
		pub fn add(&mut self, d0: C, d1: C) {
			self.cur[0] += d0;
			self.cur[1] += d1;
		}
		pub fn opt(&self) -> Option<[U;2]> {
			for i in 0..2 {
				if 0 > self.cur[i] || self.cur[i] >= self.high[i] {
					return None;
				}
			}
			Some([self.cur[0] as U, self.cur[1] as U])
		}
		pub fn opt_p(&self) -> Option<(U,U)> {
			self.opt().map(|[a,b]| (a,b))
		}
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		l!(r,c,k = rin.u());
		let mut b = rin.board(r,Some(c));
		for i in k-1..r {
			for j in k-1..c-min(c,k-1) {
				if b[i][j] != b'.' {
					let mut ma = i;
					for &dj in &[-1,1] {
						let mut p = range2::B::new_u(i,j,r,c);
						let mut x = 0;
						loop {
							if let Some((ii,jj)) = p.opt_p() {
								if b[ii][jj] != b'.' {
									p.add(-1,dj);
									x += 1;
									continue;
								}
							}
							x -= 1;
							break;
						}
						min!(ma, x);
					}
					if ma >= k {
						for x in 0..=ma {
							b[i-x][j-x] = b'x';
							b[i-x][j+x] = b'x';
						}
					}
				}
			}
		}
		let mut ok = true;
		for i in 0..r {
			for j in 0..c {
				if b[i][j] == b'*' {
					ok = false;
				}
			}
		}
		if ok {
			writeln!(rout, "YES").unwrap();
		} else {
			writeln!(rout, "NO").unwrap();
		}
	}
}
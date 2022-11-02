//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
	fn framed_board(&mut self, r: usize, c: usize, f: u8) -> Vec<Vec<u8>> {
		let mut res = v!([r+2]);
		res.push( v!([c+2] = f) );
		rp!{[r]
			let mut t = self.vb();
			assert!(t.len() == c);
			t.reserve(2);
			t.insert(0,f);
			t.push(f);
			res.push(t);
		}
		res.push( v!([c+2] = f) );
		res
	}
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		l!(r,c = rin.u());
		let b = rin.framed_board(r,c,b'?');
		let mut a = v!([r+2][c+2] = -1);
		for j in 0..c+2 {
			a[0][j] = 0;
			a[r+1][j] = 0;
		}
		for i in 0..r+2 {
			a[i][0] = 0;
			a[i][c+1] = 0;
		}
		let mut s = v!([]);
		let mut ans = (0,0,0);
		for i0 in 1..=r {
			for j0 in 1..=c {
				if a[i0][j0] == -1 {
					let mut i = i0;
					let mut j = j0;
					while a[i][j] == -1 {
						s.push((i,j));
						a[i][j] = -2;
						let (ii,jj) = match b[i][j] {
							b'L' => (i,j-1),
							b'R' => (i,j+1),
							b'U' => (i-1,j),
							b'D' => (i+1,j),
							_ => unreachable!(),
						};
						i = ii;
						j = jj;
					}
					let mut x = if a[i][j] == -2 {
						let k = s.len();
						let p = s.iter().position(|x| *x == (i,j)).unwrap();
						let x = (k - p) as i32;
						loop {
							let (ii,jj) = s.pop().unwrap();
							a[ii][jj] = x;
							if (ii,jj) == (i,j) {
								break;
							}
						}
						x
					} else {
						a[i][j]
					};
					while let Some((ii,jj)) = s.pop() {
						x += 1;
						a[ii][jj] = x;
					}
				}
				max!(ans, (a[i0][j0], i0, j0));
			}
		}
		writeln!(rout, "{} {} {}", ans.1, ans.2, ans.0).unwrap();
	}
}
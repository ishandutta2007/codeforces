//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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

fn main() {
	let (mut rin,mut rout) = rio();

	let f = |b: &mut [Vec<u8>], res: &mut Vec<[(usize,usize);3]>, r: usize, c: usize, t: usize| {
		let mut x = [(0,0);3];
		let mut p = 0;
		for i in 0..4 {
			if i != t {
				let rr = r + (i>>1);
				let cc = c + (i&1);
				x[p] = (rr+1, cc+1);
				b[rr][cc] ^= 1;
				p += 1;
			}
		}
		assert!(p == 3);
		res.push(x);
	};

	let mut b4 = v!([16][]);
	for x in 0..16 {
		let mut b = v!([2][2] = b'0');
		let mut o = v!([]);
		for i in 0..4 {
			if (x >> i) & 1 == 1 {
				o.push(i);
				f(&mut b, &mut v!([]), 0, 0, i);
			}
		}
		let mut y = 0;
		for p in 0..4 {
			if b[p>>1][p&1] == b'1' {
				y |= 1 << p;
			}
		}
		b4[y] = o;
	}

	rp!{[rin.u()]
		l!(r,c = rin.u());
		let mut b = rin.board(r, Some(c));
		let mut ans = v!([]);
		for i in (2..r).rev() {
			for j in (2..c).rev() {
				if b[i][j] == b'1' {
					f(&mut b, &mut ans, i-1, j-1, 0);
				}
			}
		}
		for i in (2..r).rev() {
			let x = b[i][0] - b'0';
			let y = b[i][1] - b'0';
			match (x,y) {
				(0,1) => f(&mut b, &mut ans, i-1, 0, 2),
				(1,0) => f(&mut b, &mut ans, i-1, 0, 3),
				(1,1) => f(&mut b, &mut ans, i-1, 0, 0),
				_ => (),
			}
		}
		for j in (2..c).rev() {
			let x = b[0][j] - b'0';
			let y = b[1][j] - b'0';
			match (x,y) {
				(0,1) => f(&mut b, &mut ans, 0, j-1, 1),
				(1,0) => f(&mut b, &mut ans, 0, j-1, 3),
				(1,1) => f(&mut b, &mut ans, 0, j-1, 0),
				_ => (),
			}
		}
		let mut y = 0;
		for p in 0..4 {
			if b[p>>1][p&1] == b'1' {
				y |= 1 << p;
			}
		}
		for &i in &b4[y] {
			f(&mut b, &mut ans, 0, 0, i);
		}
		assert!(b == v!([r][c] = b'0'));
		writeln!(rout, "{}", ans.len()).unwrap();
		for x in ans {
			for &(y,z) in &x {
				write!(rout, "{} {} ", y, z).unwrap();
			}
			writeln!(rout, "").unwrap();
		}
	}
}
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

	l!(r,c,k = rin.u());
	let mut b = rin.board(r, Some(c));
	let f = |i0: usize, j0: usize, b: &mut [Vec<u8>]| -> Vec<(usize,usize)> {
		let mut res = v!([]);
		if b[i0][j0] != b'.' {
			return res;
		}
		b[i0][j0] = b'?';
		res.push((i0,j0));
		for k in 0.. {
			if k >= res.len() {
				break;
			}
			let (i,j) = res[k];
			let mut v = v!([4]);
			if i > 0 {v.push((i-1,j));}
			if j > 0 {v.push((i,j-1));}
			if i+1<r {v.push((i+1,j));}
			if j+1<c {v.push((i,j+1));}
			for (i,j) in v {
				if b[i][j] == b'.' {
					b[i][j] = b'?';
					res.push((i,j));
				}
			}
		}
		res
	};
	for i in 0..r {
		f(i,0,&mut b);
		f(i,c-1,&mut b);
	}
	for j in 0..c {
		f(0,j,&mut b);
		f(r-1,j,&mut b);
	}
	let mut p = v!([]);
	for i in 1..r-1 {
		for j in 1..c-1 {
			let res = f(i,j,&mut b);
			if !res.is_empty() {
				p.push(res);
			}
		}
	}
	p.sort_by(|x,y| x.len().cmp(&y.len()));
	p.truncate(p.len() - k);
	for a in &mut b {
		for x in a {
			if *x == b'?' {
				*x = b'.';
			}
		}
	}
	let mut ans = 0;
	for a in p {
		for (i,j) in a {
			b[i][j] = b'*';
			ans += 1;
		}
	}
	writeln!(rout, "{}", ans).unwrap();
	for a in b {
		writeln!(rout, "{}", String::from_utf8(a).unwrap()).unwrap();
	}
}
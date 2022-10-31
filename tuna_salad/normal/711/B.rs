//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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
	fn u(&mut self) ->  usize { self.p() }
	fn l(&mut self) ->    i64 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	if n == 1 {
		writeln!(rout, "1").unwrap();
		return;
	}
	let mut b = v!([n][n]);
	let mut p = None;
	for i in 0..n {
		for j in 0..n {
			let x = rin.l();
			if x == 0 {
				p = Some((i,j));
			}
			b[i].push(x);
		}
	}
	l!(mut s0,s1 = 0);
	let (i0,j0) = p.unwrap();
	let i1 = if i0 == 0 {1} else {0};
	for j in 0..n {
		s0 += b[i0][j];
		s1 += b[i1][j];
	}
	let x = s1 - s0;
	let mut ok = x >= 1;
	b[i0][j0] = x;
	for i in 0..n {
		l!(mut y,z = 0);
		for j in 0..n {
			y += b[i][j];
			z += b[j][i];
		}
		ok &= y == s1;
		ok &= z == s1;
	}
	l!(mut y,z = 0);
	for i in 0..n {
		y += b[i][i];
		z += b[i][n-i-1];
	}
	ok &= y == s1;
	ok &= z == s1;
	if ok {
		writeln!(rout, "{}", x).unwrap();
	} else {
		writeln!(rout, "-1").unwrap();
	}
}
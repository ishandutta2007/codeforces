//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};}
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
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn rec(p: usize, eq: bool, a: &mut Vec<u8>, b: &[u8], c: &mut [usize]) -> bool {
	if p == b.len() {
		return true;
	}
	for i in (b'0'..=b'9').rev() {
		let ii = (i - b'0') as usize;
		if (eq && i > b[p]) || c[ii] == 0 {
			continue;
		}
		c[ii] -= 1;
		a.push(i);
		let e = eq && i == b[p];
		if rec(p+1, e, a, b, c) {
			return true;
		}
		a.pop();
		c[ii] += 1;
	}
	false
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(a,b = rin.vb());
	let mut a = a;
	if a.len() < b.len() {
		a.sort();
		a.reverse();
	} else {
		let mut c = v!([26] = 0);
		for x in a.clone() {
			c[(x - b'0') as usize] += 1;
		}
		a.clear();
		assert!(rec(0, true, &mut a, &b, &mut c));
	}
	writeln!(rout, "{}", String::from_utf8(a).unwrap()).unwrap();
}
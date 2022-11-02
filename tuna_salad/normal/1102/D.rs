//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let s0 = rin.vb();
	let mut s = v!([n]);
	let mut c = [-(n as i32 / 3);3];
	for x in s0 {
		let x = (x - b'0') as usize;
		s.push(x);
		c[x] += 1;
	}
	let mut p = v!([2]);
	p.push((0..n).collect::<Vec<_>>());
	p.push(p[0].clone());
	p[1].reverse();

	let mut f = |a: usize, b: usize, fw: bool| {
		let p = if fw {&p[0]} else {&p[1]};
		for &i in p {
			if s[i] == a && c[a] > 0 && c[b] < 0 {
				s[i] = b;
				c[a] -= 1;
				c[b] += 1;
			}
		}
	};

	f(0,2,false); // 2-, 0+a
	f(0,1,false); // 1-, 0+b
	f(1,0,true);  // 0-, 1+
	f(1,2,false); // 2-, 1+
	f(2,0,true);  // 0-, 2+a
	f(2,1,true);  // 1-, 2+b

	for x in s {
		write!(rout, "{}", x).unwrap();
	}
}
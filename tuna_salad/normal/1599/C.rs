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
	fn i(&mut self) ->    i32 { self.p() }
	fn u(&mut self) ->  usize { self.p() }
	fn f(&mut self) ->    f64 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.i();
	let p = rin.f();
	let mut lo = 0;
	let mut hi = n - 2;
	let mut ans = n - 1;
	while lo <= hi {
		let x = (lo + hi) / 2;
		let mut res = 0.0;
		let mut c = 0;
		for i in 0..=3 {
			let j = 3 - i;
			if i > x || j > n-x {
				continue;
			}
			let cc = if i == 0 {
				(n-x) * (n-x-1) * (n-x-2) / 6
			} else if i == 1 {
				x * (n-x) * (n-x-1) / 2
			} else if i == 2 {
				x * (x-1) * (n-x) / 2
			} else {
				x * (x-1) * (x-2) / 6
			};
			let pp = if i == 0 {
				0.0
			} else if i == 1 {
				0.5
			} else {
				1.0
			};
			res += pp * (cc as f64);
			c += cc;
		}
		assert!(c > 0);
		res /= c as f64;
		if res + 1e-9 > p {
			ans = x;
			hi = x-1;
		} else {
			lo = x+1;
		}
	}
	writeln!(rout, "{}", ans).unwrap();
}
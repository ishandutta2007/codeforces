//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn gcd(mut a: i32, mut b: i32) -> i32 {
	while b != 0 {
		let c = a % b;
		a = b;
		b = c;
	}
	a
}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let a = rin.vi(n);
	let mut g = 0;
	let mut c1 = 0;
	for &x in &a {
		g = gcd(g, x);
		if x == 1 {
			c1 += 1;
		}
	}
	if g > 1 {
		writeln!(rout, "-1").unwrap();
		return;
	}
	if c1 > 0 {
		writeln!(rout, "{}", n - c1).unwrap();
	} else {
		let mut res = n;
		for i in 0..n {
			let mut t = 0;
			let mut g = 0;
			for j in i..n {
				g = gcd(g, a[j]);
				t += 1;
				if g == 1 {
					break;
				}
			}
			if g > 1 {
				break;
			}
			min!(res, t);
		}
		writeln!(rout, "{}", n + res - 2).unwrap();
	}
}
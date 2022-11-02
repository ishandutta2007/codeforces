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
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn is_prime(x: usize) -> bool {
	let mut i = 2;
	while i*i <= x {
		if x % i == 0 {
			return false;
		}
		i += 1;
	}
	true
}

fn main() {
	let (mut rin,mut rout) = rio();
	const X: usize = 5000;

	let n = rin.u();
	if is_prime(n) {
		writeln!(rout, "1").unwrap();
		return;
	}
	let mut c = v!([X] = X);
	for i in 2..X {
		if is_prime(i) {
			c[i] = 1;
		}
	}
	for i in 2..X {
		for j in 2..X {
			if i+j >= X {
				break;
			}
			min!(c[i+j], c[i]+c[j]);
		}
	}
	let mut ans = n;
	if n < X {
		ans = c[n];
	} else {
		for i in 2..=X-2 {
			if is_prime(n-i) {
				min!(ans, c[i] + 1);
			}
		}
	}
	writeln!(rout, "{}", ans).unwrap();
}
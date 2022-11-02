//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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

	rp!{[rin.u()]
		let n = rin.u();
		let s = rin.vb();
		let f = |k: usize, p: usize| -> u8 {
			assert!(1 <= k && k <= n);
			assert!(p < n);
			if p <= n-k {
				s[p+k-1]
			} else if (n - k) % 2 == 0 {
				s[n-p-1]
			} else {
				s[p+k-n-1]
			}
		};
		let mut a = (1..=n).collect::<Vec<_>>();
		let mut b = v!([n]);
		for i in 0..n {
			if a.len() == 1 {
				break;
			}
			if i > 0 && a.len() == n {
				break;
			}
			b.clear();
			let mut x = b'z';
			for &k in &a {
				let y = f(k,i);
				if min!(x, y) {
					b.clear();
				}
				if x == y {
					b.push(k);
				}
			}
			std::mem::swap(&mut a, &mut b);
		}
		let k = a.into_iter().min().unwrap();
		for i in 0..n {
			write!(rout, "{}", f(k,i) as char).unwrap();
		}
		writeln!(rout, "").unwrap();
		writeln!(rout, "{}", k).unwrap();
	}
}
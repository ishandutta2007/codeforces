//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
		let s = rin.vb();
		let f = |mut i, mut j| -> bool {
			while i < j {
				if s[i] != s[j] {
					return false;
				}
				i += 1;
				j -= 1;
			}
			true
		};
		let n = s.len();
		let mut i = 0;
		let mut j = n-1;
		while i+1 <= j && s[i] == s[j] {
			i += 1;
			j -= 1;
		}
		let mut ans = if i > j {(0,0)} else {(1,i)};
		for k in (i..j).rev() {
			if f(i,k) {
				if max!(ans.0, k-i+1) {
					ans.1 = i;
				}
				break;
			}
		}
		for k in i+1..=j {
			if f(k,j) {
				if max!(ans.0, j-k+1) {
					ans.1 = k;
				}
				break;
			}
		}
		for &(l,r) in &[(0,i), (ans.1, ans.0+ans.1), (j+1,n)] {
			let res = str::from_utf8(&s[l..r]).unwrap();
			write!(rout, "{}", res).unwrap();
		}
		writeln!(rout, "").unwrap();
	}
}
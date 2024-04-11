//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn gcd(mut a: usize, mut b: usize) -> usize {
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
	let mut a = rin.vu(n);
	let mut g = 0;
	for x in &a {
		g = gcd(g,*x);
	}
	for x in &mut a {
		*x /= g;
	}
	let m = *a.iter().max().unwrap();
	let mut ps = v!([m+1] = true);
	let mut c = v!([m+1] = 0);
	for x in a {
		c[x] += 1;
	}
	let mut ans = 0;
	for i in 2..=m {
		if ps[i] {
			let mut res = 0;
			let mut j = i;
			while j <= m {
				res += c[j];
				ps[j] = false;
				j += i;
			}
			max!(ans, res);
		}
	}
	if ans == 0 {
		writeln!(rout, "-1").unwrap();
	} else {
		assert!(ans < n);
		writeln!(rout, "{}", n - ans).unwrap();
	}
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vf(&mut self, n: usize) -> Vec<f64> { self.vp(n) }
	fn f(&mut self) ->    f64 { self.p() }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let f = |a: &[f64], mut t: f64| -> f64 {
		let n = a.len();
		for i in 1..n {
			let tt = (a[i] - a[i-1]) / i as f64;
			if t >= tt {
				t -= tt;
			} else {
				return a[i-1] + i as f64 * t;
			}
		}
		a[n-1]
	};

	rp!{[rin.u()]
		let n = rin.u();
		let l = rin.f();
		let mut a = v!([n+2]);
		a.push(0.0);
		a.append(&mut rin.vf(n));
		a.push(l);
		let mut b = a.clone();
		b.reverse();
		for x in &mut b {
			*x = l - *x;
		}
		let mut hi = 1.0;
		let mut lo = 0.5;
		loop {
			let ya = f(&a, hi);
			let yb = f(&b, hi);
			if ya + yb < l {
				lo = hi;
				hi += hi;
			} else {
				break;
			}
		}
		while lo + 1e-7 < hi {
			let mid = (lo + hi) / 2.0;
			let ya = f(&a, mid);
			let yb = f(&b, mid);
			if ya + yb >= l {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		let ans = (lo + hi) / 2.0;
		writeln!(rout, "{:.6}", ans).unwrap();
	}
}
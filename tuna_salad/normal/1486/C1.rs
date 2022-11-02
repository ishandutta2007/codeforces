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
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const A: usize = 40;

	let n = rin.i();
	let mut ca = 0;
	let mut ask = |l: i32, r: i32| -> i32 {
		ca += 1;
		assert!(ca <= A);
		assert!(1 <= l && l < r && r <= n);
		writeln!(rout, "? {} {}", l, r).unwrap();
		rout.flush().unwrap();
		rin.i()
	};
	let p0 = ask(1,n);
	let ans = {
		if p0 > 1 && ask(1,p0) == p0 {
			let mut lo = 2;
			let mut hi = p0-1;
			let mut ans = 1;
			while lo <= hi {
				let mid = (lo + hi) / 2;
				if ask(mid, p0) == p0 {
					ans = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			ans
		} else {
			if p0 > 1 {
				assert!(ask(p0,n) == p0);
			}
			let mut lo = p0+1;
			let mut hi = n-1;
			let mut ans = n;
			while lo <= hi {
				let mid = (lo + hi) / 2;
				if ask(p0, mid) == p0 {
					ans = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			ans
		}
	};
	writeln!(rout, "! {}", ans).unwrap();
}
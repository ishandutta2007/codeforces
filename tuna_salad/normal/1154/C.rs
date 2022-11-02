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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn l(&mut self) ->    i64 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const R: [usize; 7] = [0,0,1,2,0,2,1];
	const N: [i64; 3] = [3,2,2];

	let a = rin.vl(3);
	let mut lo = 4;
	let mut hi = a[0]+a[1]+a[2];
	let mut ans = 3;
	while lo <= hi {
		let mid = lo + (hi - lo) / 2;
		let mut ok = false;
		for i in 0..7 {
			let mut b = [0;3];
			let mut d = mid;
			for j in i..7 {
				b[R[j]] += 1;
				d -= 1;
				if d == 0 {
					break;
				}
			}
			let w = d / 7;
			d %= 7;
			for j in 0..3 {
				b[j] += w * N[j];
			}
			for j in 0..d as usize {
				b[R[j]] += 1;
			}
			ok = true;
			for j in 0..3 {
				if b[j] > a[j] {
					ok = false;
					break;
				}
			}
			if ok {
				break;
			}
		}
		if ok {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	writeln!(rout, "{}", ans).unwrap();
}
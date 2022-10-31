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
	fn l(&mut self) ->    i64 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn test_enough(n: i64, k: i64) -> bool {
	let mut x = n;
	let mut sum = 0;
	while x > 0 {
		let y = x.min(k);
		x -= y;
		sum += y;
		x -= x/10;
	}
	// println!("n {}  k {}   get {}   {}", n, k, sum, 2*sum >= n);
	2*sum >= n
}

fn find_enough(n: i64) -> i64 {
	let mut res = 1;
	while !test_enough(n, res) {
		res *= 2;
		// println!("up res to {}", res);
	}
	let mut lo = 1.max(res/2);
	let mut hi = res-1;
	while lo <= hi {
		// println!("lo {}  hi {}", lo, hi);
		let mid = (lo + hi) / 2;
		if test_enough(n, mid) {
			res = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	res
}

fn main() {
	let (mut rin,mut rout) = rio();

	if false {
		let mut last = 0;
		for i in 1..=1000 {
			let k = find_enough(i);
			if last != k {
				last = k;
				println!("{} -> {}", i, k);
			}
		}
		return;
	}
	let n = rin.l();
	let ans = find_enough(n);
	writeln!(rout, "{}", ans).unwrap();
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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
	fn l(&mut self) ->    i64 { self.p() }
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		let n = rin.u();
		let k = rin.l();
		let a = rin.vu(n);
		let mut m = 0;
		while (1 << m) <= n {
			m += 1;
		}
		let m2 = 1 << m;
		let mut dp = v!([m2][4]);
		for i in (0..n).rev() {
			let x = a[i];
			if dp[x].len() < 2 {
				dp[x].push(i);
			}
		}
		for i in 0..m {
			for j in 0..m2 {
				let jj = j | (1 << i);
				if j != jj {
					let mut t = dp[j].clone();
					dp[jj].append(&mut t);
					dp[jj].sort();
					dp[jj].dedup();
					dp[jj].reverse();
					dp[jj].truncate(2);
				}
			}
		}
		let mut ans = -k * m2 as i64;
		for i in 0..m2 {
			if dp[i].len() == 2 {
				let a = dp[i][0] as i64 + 1;
				let b = dp[i][1] as i64 + 1;
				max!(ans, a * b - k * (i as i64));
			}
		}
		writeln!(rout, "{}", ans).unwrap();
	}
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
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
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn rec(l: usize, r: usize, a: &[i32], dp: &mut [Vec<i32>]) -> i32 {
	assert!(l <= r);
	let mut res = dp[l][r];
	if res == -1 {
		res = (r-l+1) as i32;
		if a[l] == a[r] {
			min!(res, rec(l+1, r-1, a, dp));
		}
		for i in l+1..=r {
			let res1 = rec(l, i-1, a, dp);
			let res2 = rec(i, r, a, dp);
			min!(res, res1 + res2);
		}
		dp[l][r] = res;
	}
	res
}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let a = rin.vi(n);
	let mut dp = v!([n][n] = -1);
	for i in 0..n {
		dp[i][i] = 1;
	}
	for i in 1..n {
		dp[i-1][i] = if a[i-1] == a[i] {1} else {2};
	}
	let ans = rec(0, n-1, &a, &mut dp);
	writeln!(rout, "{}", ans).unwrap();
}
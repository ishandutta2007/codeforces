//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};}
fn rio()->(Reader,BufWriter<Stdout>){(Reader::new(),BufWriter::new(stdout()))}
struct Reader{buf:Vec<u8>,pos:usize,q:StdinLock<'static>}/*'>}*/#[allow(dead_code)]impl Reader{
	fn new()->Self{let r=unsafe{&*Box::into_raw(Box::new(stdin()))};Self{q:r.lock(),buf:v!([]),pos:0}}
	fn next_line(&mut self)->bool{self.buf.clear();self.pos=0;self.q.read_until(b'\n',&mut self.buf).unwrap_or(0)>0}
	fn byte(&mut self)->Option<u8>{
		if self.pos==self.buf.len(){if!self.next_line(){return None;}}self.pos+=1;Some(self.buf[self.pos-1])}
	fn vb(&mut self)->Vec<u8>{let mut s=v!([10]);let mut f=false;while let Some(c)=self.byte(){
		if!c.is_ascii_whitespace(){s.push(c);f=true;}else if f{break;}}s}
	fn p<T:FromStr>(&mut self)->T where T::Err:Debug{let w=self.vb();str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()}
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let a = rin.vu(n);
	let c0 = n/2;
	let c1 = n - c0;
	let even = |x| x == 0 || (x > 0 && x % 2 == 0);
	let odd = |x| x == 0 || (x > 0 && x % 2 == 1);
	let mut dp = v!([n][c0+2][c1+2][2] = n+1);
	{
		let x = a[0];
		if even(x) {
			dp[0][1][0][0] = 0;
		}
		if odd(x) {
			dp[0][0][1][1] = 0;
		}
	}
	for i in 1..n {
		let x = a[i];
		for j0 in 0..=c0 {
			for j1 in 0..=c1 {
				for k in 0..=1 {
					let z = dp[i-1][j0][j1][k];
					if even(x) {
						min!(dp[i][j0+1][j1][0], z + k);
					}
					if odd(x) {
						min!(dp[i][j0][j1+1][1], z + 1 - k);
					}
				}
			}
		}
	}
	let ans = min(dp[n-1][c0][c1][0], dp[n-1][c0][c1][1]);
	writeln!(rout, "{}", ans).unwrap();
}
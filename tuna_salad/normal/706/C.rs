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
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const INF: i64 = 1_000000_000000_000000;

	let n = rin.u();
	let a = rin.vl(n);
	let mut dp = v!([2][2] = INF);
	let mut s = v!([2][2][]);
	let mut i0 = 0;
	let mut i1 = 1;
	s[i0][0] = rin.vb();
	s[i0][1] = s[i0][0].clone();
	s[i0][1].reverse();
	dp[i0][0] = 0;
	dp[i0][1] = a[0];
	for i in 1..n {
		let mut ss = rin.vb();
		s[i1][0] = ss.clone();
		ss.reverse();
		s[i1][1] = ss;
		for j in 0..2 {
			let d = j as i64 * a[i];
			let mut res = INF;
			for k in 0..2 {
				if s[i0][k] <= s[i1][j] {
					min!(res, dp[i0][k] + d);
				}
			}
			dp[i1][j] = res;
		}
		std::mem::swap(&mut i0, &mut i1);
	}
	let mut ans = dp[i0][0].min(dp[i0][1]);
	if ans == INF {
		ans = -1;
	}
	writeln!(rout, "{}", ans).unwrap();
}
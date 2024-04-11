//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
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
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const INF: i32 = 1000000000;

	let n = rin.u();
	let c = rin.i();
	l!(a,b = rin.vi(n-1));
	let mut dp = v!([n][2] = INF);
	dp[0][0] = 0;
	dp[0][1] = c;
	for i in 1..n {
		dp[i][0] = min(dp[i-1][0] + a[i-1], dp[i-1][1] + b[i-1]);
		dp[i][1] = min(dp[i-1][0] + c + min(a[i-1], b[i-1]), dp[i-1][1] + b[i-1]);
		min!(dp[i][0], dp[i][1]);
		min!(dp[i][1], dp[i][0] + c);
	}
	for i in 0..n {
		write!(rout, "{} ", dp[i][0]).unwrap();
	}
	writeln!(rout, "").unwrap();
}
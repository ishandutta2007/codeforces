//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
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
	fn board(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rp!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
	}
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let b = rin.board(n,Some(n));
	let m = rin.u();
	let p = rin.vu(m);
	let mut d = v!([n][n] = m+1);
	for i in 0..n {
		d[i][i] = 0;
		for j in 0..n {
			if b[i][j] == b'1' {
				min!(d[i][j], 1);
			}
		}
	}
	for k in 0..n {
		for i in 0..n {
			for j in 0..n {
				min!(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	let mut dp = v!([m]: (usize,usize));
	dp.push((1,0));
	for i in 1..m {
		let mut res = (m+1,m);
		for j in 1..=i.min(n-1) {
			if d[p[i-j]-1][p[i]-1] == j && min!(res.0, dp[i-j].0+1) {
				res.1 = i-j;
			}
		}
		assert!(res.1 < m);
		dp.push(res);
	}
	let mut ans = v!([]);
	let mut i = m-1;
	ans.push(p[i]);
	while i > 0 {
		i = dp[i].1;
		ans.push(p[i]);
	}
	ans.reverse();
	writeln!(rout, "{}", ans.len()).unwrap();
	for x in ans {
		write!(rout, "{} ", x).unwrap();
	}
}
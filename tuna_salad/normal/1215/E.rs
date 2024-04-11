//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
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
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let mut p = v!([20][]);
	for i in 0..n {
		p[rin.u()-1].push(i);
	}
	let mut d = v!([20][20] = 0);
	for i in 0..20 {
		let pi = &p[i];
		let ni = pi.len();
		if ni == 0 {
			continue;
		}
		for j in i+1..20 {
			let pj = &p[j];
			let nj = pj.len();
			if nj == 0 {
				continue;
			}
			let res0 = ni as i64 * nj as i64;
			let mut res = 0;
			l!(mut ii,jj = 0);
			while ii < ni || jj < nj {
				if jj == nj || (ii < ni && pi[ii] < pj[jj]) {
					ii += 1;
					res += jj as i64;
				} else {
					jj += 1;
				}
			}
			d[i][j] = res;
			d[j][i] = res0 - res;
		}
	}
	let n2 = 1 << 20;
	let mut dp = v!([n2] = i64::MAX);
	dp[0] = 0;
	let mut a = v!([20]);
	for b in 0..n2-1 {
		a.clear();
		for i in 0..20 {
			if b & (1 << i) == 0 {
				a.push(i);
			}
		}
		let res0 = dp[b];
		for &x in &a {
			let mut s = 0;
			for &y in &a {
				s += d[x][y];
			}
			min!(dp[b | (1 << x)], res0 + s);
		}
	}
	let ans = dp[n2-1];
	writeln!(rout, "{}", ans).unwrap();
}
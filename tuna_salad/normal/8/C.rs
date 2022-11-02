//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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
	fn u(&mut self) ->  usize { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const INF: i32 = 1000000000;

	l!(x0,y0 = rin.i());
	let n = rin.u();
	l!(mut x,y = v!([n]));
	rp!{[n]
		x.push(rin.i());
		y.push(rin.i());
	}
	let sqr = |x| x*x;
	let mut d = v!([n][n]);
	for i in 0..n {
		for j in 0..n {
			let mut res = 0;
			res += sqr(x[i]-x[j]) + sqr(y[i]-y[j]);
			res += sqr(x[i]-x0)   + sqr(y[i]-y0);
			res += sqr(x0  -x[j]) + sqr(y0  -y[j]);
			d[i].push(res);
		}
	}
	let n2 = 1 << n;
	let mut dp = v!([n2] = (INF,0,0));
	dp[0] = (0,0,0);
	for b in 0..n2-1 {
		if dp[b].0 == INF {
			continue;
		}
		let mut k = 0;
		while b & (1 << k) > 0 {
			k += 1;
		}
		assert!(k < n);
		let res0 = dp[b].0;
		for i in k..n {
			let bb = b | (1 << i);
			if bb == b {
				continue;
			}
			let bb = bb | (1 << k);
			let res = res0 + d[k][i];
			if min!(dp[bb].0, res) {
				dp[bb].1 = k;
				dp[bb].2 = i;
			}
		}
	}
	let mut b = n2-1;
	writeln!(rout, "{}", dp[b].0).unwrap();
	write!(rout, "0").unwrap();
	while b > 0 {
		let (_,i,j) = dp[b];
		if i < j {
			write!(rout, " {}", i+1).unwrap();
		}
		write!(rout, " {} 0", j+1).unwrap();
		b &= !((1 << i) | (1 << j));
	}
}
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
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const S: &[u8] = b"RGB";
	let p = |c:u8| S.iter().position(|&x| x == c).unwrap();

	let n = rin.u();
	let mut s = rin.vb();
	let mut dp = v!([n][3]);
	dp[0] = v!([3] = (1,3));
	dp[0][p(s[0])].0 = 0;
	for i in 1..n {
		for j1 in 0..3 {
			let mut res = n+1;
			let mut f = 3;
			for j0 in 0..3 {
				let t = dp[i-1][j0].0 + if j0 != j1 {0} else {n};
				if min!(res, t) {
					f = j0;
				}
			}
			if j1 != p(s[i]) {
				res += 1;
			}
			dp[i].push( (res,f) );
		}
	}
	let mut j = dp[n-1].iter().enumerate().min_by(|x,y| x.1.cmp(y.1)).unwrap().0;
	writeln!(rout, "{}", dp[n-1][j].0).unwrap();
	for i in (0..n).rev() {
		s[i] = S[j];
		j = dp[i][j].1;
	}
	writeln!(rout, "{}", String::from_utf8(s).unwrap()).unwrap();
}
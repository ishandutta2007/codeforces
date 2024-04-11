//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let f = |s:usize, c:u8| -> Option<usize> {
		match (s,c) {
			(2,b'e') => None,
			(4,b'o') => None,
			(1,b'n') => Some(2),
			(3,b'w') => Some(4),
			(_,b'o') => Some(1),
			(_,b't') => Some(3),
			(_,_)    => Some(0),
		}
	};

	rp!{[rin.u()]
		let s = rin.vb();
		let n = s.len();
		let mut dp = v!([n+1][5] = (-1,0,false));
		dp[0][0] = (0,0,false);
		for i in 0..n {
			let c = s[i];
			for j in 0..5 {
				let v = dp[i][j].0;
				if v < 0 {
					continue;
				}
				if max!(dp[i+1][j].0, v) {
					dp[i+1][j] = (v, j, true);
				}
				if let Some(jj) = f(j,c) {
					if max!(dp[i+1][jj].0, v+1) {
						dp[i+1][jj] = (v+1, j, false);
					}
				}
			}
		}
		let mut p = 0;
		for j in 1..5 {
			if dp[n][p].0 < dp[n][j].0 {
				p = j;
			}
		}
		let mut ans = v!([]);
		for i in (1..=n).rev() {
			let (_, j, u) = dp[i][p];
			p = j;
			if u {
				ans.push(i);
			}
		}
		ans.reverse();
		writeln!(rout, "{}", ans.len()).unwrap();
		for x in ans {
			write!(rout, "{} ", x).unwrap();
		}
		writeln!(rout, "").unwrap();
	}
}
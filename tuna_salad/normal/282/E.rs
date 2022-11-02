//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let (p,s) = {
		let a = rin.vl(n);
		l!(mut p,s = v!([n+1]));
		let mut x = 0;
		p.push(x);
		for &y in &a {
			x ^= y;
			p.push(x);
		}
		x = 0;
		s.push(0);
		for &y in a.iter().rev() {
			x ^= y;
			s.push(x);
		}
		(p,s)
	};

	let mut t = v!([1] = [0,0]);
	let mut ans = 0;
	for i in 0..=n {
		let x = s[i];
		let mut u = 0;
		for i in (0..40).rev() {
			let j = ((x >> i) & 1) as usize;
			if t[u][j] == 0 {
				t[u][j] = t.len();
				t.push([0,0]);
			}
			u = t[u][j];
		}
		let x = p[n-i];
		let mut u = 0;
		let mut res = 0;
		for i in (0..40).rev() {
			let j = 1 - ((x >> i) & 1) as usize;
			let j = if t[u][j] > 0 {
				j
			} else {
				1 - j
			};
			res = (res << 1) | j as i64;
			u = t[u][j];
			assert!(u != 0);
		}
		max!(ans, x ^ res);
	}
	writeln!(rout, "{}", ans).unwrap();
}
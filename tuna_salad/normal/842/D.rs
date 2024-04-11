//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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
	const X: ([usize;2],bool) = ([0,0],false);

	l!(n,m = rin.u());
	let mut a = rin.vu(n);
	a.sort();
	a.dedup();
	let mut t = v!([2] = X);
	for x in a {
		let mut u = 1;
		for i in (0..19).rev() {
			let b = (x >> i) & 1;
			if t[u].0[b] == 0 {
				t[u].0[b] = t.len();
				t.push(X);
			}
			u = t[u].0[b];
		}
	}
	for u in (1..t.len()).rev() {
		let a = t[u].0[0];
		let b = t[u].0[1];
		t[u].1 = (a == 0 && b == 0) || (t[a].1 && t[b].1);
	}
	assert!(!t[1].1);
	let mut x0 = 0;
	rp!{[m]
		x0 ^= rin.u();
		let mut ans = 0;
		let mut u = 1;
		for i in (0..19).rev() {
			let b = (x0 >> i) & 1;
			let v = t[u].0[b];
			if t[v].1 {
				ans |= 1 << i;
				u = t[u].0[b^1];
			} else {
				u = v;
			}
		}
		writeln!(rout, "{}", ans).unwrap();
	}
}
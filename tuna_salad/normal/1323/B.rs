//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
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
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m,k = rin.u());
	let a = rin.vi(n);
	let b = rin.vi(m);
	let f = |a: Vec<i32>| -> Vec<i64> {
		let n = a.len();
		let mut aa = v!([n+1] = 0);
		let mut i = 0;
		while i < n {
			if a[i] == 0 {
				i += 1;
				continue;
			}
			let mut j = i;
			while j < n && a[j] == 1 {
				aa[j-i+1] += 1;
				j += 1;
			}
			i = j;
		}
		for i in (0..n).rev() {
			aa[i] += aa[i+1];
		}
		aa
	};
	let aa = f(a);
	let bb = f(b);
	let mut ans = 0;
	let mut f = |aa: &[i64], bb: &[i64], x: usize, y: usize| {
		if let (Some(&x),Some(&y)) = (aa.get(x),bb.get(y)) {
			ans += x * y;
		}
	};
	let mut i = 1;
	while i*i < k {
		if k % i == 0 {
			let j = k / i;
			f(&aa, &bb, i, j);
			f(&aa, &bb, j, i);
		}
		i += 1;
	}
	if i*i == k {
		f(&aa, &bb, i, i);
	}
	writeln!(rout, "{}", ans).unwrap();
}
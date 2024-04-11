//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
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
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let f = |a: &[i64]| -> Vec<i64> {
		let mut st = v!([n+1]: (i64,i64,i64));
		st.push((-1,0,0));
		let mut res = v!([n]);
		for i in 0..n {
			let j = i as i64;
			loop {
				let (x,y,z) = st.pop().unwrap();
				if y < a[i] {
					st.push((x,y,z));
					let s = z + (j - x) * a[i];
					st.push((j,a[i],s));
					res.push(s);
					break;
				}
			}
		}
		res
	};
	let mut a = rin.vl(n);
	let l = f(&a);
	a.reverse();
	let mut r = f(&a);
	r.reverse();
	a.reverse();
	let mut res = 0;
	let mut p = n;
	for i in 0..n {
		let x = l[i] + r[i] - a[i];
		if max!(res, x) {
			p = i;
		}
	}
	assert!(p < n);
	let mut ans = v!([n] = 0);
	let mut x = a[p];
	for i in (0..p).rev() {
		min!(x, a[i]);
		ans[i] = x;
	}
	x = a[p];
	for i in p..n {
		min!(x, a[i]);
		ans[i] = x;
	}
	for x in ans {
		write!(rout, "{} ", x).unwrap();
	}
}
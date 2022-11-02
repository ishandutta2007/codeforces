//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

// Fenwick Tree {{{
mod fenwick {
	type V = i32;
	pub struct Tree {
		n: usize,
		pub arr: Box<[V]>
	}
	impl Tree {
		pub fn new(n: usize) -> Self {
			let arr = vec![0; n + 1].into_boxed_slice();
			Self { n, arr }
		}
		pub fn add(&mut self, p: usize, v: V) {
			let mut p = p as i32 + 1;
			let n = self.n as i32;
			while p <= n {
				self.arr[p as usize] += v;
				p += p & -p;
			}
		}
		pub fn sum(&self, p: usize) -> V {
			let mut p = p as i32 + 1;
			let mut res = 0;
			while p > 0 {
				res += self.arr[p as usize];
				p -= p & -p;
			}
			res
		}
	}
}//}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let mut a = rin.vu(2*n);
	let mut p = v!([n][2]);
	let mut ft = fenwick::Tree::new(2*n);
	for i in 0..2*n {
		a[i] -= 1;
		p[a[i]].push(i);
		ft.add(i,1);
	}
	let mut ans = 0;
	for i in 0..2*n {
		if i == p[a[i]][0] {
			for &x in &p[a[i]] {
				ft.add(x,-1);
			}
			ans += ft.sum(p[a[i]][1]);
		}
	}
	writeln!(rout, "{}", ans).unwrap();
}
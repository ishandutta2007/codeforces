//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

mod spn {
	use std::fmt::{Display, Formatter, Result};
	use std::cmp::Ordering;
	use std::convert::TryFrom;
	#[derive(Debug,Clone,Copy,PartialEq,Eq)]
	pub struct U(i32);
	#[allow(dead_code)]
	impl U {
		pub fn from_i<T:Into<i32>>(x: T) -> Self {
			Self(x.into().max(-1))
		}
		pub fn from_u<T:Into<usize>>(x: T) -> Self {
			Self(<i32 as TryFrom<_>>::try_from(x.into()).unwrap())
		}
		pub fn none() -> Self {
			Self(-1)
		}
		pub fn is_ok(self) -> bool {
			self.0 >= 0
		}
		pub fn uo(self) -> Option<usize> {
			if self.is_ok() {
				Some(self.0 as usize)
			} else {
				None
			}
		}
		pub fn io(self) -> Option<i32> {
			if self.is_ok() {
				Some(self.0)
			} else {
				None
			}
		}
		pub fn u(self) -> usize {
			self.uo().unwrap()
		}
		pub fn i(self) -> i32 {
			self.io().unwrap()
		}
		pub fn min(self, o: Self) -> Self {
			if !self.is_ok() {
				o
			} else if !o.is_ok() {
				self
			} else {
				Self(self.0.min(o.0))
			}
		}
		pub fn max(self, o: Self) -> Self {
			if !self.is_ok() {
				o
			} else if !o.is_ok() {
				self
			} else {
				Self(self.0.max(o.0))
			}
		}
		pub fn min_i<T:Into<i32>>(self, x: T) -> Self {
			self.min(U::from_i(x))
		}
		pub fn max_i<T:Into<i32>>(self, x: T) -> Self {
			self.max(U::from_i(x))
		}
		pub fn min_u<T:Into<usize>>(self, x: T) -> Self {
			self.min(U::from_u(x))
		}
		pub fn max_u<T:Into<usize>>(self, x: T) -> Self {
			self.max(U::from_u(x))
		}
	}
	impl Default for U {
		fn default() -> Self {
			Self::none()
		}
	}
	impl PartialOrd for U {
		fn partial_cmp(&self, rhs: &Self) -> Option<Ordering> {
			if self.is_ok() == rhs.is_ok() {
				Some(self.0.cmp(&rhs.0))
			} else {
				None
			}
		}
	}
	impl Display for U {
		fn fmt(&self, f: &mut Formatter) -> Result {
			if self.0 >= 0 {
				write!(f, "{}", self.0)
			} else {
				write!(f, "(-)")
			}
		}
	}
}
use spn::U;

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m = rin.u());
	let mut el = v!([m]);
	let mut deg = v!([n] = 0);
	let mut adj = v!([n][n] = false);
	rp!{[m]
		l!(a,b = rin.u()-1);
		el.push((a,b));
		deg[a] += 1;
		deg[b] += 1;
		adj[a][b] = true;
		adj[b][a] = true;
	}
	let mut ans = U::none();
	for (a,b) in el {
		for i in 0..n {
			if i != a && i != b && adj[a][i] && adj[b][i] {
				let res = deg[i] + deg[a] + deg[b] - 6;
				ans = ans.min_i(res);
			}
		}
	}
	let ans = ans.io().unwrap_or(-1);
	writeln!(rout, "{}", ans).unwrap();
}
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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

type X = (i32, i32, i32, i32, i32);

fn insert(t: &mut BinaryHeap<X>, (_,a,b,l,r): X) {
	if a <= b {
		let res = if l == 0 || (r > 0 && r <= l) {
			r
		} else {
			l
		};
		t.push( (-res,a,b,l,r) );
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m = rin.u());
	let mut x = rin.vi(n);
	x.sort();
	let mut ans: i64 = 0;
	let mut pos = v!([m]);
	let mut t = BinaryHeap::new();
	insert(&mut t, (0, i32::MIN, x[0]-1, 0, 1));
	insert(&mut t, (0, x[n-1]+1, i32::MAX, 1, 0));
	for i in 1..n {
		insert(&mut t, (0, x[i-1]+1, x[i]-1, 1, 1));
	}
	rp!{[m]
		let (res,a,b,l,r) = t.pop().unwrap();
		let res = -res;
		ans += res as i64;
		if res == l {
			insert(&mut t, (0, a+1, b, l+1, r));
			pos.push(a);
		} else {
			insert(&mut t, (0, a, b-1, l, r+1));
			pos.push(b);
		}
	}

	writeln!(rout, "{}", ans).unwrap();
	for a in pos {
		write!(rout, "{} ", a).unwrap();
	}
}
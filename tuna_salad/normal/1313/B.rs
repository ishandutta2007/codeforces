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
	fn l(&mut self) ->    i64 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

type I = (i64,i64);
const INF: i64 = 1e10 as i64;

fn intersect(a: I, b: I) -> Option<I> {
	let x = a.0.max(b.0);
	let y = a.1.min(b.1);
	if x <= y {
		Some((x,y))
	} else {
		None
	}
}

fn push(a: I, b: I, c: &mut Vec<I>) {
	if let Some(x) = intersect(a,b) {
		c.push(x);
	}
}

fn calc(mut a: Vec<I>, mut b: Vec<I>, t: i64) -> i64 {
	a.retain(|(x,y)| x <= y);
	b.retain(|(x,y)| x <= y);
	let mut res = 0;
	for (x,y) in a {
		let (x,mut y) = (t-y,t-x);
		let mut bb = v!([]);
		for i in b {
			if let Some((l,r)) = intersect((x,INF), i) {
				let r = r.min(l+y-x);
				res += r-l+1;
				push(i, (-INF,l-1), &mut bb);
				push(i, (r+1,INF), &mut bb);
				y -= r-l+1;
			} else {
				bb.push(i);
			}
		}
		b = bb;
		b.retain(|(x,y)| x <= y);
	}
	res
}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		l!(n,x,y = rin.l());
		let ans1 = n - calc(vec![(1,x-1),(x+1,n)], vec![(1,y-1),(y+1,n)], x+y+1);
		let ans2 = 1 + calc(vec![(1,n-x),(n-x+2,n)], vec![(1,n-y),(n-y+2,n)], n+n-x-y+2);
		writeln!(rout, "{} {}", ans1, ans2).unwrap();
	}
}
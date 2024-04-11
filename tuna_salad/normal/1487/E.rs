//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const X: i32 = 1000000000;

	let n = rin.vu(4);
	let mut a = v!([4]);
	for i in 0..4 {
		a.push(rin.vi(n[i]));
	}
	let mut h = v!([4] = HashSet::new());
	for i in 1..4 {
		let h = &mut h[i];
		rp!{[rin.u()]
			l!(a,b = rin.u()-1);
			h.insert( (a,b) );
		}
	}
	let mut b = v!([]);
	for (i,&x) in a[0].iter().enumerate() {
		b.push( (x,i) );
	}
	b.sort();
	for i in 1..4 {
		let mut bb = v!([]);
		let a = &a[i];
		let h = &h[i];
		for (j,&x) in a.iter().enumerate() {
			let mut res = X;
			for &(y,k) in b.iter() {
				if !h.contains( &(k,j) ) {
					res = x + y;
					break;
				}
			}
			if res < X {
				bb.push( (res,j) );
			}
		}
		bb.sort();
		b = bb;
	}
	let ans = b.first().map(|&(x,_)| x).unwrap_or(-1);
	writeln!(rout, "{}", ans).unwrap();
}
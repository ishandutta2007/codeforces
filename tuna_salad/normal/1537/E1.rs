//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn z_fn(s: &[u8]) -> Vec<i32> {
	let n = s.len();
	assert!(n > 0);
	l!(mut l,r = 0);
	let mut z = vec![0; n];
	z[0] = -1;
	for i in 1..n {
		if i <= r && z[i-l] < (r as i32) - (i as i32) +1 {
			z[i] = z[i-l];
		} else {
			l = i;
			max!(r, l);
			while r < n && s[r-l] == s[r] {
				r += 1;
			}
			z[i] = (r as i32) - (l as i32);
			r -= 1;
		}
	}
	z
}
fn main() {
	let (mut rin,mut rout) = rio();

	l!(_n,k = rin.u());
	let mut s = rin.vb();
	s.push(b'z'+1);
	let z = z_fn(&s);
	let mut l = 1;
	loop {
		let p = z[l] as usize;
		if s[p] < s[l+p] {
			break;
		}
		l += 1;
	}
	for i in 0..k {
		write!(rout, "{}", s[i%l] as char).unwrap();
	}
}
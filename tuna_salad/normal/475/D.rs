//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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
	fn i(&mut self) ->    i32 { self.p() }
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn gcd(mut a: i32, mut b: i32) -> i32 {
	while b != 0 {
		let c = a % b;
		a = b;
		b = c;
	}
	a
}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let a = rin.vi(n);
	let q = rin.u();
	let b = rin.vi(q);
	l!(mut h,c = HashMap::new());
	for &x in &b {
		h.insert(x, 0_i64);
	}
	let mut s = v!([n]);
	for i in 0..n {
		s.push(a[i]);
		*c.entry(a[i]).or_insert(0) += 1_i64;
		let mut j = i;
		while j > 0 {
			let t = gcd(s[j], a[j-1]);
			if s[j-1] != t {
				let e = c.entry(s[j-1]).or_insert(0);
				*e -= 1;
				if *e == 0 {
					c.remove(&s[j-1]);
				}
				s[j-1] = t;
				*c.entry(t).or_insert(0) += 1;
				j -= 1;
			} else {
				break;
			}
		}
		for (x,y) in c.iter() {
			if let Some(z) = h.get_mut(&x) {
				*z += y;
			}
		}
	}
	for x in b {
		let ans = h[&x];
		writeln!(rout, "{}", ans).unwrap();
	}
}
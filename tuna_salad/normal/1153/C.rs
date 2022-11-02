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
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn no() -> ! {
	println!(":(");
	std::process::exit(0)
}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let s = rin.vb();
	if s.len() & 1 != 0 || s[0] == b')' || s[n-1] == b'(' {
		no();
	}
	let s = &s[1..n-1];
	l!(mut co,cc,cq = 0);
	for &c in s {
		match c {
			b'(' => co += 1,
			b')' => cc += 1,
			_    => cq += 1,
		}
	}
	if co.min(cc) + cq < co.max(cc) {
		no();
	}
	let mut t = v!([n-2]);
	let mut k = n/2-1 - co;
	for &c in s {
		if c == b'?' {
			if k > 0 {
				k -= 1;
				t.push(b'(');
			} else {
				t.push(b')');
			}
		} else {
			t.push(c);
		}
	}
	let mut i: i32 = 0;
	for &c in &t {
		if c == b'(' {
			i += 1;
		} else {
			i -= 1;
			if i < 0 {
				no();
			}
		}
	}
	assert!(i == 0);
	writeln!(rout, "({})", String::from_utf8(t).unwrap()).unwrap();
}
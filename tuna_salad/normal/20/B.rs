//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};}
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
	fn l(&mut self) ->    i64 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(a,b,c = rin.l());
	if a == 0 && b == 0 {
		if c == 0 {
			writeln!(rout, "-1").unwrap();
		} else {
			writeln!(rout, "0").unwrap();
		}
	} else if a == 0 {
		writeln!(rout, "1").unwrap();
		let x0 = -c as f64 / b as f64;
		writeln!(rout, "{:.6}", x0).unwrap();
	} else {
		let d2 = b*b - 4*a*c;
		if d2 < 0 {
			writeln!(rout, "0").unwrap();
		} else {
			if d2 == 0 {
				writeln!(rout, "1").unwrap();
				let x0 = -b as f64 / (2.0 * a as f64);
				writeln!(rout, "{:.6}", x0).unwrap();
			} else {
				writeln!(rout, "2").unwrap();
				let d = (d2 as f64).sqrt();
				let mut x0 = (-b as f64 - d) / (2.0 * a as f64);
				let mut x1 = (-b as f64 + d) / (2.0 * a as f64);
				if x0 > x1 {
					std::mem::swap(&mut x0, &mut x1);
				}
				writeln!(rout, "{:.6}", x0).unwrap();
				writeln!(rout, "{:.6}", x1).unwrap();
			}
		}
	}
}
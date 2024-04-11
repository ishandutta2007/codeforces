//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let mut a = v!([n]);
	for i in 0..n {
		a.push( (rin.u(),i+1) );
	}
	a.sort();
	let mut c = v!([2500001] = 0);
	for i in 2..n {
		let j = c[a[i].0 - a[i-1].0];
		if j > 0 {
			let (x,w,z,y) = (a[j-1].1, a[j].1, a[i-1].1, a[i].1);
			writeln!(rout, "YES").unwrap();
			writeln!(rout, "{} {} {} {}", x, y, z, w).unwrap();
			return;
		}
		c[a[i-1].0 - a[i-2].0] = i-1;
	}
	drop(c);
	let mut p = v!([2500001] = (0,0));
	for i in 1..n {
		for j in i+1..n {
			let d = a[j].0 - a[i].0;
			if p[d] != (0,0) {
				let (x,w) = p[d];
				let (z,y) = (a[i].1, a[j].1);
				writeln!(rout, "YES").unwrap();
				writeln!(rout, "{} {} {} {}", x, y, z, w).unwrap();
				return;
			}
		}
		for j in 0..i {
			let d = a[i].0 - a[j].0;
			p[d] = (a[j].1, a[i].1);
		}
	}
	writeln!(rout, "NO").unwrap();
}
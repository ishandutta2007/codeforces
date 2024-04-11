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
	fn i(&mut self) ->    i32 { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let mut ask = |s: &str, i: usize, j: usize| -> usize {
		writeln!(rout, "{} {} {}", s, i+1, j+1).unwrap();
		rout.flush().unwrap();
		let res = rin.i();
		assert!(res >= 0);
		res as usize
	};
	let mut pos = v!([n][]);
	let mut x = v!([n]);
	x.push(0);
	pos[0].push(0);
	let mut y2 = None;
	for i in 1..n {
		let y = ask("XOR", 0, i);
		x.push(y);
		pos[y].push(i);
		if pos[y].len() > 1 {
			y2 = Some(y);
		}
	}
	let v0 = if let Some(y) = y2 {
		y ^ ask("OR", pos[y][0], pos[y][1])
	} else {
		let a1 = ask("AND", 0, pos[1][0]);
		let a2 = ask("AND", 0, pos[2][0]);
		a1 | a2
	};
	write!(rout, "!").unwrap();
	for v in x {
		write!(rout, " {}", v ^ v0).unwrap();
	}
	writeln!(rout, "").unwrap();
}
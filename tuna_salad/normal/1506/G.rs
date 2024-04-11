//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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

	rp!{[rin.u()]
		let s = rin.vb();
		let n = s.len();
		let mut a = v!([n] = 0);
		let mut b = 0_i32;
		let mut p = v!([26][]);
		for i in (0..n).rev() {
			let x = (s[i] - b'a') as usize;
			b |= 1 << x;
			a[i] = b;
			p[x].push(i);
		}
		b = 0;
		let mut i = 0;
		let mut ans = String::new();
		while b != a[0] {
			let mut ok = false;
			for j in (0..26).rev() {
				if b & (1 << j) == 0 {
					if let Some(&k) = p[j].last() {
						if a[k] | b == a[0] {
							ok = true;
							ans.push((j as u8 + b'a') as char);
							b |= 1 << j;
							while i <= k {
								p[(s[i] - b'a') as usize].pop();
								i += 1;
							}
							break;
						}
					}
				}
			}
			assert!(ok);
		}
		writeln!(rout, "{}", ans).unwrap();
	}
}
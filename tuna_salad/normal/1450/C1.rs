//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
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
	fn board(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rp!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
	}
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		let n = rin.u();
		let mut b = rin.board(n, Some(n));
		let mut c = v!([2][3] = 0_usize);
		for i in 0..n {
			for j in 0..n {
				let mut k = None;
				if b[i][j] == b'X' {
					k = Some(0);
				} else if b[i][j] == b'O' {
					k = Some(1);
				}
				if let Some(k) = k {
					c[k][(i+j)%3] += 1;
				}
			}
		}
		let mut res = n*n;
		let mut p = (0,0);
		for i in 0..3 {
			for j in 0..3 {
				if i != j && min!(res, c[0][i] + c[1][j]) {
					p = (i,j);
				}
			}
		}
		for i in 0..n {
			for j in 0..n {
				if b[i][j] != b'.' {
					let ij = (i + j) % 3;
					if ij == p.0 {
						b[i][j] = b'O';
					} else if ij == p.1 {
						b[i][j] = b'X';
					}
				}
			}
		}
		for bb in b {
			writeln!(rout, "{}", String::from_utf8(bb).unwrap()).unwrap();
		}
	}
}
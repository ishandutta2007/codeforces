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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		let n = rin.u();
		let m = rin.i();
		let xs = rin.vi(n);
		let mut rs = v!([n]);
		rp!{[n]
			rs.push(rin.vb()[0] == b'R');
		}
		let mut ans = v!([n] = -1);
		for p in 0..2 {
			let mut a = v!([n]);
			for i in 0..n {
				if xs[i] % 2 == p {
					a.push( (xs[i],i) );
				}
			}
			a.sort();
			let mut st = v!([n]);
			for (x,i) in a {
				if rs[i] {
					st.push( (x,i) );
				} else if let Some( (x1,j) ) = st.pop() {
					let t = (x - x1) / 2;
					ans[j] = t;
					ans[i] = t;
				} else {
					st.push( (-x,i) );
				}
			}
			while st.len() >= 2 {
				let (xb,b) = st.pop().unwrap();
				let (xa,a) = st.pop().unwrap();
				let t = (2*m - xa - xb) / 2;
				ans[a] = t;
				ans[b] = t;
			}
		}
		for a in ans {
			write!(rout, "{} ", a).unwrap();
		}
		writeln!(rout, "").unwrap();
	}
}
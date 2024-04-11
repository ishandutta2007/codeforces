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
		l!(n,m = rin.u());
		let e = rin.board(n,Some(n));
		let mut ans = None;
		if m % 2 == 1 {
			ans = Some([1,2].repeat((m+1)/2));
		} else {
			'ok1: /*'*/
			for i in 0..n {
				for j in i+1..n {
					if e[i][j] == e[j][i] {
						let mut t = [i+1,j+1].repeat(m/2);
						t.push(i+1);
						ans = Some(t);
						break 'ok1; //'
					}
				}
			}
			if ans.is_none() {
				for i in 0..n {
					l!(mut a,b = None);
					for j in 0..n {
						if e[i][j] == b'a' {
							a = Some(j);
						} else if e[i][j] == b'b' {
							b = Some(j);
						}
					}
					if let (Some(a),Some(b)) = (a,b) {
						let mut t = v!([m+1]);
						let mut c = a;
						let x = a ^ i;
						rp!{[m/2]
							t.push(c+1);
							c ^= x;
						}
						t.reverse();
						t.push(i+1);
						let mut c = b;
						let x = b ^ i;
						rp!{[m/2]
							t.push(c+1);
							c ^= x;
						}
						ans = Some(t);
						break;
					}
				}
			}
		}
		if let Some(ans) = ans {
			writeln!(rout, "YES").unwrap();
			for x in ans {
				write!(rout, "{} ", x).unwrap();
			}
			writeln!(rout, "").unwrap();
		} else {
			writeln!(rout, "NO").unwrap();
		}
	}
}
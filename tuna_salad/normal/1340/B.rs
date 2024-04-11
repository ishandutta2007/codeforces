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

const B: [&[u8];10] = [
	b"1110111",
	b"0010010",
	b"1011101",
	b"1011011",
	b"0111010",
	b"1101011",
	b"1101111",
	b"1010010",
	b"1111111",
	b"1111011",
];

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,k = rin.u());
	let s = rin.board(n, Some(7));
	let mut dp = v!([n+1][k+1] = (-1,0));
	dp[n][0] = (0,0);
	for i in (0..n).rev() {
		let b = &s[i];
		let mut t = v!([10]);
		for j in 0..10 {
			let mut ok = true;
			let mut c = 0;
			for k in 0..7 {
				if B[j][k] != b[k] {
					if b[k] == b'1' {
						ok = false;
						break;
					}
					c += 1;
				}
			}
			if ok {
				t.push( (j as i8, c) );
			}
		}
		for j in 0..=k {
			let mut res = (-1,0);
			for &(d,c) in &t {
				if c <= j && dp[i+1][j-c].0 >= 0 {
					res = (d,c);
				}
			}
			dp[i][j] = res;
		}
	}
	if dp[0][k].0 == -1 {
		writeln!(rout, "-1").unwrap();
	} else {
		let mut j = k;
		for i in 0..n {
			let (d,c) = dp[i][j];
			write!(rout, "{}", d).unwrap();
			j -= c;
		}
		writeln!(rout, "").unwrap();
	}
}
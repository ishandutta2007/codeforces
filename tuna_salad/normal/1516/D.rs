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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const NL: usize = 18;
	const A: usize = 100000;

	l!(n,q = rin.u());
	let a = rin.vi(n);
	let mut f = v!([n]);
	for i in 0..n {
		let mut x = a[i];
		let mut b = v!([]);
		for j in 2.. {
			if j * j > x {
				break;
			}
			let mut c = 0;
			while x % j == 0 {
				x /= j;
				c += 1;
			}
			if c > 0 {
				b.push(j as usize);
			}
		}
		if x > 1 {
			b.push(x as usize);
		}
		f.push(b);
	}
	let mut j = n;
	let mut c = v!([A+1] = 0_i8);
	let mut c2 = 0;
	let mut ss = v!([NL][n+1] = 0);
	for i in (0..n).rev() {
		for &x in &f[i] {
			c[x] += 1;
			if c[x] == 2 {
				c2 += 1;
			}
		}
		while c2 > 0 {
			j -= 1;
			for &x in &f[j] {
				if c[x] == 2 {
					c2 -= 1;
				}
				c[x] -= 1;
			}
		}
		ss[0][i] = j;
	}
	ss[0][n] = n;
	for i in 1..NL {
		for j in 0..=n {
			ss[i][j] = ss[i-1][ss[i-1][j]];
		}
	}
	rp!{[q]
		let mut l = rin.u() - 1;
		let r = rin.u();
		let mut ans = 1;
		for i in (0..NL).rev() {
			let p = ss[i][l];
			if p < r {
				ans += 1 << i;
				l = p;
			}
		}
		writeln!(rout, "{}", ans).unwrap();
	}
}
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
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	const N: usize = 20000000;
	let ns = (N as f64).sqrt().ceil() as usize;
	let mut min_p = v!([N+1] = 0);
	for i in 2..=ns {
		if min_p[i] == 0 {
			min_p[i] = i;
			let mut j = i*i;
			while j <= N {
				if min_p[j] == 0 {
					min_p[j] = i;
				}
				j += i;
			}
		}
	}
	for i in ns+1..=N {
		if min_p[i] == 0 {
			min_p[i] = i;
		}
	}
	let mut num_p = v!([N+1]);
	num_p.push(0);
	num_p.push(0);
	for i in 2..=N {
		let p = min_p[i];
		let a = i / p;
		let n = num_p[a] + if min_p[a] != p {1} else {0};
		num_p.push(n);
	}

	rp!{[rin.u()]
		l!(c,d,x = rin.u());
		let mut last = 0;
		let mut res = 0_i64;
		let mut f = |a:usize| {
			if last != a {
				last = a;
				if (a+d) % c == 0 {
					res += 1 << num_p[(a+d) / c];
				}
			}
		};
		let xs = (x as f64).sqrt().floor() as usize;
		for i in 1..=xs {
			if x % i == 0 {
				f(i);
				f(x/i);
			}
		}
		writeln!(rout, "{}", res).unwrap();
	}
}
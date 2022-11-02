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

fn calc(e: &[Vec<usize>]) -> i64 {
	let n = e.len();
	let n2 = 1 << n;
	let s = n-1;
	let mut dp = v!([n2][n] = 0_i64);
	let mut res = - (e[s].len() as i64);
	for &v in &e[s] {
		dp[1 << v][v] = 1;
	}
	for b in 0..n2 {
		res += dp[b][s];
		for u in 0..n {
			let d = dp[b][u];
			if u != s && d > 0 {
				for &v in &e[u] {
					let bb = b | (1 << v);
					if b != bb {
						dp[bb][v] += d;
					}
				}
			}
		}
	}
	res / 2
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m = rin.u());
	let mut el = v!([m]);
	rp!{[m]
		l!(a,b = rin.u()-1);
		el.push( (a,b) );
	}
	let mut ans = 0;
	for k in 3..=n {
		let mut e = v!([k][]);
		for &(a,b) in &el {
			if max(a,b) < k {
				e[a].push(b);
				e[b].push(a);
			}
		}
		ans += calc(&e);
	}
	writeln!(rout, "{}", ans).unwrap();
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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

fn dfs(u: usize, e: &[(usize,usize)], a: usize, ans0: &mut usize) {
	if e[u] == (0,0) {
		max!(*ans0, a + 1);
	} else {
		if e[u].0 == 0 {
			dfs(e[u].1, e, a, ans0);
		} else if e[u].1 == 0 {
			dfs(e[u].0, e, a, ans0);
		} else {
			dfs(e[u].0, e, a+1, ans0);
			dfs(e[u].1, e, a+1, ans0);
		}
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let a = rin.vi(n);
	let mut e = v!([n*30+1]);
	e.push((0,0));
	for x in a {
		let mut u = 0;
		for i in (0..30).rev() {
			if x & (1 << i) == 0 {
				if e[u].0 == 0 {
					e[u].0 = e.len();
					e.push((0,0));
				}
				u = e[u].0;
			} else {
				if e[u].1 == 0 {
					e[u].1 = e.len();
					e.push((0,0));
				}
				u = e[u].1;
			}
		}
	}
	let mut ans0 = 0;
	dfs(0, &e, 0, &mut ans0);
	let ans = n - ans0;
	writeln!(rout, "{}", ans).unwrap();
}
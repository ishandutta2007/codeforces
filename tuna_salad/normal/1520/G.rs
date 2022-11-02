//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
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
	fn l(&mut self) ->    i64 { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const INF: i64 = 1e18 as i64;

	l!(n,m = rin.u());
	let w = rin.l();
	let b: Vec<_> = (0..n).map(|_| rin.vi(m)).collect();
	let bfs = |i0: usize, j0: usize, i1: usize, j1: usize| -> (i64,i64) {
		let mut res = v!([n][m] = -1);
		let mut f = |q: &mut VecDeque<(usize,usize,i32)>, i: usize, j: usize, d: i32| {
			if res[i][j] == -1 {
				res[i][j] = d;
				q.push_back((i,j,d));
			}
		};
		let mut q = VecDeque::new();
		f(&mut q, i0, j0, 0);
		while let Some((i,j,d)) = q.pop_front() {
			let d1 = d + 1;
			let mut v = v!([4]);
			if i > 0 { v.push((i-1,j)); }
			if j > 0 { v.push((i,j-1)); }
			if i+1<n { v.push((i+1,j)); }
			if j+1<m { v.push((i,j+1)); }
			for (ii,jj) in v {
				if b[ii][jj] >= 0 {
					f(&mut q, ii, jj, d1);
				}
			}
		}
		let res0 = if res[i1][j1] >= 0 {
			res[i1][j1] as i64 * w
		} else {
			INF
		};
		let mut res1 = INF;
		for i in 0..n {
			for j in 0..m {
				if res[i][j] >= 0 && b[i][j] > 0 {
					min!(res1, b[i][j] as i64 + res[i][j] as i64 * w);
				}
			}
		}
		(res0,res1)
	};
	let (b0,x0) = bfs(0,0,n-1,m-1);
	let (_,x1) = bfs(n-1,m-1,0,0);
	let ans = b0.min(x0 + x1);
	if ans < INF {
		writeln!(rout, "{}", ans).unwrap();
	} else {
		writeln!(rout, "-1").unwrap();
	}
}
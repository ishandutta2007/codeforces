//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};}
fn rio()->(Reader,BufWriter<Stdout>){(Reader::new(),BufWriter::new(stdout()))}
struct Reader{buf:Vec<u8>,pos:usize,x:*mut Stdin,q:StdinLock<'static>}//'
#[allow(dead_code)]impl Reader{
	fn new()->Self{let x=Box::into_raw(Box::new(stdin()));let q=unsafe{&*x}.lock();Self{x,q,buf:v!([]),pos:0}}
	fn next_line(&mut self)->bool{self.buf.clear();self.pos=0;self.q.read_until(b'\n',&mut self.buf).unwrap_or(0)>0}
	fn byte(&mut self)->Option<u8>{
		if self.pos==self.buf.len(){if!self.next_line(){return None;}}self.pos+=1;Some(self.buf[self.pos-1])}
	fn vb(&mut self)->Vec<u8>{let mut s=v!([10]);let mut f=false;while let Some(c)=self.byte(){
		if!c.is_ascii_whitespace(){s.push(c);f=true;}else if f{break;}}s}
	fn p<T:FromStr>(&mut self)->T where T::Err:Debug{let w=self.vb();str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()}
	fn graph(&mut self,n:usize,m:usize)->Vec<Vec<usize>>{
		let mut e=v!([n][]);rp!{[m]l!(a,b=self.u()-1);e[a].push(b);e[b].push(a);}e}
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let mut a = v!([n] = [0;3]);
	for i in 0..3 {
		for (j,x) in rin.vl(n).into_iter().enumerate() {
			a[j][i] = x;
		}
	}
	let e = rin.graph(n,n-1);
	let mut u0 = None;
	for i in 0..n {
		if e[i].len() > 2 {
			writeln!(rout, "-1").unwrap();
			return;
		}
		if e[i].len() == 1 {
			u0 = Some(i);
		}
	}
	let s = {
		let mut s = v!([n]);
		let mut u = u0.unwrap();
		let mut last = n;
		s.push(u);
		rp!{[n-1]
			let uu;
			if e[u][0] != last {
				uu = e[u][0];
			} else {
				uu = e[u][1];
			}
			last = u;
			u = uu;
			s.push(u);
		}
		s
	};
	let mut res = (i64::MAX,[0;3]);
	for x in 0..3 {
		for y in 0..3 {
			if x == y {
				continue;
			}
			for z in 0..3 {
				if x == z || y == z {
					continue;
				}
				let mut r = 0;
				let b = [x,y,z];
				for i in 0..n {
					r += a[s[i]][b[i%3]];
				}
				if res.0 > r {
					res = (r, b);
				}
			}
		}
	}
	writeln!(rout, "{}", res.0).unwrap();
	let b = res.1;
	let mut ans = v!([n] = 0);
	for i in 0..n {
		ans[s[i]] = b[i%3] + 1;
	}
	for x in ans {
		write!(rout, "{} ", x).unwrap();
	}
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

// Simple DSU {{{
struct DSU {
	n: usize,
	par: Vec<usize>
}
#[allow(dead_code)]impl DSU {
	fn new(n: usize) -> Self { let mut d = Self {n:0, par:Vec::new()}; d.resize(n); d }
	fn resize(&mut self, n: usize) { self.n = n; self.par.resize(n, 0); self.reset(); }
	fn reset(&mut self) { for i in 0..self.n { self.par[i] = i; } }
	fn find(&mut self, a: usize) -> usize {
		if a != self.par[a] { self.par[a] = self.find(self.par[a]); } self.par[a] }
	fn union(&mut self, mut a: usize, mut b: usize) -> bool {
		a = self.find(a); b = self.find(b); if a != b { self.par[a] = b; true } else { false } }
}//}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const INF: i32 = 1000000000;

	l!(n,m,k = rin.u());
	let c = rin.vu(k);
	let mut t = v!([n]);
	for i in 0..k {
		rp!{[c[i]]
			t.push(i);
		}
	}
	let mut dsu = DSU::new(n);
	let mut el = v!([m]);
	rp!{[m]
		l!(a,b = rin.u()-1);
		let c = rin.i();
		el.push((a,b,c));
		if c == 0 {
			dsu.union(a,b);
		}
	}
	{
		let mut j = 0;
		for i in 0..n {
			if t[i] != t[j] {
				j = i;
			}
			if dsu.find(i) != dsu.find(j) {
				writeln!(rout, "No").unwrap();
				return;
			}
		}
	}
	let mut dp = v!([k][k] = INF);
	for i in 0..k {
		dp[i][i] = 0;
	}
	for (a,b,c) in el {
		let a = t[a];
		let b = t[b];
		min!(dp[a][b], c);
		min!(dp[b][a], c);
	}
	for z in 0..k {
		for i in 0..k {
			for j in 0..k {
				min!(dp[i][j], dp[i][z] + dp[z][j]);
			}
		}
	}
	writeln!(rout, "Yes").unwrap();
	for ans in dp {
		for mut x in ans {
			if x == INF {
				x = -1;
			}
			write!(rout, "{} ", x).unwrap();
		}
		writeln!(rout, "").unwrap();
	}
}
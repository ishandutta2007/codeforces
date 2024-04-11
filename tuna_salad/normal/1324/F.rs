//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!v{
	($(:$t:ty)?=$e:expr)=>{$e$(as$t)?};([$d:expr]$(:$t:ty)?)=>{Vec::$(<$t>::)?with_capacity($d)};
	([]$(:$t:ty)?)=>{Vec::$(<$t>::)?new()};([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};}
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
	fn graph(&mut self,n:usize,m:usize)->Vec<Vec<usize>>{
		let mut e=v!([n][]);rp!{[m]l!(a,b=self.u()-1);e[a].push(b);e[b].push(a);}e}
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn dfs1(u: usize, p: usize, e: &[Vec<usize>], a: &[i32], dp1: &mut [i32]) {
	let mut res = a[u];
	for &v in &e[u] {
		if v != p {
			dfs1(v, u, e, a, dp1);
			res += dp1[v].max(0);
		}
	}
	dp1[u] = res;
}

fn dfs2(u: usize, p: usize, e: &[Vec<usize>], a: &[i32], dp1: &[i32], ans: &mut [i32], to: i32) {
	ans[u] = dp1[u] + to.max(0);
	for &v in &e[u] {
		if v != p {
			dfs2(v, u, e, a, dp1, ans, ans[u] - dp1[v].max(0));
		}
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let mut a = rin.vi(n);
	for x in &mut a {
		*x = 2 * *x - 1;
	}
	let e = rin.graph(n,n-1);
	l!(mut dp1,ans = v!([n] = -1));
	dfs1(0, 0, &e, &a, &mut dp1);
	dfs2(0, 0, &e, &a, &dp1, &mut ans, 0);
	for x in ans {
		write!(rout, "{} ", x).unwrap();
	}
}
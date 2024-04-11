//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
	fn graph_di(&mut self,n:usize,m:usize)->Vec<Vec<usize>>{
		let mut e=v!([n][]);rp!{[m]l!(a,b=self.u()-1);e[a].push(b);}e}
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn dfs(u: usize, e: &[Vec<usize>], vis: &mut [i8], ord: &mut Vec<usize>) -> bool {
	vis[u] = 1;
	for &v in &e[u] {
		if vis[v] == 1 || (vis[v] == 0 && !dfs(v, e,  vis, ord)) {
			return false;
		}
	}
	vis[u] = 2;
	ord.push(u);
	true
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m = rin.u());
	let s = rin.vb();
	let e = rin.graph_di(n,m);
	let mut vis = v!([n] = 0);
	let mut ord = v!([n]);
	for u in 0..n {
		if vis[u] == 0 && !dfs(u, &e, &mut vis, &mut ord) {
			writeln!(rout, "-1").unwrap();
			return;
		}
	}
	ord.reverse();
	let mut ans = 0;
	for i in b'a'..=b'z' {
		let mut dp = v!([n] = 0);
		for &u in &ord {
			let res = dp[u] + if i == s[u] {1} else {0};
			max!(ans, res);
			for &v in &e[u] {
				max!(dp[v], res);
			}
		}
	}
	writeln!(rout, "{}", ans).unwrap();
}
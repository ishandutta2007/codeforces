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
	fn graph(&mut self,n:usize,m:usize)->Vec<Vec<usize>>{
		let mut e=v!([n][]);rp!{[m]l!(a,b=self.u()-1);e[a].push(b);e[b].push(a);}e}
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn dfs(u: usize, e: &[Vec<usize>], c: usize, rit: usize, vis: &mut [usize], col: &mut [usize], c12: &mut [Vec<usize>]) {
	vis[u] = rit;
	c12[c].push(u);
	for &v in &e[u] {
		if col[v] == 0 && vis[v] != rit {
			dfs(v, e, 1-c, rit, vis, col, c12);
		}
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		let n = rin.u();
		let e = rin.graph(n,n-1);
		let mut vis = v!([n] = 0);
		let mut rit = 0;
		l!(mut a,b,aa = v!([]));
		a.push(v!([]));
		let mut x = 1;
		for i in 1..=n {
			if i >= (1 << x) {
				b.push((aa.len(),x));
				a.push(aa);
				aa = v!([]);
				x += 1;
			}
			aa.push(i);
		}
		b.push((aa.len(),x));
		a.push(aa);
		// writeln!(rout, "{:?}", a).unwrap();
		let mut col = v!([n] = 0);
		b.sort();
		b.reverse();
		for (c,x) in b {
			rit += 1;
			let mut c12 = [v!([]),v!([])];
			for u in 0..n {
				if col[u] == 0 && vis[u] != rit {
					dfs(u, &e, 0, rit, &mut vis, &mut col, &mut c12);
				}
			}
			let p = if c12[0].len() >= c12[1].len() {
				0
			} else {
				1
			};
			// writeln!(rout, "({},{}) => p {}  c12 {:?}", c,x,p,c12).unwrap();
			let cc = &mut c12[p];
			assert!(cc.len() >= c);
			rp!{[c]
				let u = cc.pop().unwrap();
				col[u] = x;
			}
		}
		// for u in 0..n {
		// 	writeln!(rout, "{} : {}", u, col[u]).unwrap();
		// }
		for u in 0..n {
			let ans = a[col[u]].pop().unwrap();
			write!(rout, "{} ", ans).unwrap();
		}
		writeln!(rout, "").unwrap();
	}
}
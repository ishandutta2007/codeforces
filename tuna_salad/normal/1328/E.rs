//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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
	fn graph(&mut self,n:usize,m:usize)->Vec<Vec<usize>>{
		let mut e=v!([n][]);rp!{[m]l!(a,b=self.u()-1);e[a].push(b);e[b].push(a);}e}
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

#[derive(Clone,Copy)]
struct Info {
	dep: usize,
	par: usize,
	beg: usize,
	end: usize,
}
impl Info {
	fn new() -> Self {
		l!(dep,par,beg,end = 0);
		Self {dep,par,beg,end}
	}
}

fn dfs(u: usize, d: usize, t: &mut usize, e: &[Vec<usize>], info: &mut [Info]) {
	info[u].dep = d;
	*t += 1;
	info[u].beg = *t;
	for &v in &e[u] {
		if info[v].dep == 0 {
			info[v].par = u;
			dfs(v, d+1, t, e, info);
		}
	}
	*t += 1;
	info[u].end = *t;
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m = rin.u());
	let e = rin.graph(n,n-1);
	let mut info = v!([n] = Info::new());
	info[0].par = 0;
	dfs(0, 1, &mut 0, &e, &mut info);

	rp!{[m]
		let k = rin.u();
		let mut a = v!([k]);
		let mut y = 0;
		rp!{[k]
			let u = info[rin.u()-1].par;
			a.push(u);
			if info[y].dep < info[u].dep {
				y = u;
			}
		}
		let mut ok = true;
		for x in a {
			if info[x].beg > info[y].beg || info[x].end < info[y].end {
				ok = false;
				break;
			}
		}
		if ok {
			writeln!(rout, "YES").unwrap();
		} else {
			writeln!(rout, "NO").unwrap();
		}
	}
}
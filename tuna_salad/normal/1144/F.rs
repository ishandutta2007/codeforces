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
	fn graph(&mut self,n:usize,m:usize)->Vec<Vec<usize>>{
		let mut e=v!([n][]);rp!{[m]l!(a,b=self.u()-1);e[a].push(b);e[b].push(a);}e}
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn dfs(u: usize, cc: i8, e: &[Vec<usize>], c: &mut [i8]) -> bool {
	c[u] = cc;
	for &v in &e[u] {
		if c[v] == 2 {
			if !dfs(v, 1-cc, e, c) {
				return false;
			}
		} else if c[v] == cc {
			return false;
		}
	}
	true
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m = rin.u());
	let mut ea = v!([m]);
	let mut e = v!([n][]);
	rp!{[m]
		l!(a,b = rin.u()-1);
		ea.push(a);
		e[a].push(b);
		e[b].push(a);
	}
	let mut c = v!([n] = 2);
	if dfs(0, 0, &e, &mut c) {
		writeln!(rout, "YES").unwrap();
		for x in ea {
			write!(rout, "{}", c[x]).unwrap();
		}
		writeln!(rout, "").unwrap();
	} else {
		writeln!(rout, "NO").unwrap();
	}
}
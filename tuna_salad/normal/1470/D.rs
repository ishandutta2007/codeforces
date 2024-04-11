//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		l!(n,m = rin.u());
		let e = rin.graph(n,m);
		{
			let mut dsu = DSU::new(n);
			let mut cc = n;
			for u in 0..n {
				for &v in &e[u] {
					if dsu.union(u,v) {
						cc -= 1;
					}
				}
			}
			if cc > 1 {
				writeln!(rout, "NO").unwrap();
				continue;
			}
		}
		let mut exp = v!([n] = false);
		let mut st = v!([]);
		let mut stv = v!([n] = false);
		let mut no = v!([n] = false);
		let mut ans = v!([]);
		stv[0] = true;
		st.push(0);
		while let Some(u) = st.pop() {
			if no[u] {
				continue;
			}
			ans.push(u);
			for &v in &e[u] {
				no[v] = true;
				if max!(exp[v], true) {
					for &w in &e[v] {
						if max!(stv[w], true) {
							st.push(w);
						}
					}
				}
			}
		}
		writeln!(rout, "YES").unwrap();
		writeln!(rout, "{}", ans.len()).unwrap();
		for u in ans {
			write!(rout, "{} ", u+1).unwrap();
		}
		writeln!(rout, "").unwrap();
	}
}
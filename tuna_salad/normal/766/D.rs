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
	fn u(&mut self) ->  usize { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
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

	l!(n,m,q = rin.u());
	let mut h = HashMap::new();
	for i in 0..n {
		h.insert(rin.vb(), i);
	}

	l!(mut rel,mean = DSU::new(n));
	let mut oppo = v!([n] = n);
	rp!{[m]
		let r = rin.i();
		l!(u,v = h[&rin.vb()]);
		if rel.find(u) == rel.find(v) {
			if (mean.find(u) == mean.find(v)) == (r == 1) {
				writeln!(rout, "YES").unwrap();
			} else {
				writeln!(rout, "NO").unwrap();
			}
		} else {
			writeln!(rout, "YES").unwrap();
			rel.union(u,v);
			let u = mean.find(u);
			let v = mean.find(v);
			let (w,x) = (u, oppo[u]);
			let (y,z) = if r == 1 {(v, oppo[v])} else {(oppo[v], v)};
			let mut make_same = |a: usize, b: usize| -> usize {
				if a != n && b != n {
					mean.union(a,b);
					mean.find(a)
				} else if a != n {
					a
				} else {
					b
				}
			};
			let wy = make_same(w,y);
			let xz = make_same(x,z);
			if wy != n && xz != n {
				let a = mean.find(wy);
				let b = mean.find(xz);
				oppo[a] = b;
				oppo[b] = a;
			}
		}
	}
	rp!{[q]
		l!(u,v = h[&rin.vb()]);
		if rel.find(u) == rel.find(v) {
			if mean.find(u) == mean.find(v) {
				writeln!(rout, "1").unwrap();
			} else {
				writeln!(rout, "2").unwrap();
			}
		} else {
			writeln!(rout, "3").unwrap();
		}
	}
}
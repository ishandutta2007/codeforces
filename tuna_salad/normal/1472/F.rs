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
	fn u(&mut self) ->  usize { self.p() }
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

	rp!{[rin.u()]
		l!(n,m = rin.u());
		let mut a = v!([m]);
		let mut h = BTreeMap::new();
		rp!{[m]
			l!(r,c = rin.u());
			a.push((r-1,c));
			h.insert(c-1, 0);
			h.insert(c, 0);
			h.insert(c+1, 0);
		}
		h.remove(&0);
		h.remove(&(n+1));
		let k = h.len();
		let z = h.keys().cloned().collect::<Vec<_>>();
		for (i,v) in h.values_mut().enumerate() {
			*v = i;
		}

		let mut f = v!([2][k] = true);
		for (r,c) in a {
			f[r][h[&c]] = false;
		}
		let mut dsu = DSU::new(2*k);
		for i in 0..k {
			if f[0][i] && f[1][i] {
				dsu.union(i, i+k);
			}
		}
		for i in 1..k {
			for j in 0..2 {
				if f[j][i-1] && f[j][i] {
					let x = i + j * k;
					dsu.union(x-1, x);
				}
			}
		}
		let mut c = v!([2*k] = 0_i32);
		let y = |i,j| if (i ^ z[j]) & 1 == 0 {1} else {-1};
		for i in 0..2 {
			for j in 0..k {
				if f[i][j] {
					let x = j + i * k;
					c[dsu.find(x)] += y(i,j);
				}
			}
		}
		let mut ans = c.into_iter().all(|x| x == 0);
		if ans {
			let mut c = 0;
			for j in 0..k {
				for i in 0..2 {
					if f[i][j] {
						c += y(i,j);
					}
				}
				if c.abs() >= 2 {
					ans = false;
					break;
				}
			}
		}
		if ans {
			writeln!(rout, "YES").unwrap();
		} else {
			writeln!(rout, "NO").unwrap();
		}
	}
}
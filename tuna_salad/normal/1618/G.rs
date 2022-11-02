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
	fn l(&mut self) ->    i64 { self.p() }
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

	l!(n,m,q = rin.u());
	let mut a = v!([n+m]);
	for (k,p) in [(n,1_usize),(m,0)] {
		rp!{[k]
			a.push((rin.l(), p));
		}
	}
	a.sort();
	let s = {
		let mut s = v!([n+m+1]);
		l!(mut x,y = 0);
		s.push((x,y));
		for &(xx,yy) in &a {
			x += xx;
			y += yy;
			s.push((x,y));
		}
		s
	};
	let mut b = v!([n+m+q-1]);
	for i in 1..n+m {
		b.push((a[i].0 - a[i-1].0, 0, i));
	}
	for i in 0..q {
		b.push((rin.l(), 1, i));
	}
	b.sort();
	let mut ans = v!([q] = -1);
	let mut d = DSU::new(n+m);
	let mut lr = v!([n+m]);
	for i in 0..n+m {
		lr.push((i,i));
	}
	let f = |lr: &[(usize,usize)], s: &[(i64,usize)], p: usize| -> i64 {
		// let p = d.find(p);
		let (l,r) = lr[p];
		let k = s[r+1].1 - s[l].1;
		s[r+1].0 - s[r+1-k].0
	};
	let mut res = 0;
	for i in 0..n+m {
		if a[i].1 == 1 {
			res += a[i].0;
		}
	}
	for (_,t,i) in b {
		if t == 0 {
			let i0 = d.find(i-1);
			let i1 = d.find(i);
			res -= f(&lr, &s, i0) + f(&lr, &s, i1);
			let l = lr[i0].0;
			let r = lr[i1].1;
			assert!(d.union(i0,i1));
			let ii = d.find(i0);
			lr[ii] = (l,r);
			res += f(&lr, &s, ii);
		} else {
			ans[i] = res;
		}
	}
	for x in ans {
		writeln!(rout, "{}", x).unwrap();
	}
}
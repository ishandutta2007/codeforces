//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::{Ordering,min,max},ops::{self,*},iter::{self,*}};
#[allow(unused_macros)]macro_rules!min{($x:expr,$y:expr)=>{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}};}
#[allow(unused_macros)]macro_rules!max{($x:expr,$y:expr)=>{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}};}
#[allow(unused_macros)]macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};
}#[allow(unused_macros)]macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};
	([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};
}#[allow(unused_macros)]macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
#[allow(dead_code)]fn rio()->(Reader,BufWriter<Stdout>){(Reader::new(),BufWriter::new(stdout()))}
struct Reader{buf:Vec<u8>,pos:usize,q:StdinLock<'static>}//'
#[allow(dead_code)]impl Reader{
	fn new()->Self{let r=unsafe{&*Box::into_raw(Box::new(stdin()))};Self{q:r.lock(),buf:v!([]),pos:0}}
	fn next_line(&mut self)->bool{self.buf.clear();self.pos=0;self.q.read_until(b'\n',&mut self.buf).unwrap_or(0)>0}
	fn is_ws(c:u8)->bool{c==b' '||c==b'\n'||c==b'\r'||c==b'\t'}
	fn byte(&mut self) -> Option<u8> {
		if self.pos==self.buf.len(){if!self.next_line(){return None;}}self.pos+=1;Some(self.buf[self.pos-1])
	}
	fn vb(&mut self)->Vec<u8>{
		let mut s=v!([10]);let mut f=false;while let Some(c)=self.byte()
		{if!Self::is_ws(c){s.push(c);f=true;}else if f{break;}}s
	}
	fn board(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rp!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
	}
	fn framed_board(&mut self, r: usize, c: usize, f: u8) -> Vec<Vec<u8>> {
		let mut res = v!([r+2]);
		res.push( v!([c+2] = f) );
		rp!{[r]
			let mut t = self.vb();
			assert!(t.len() == c);
			t.reserve(2);
			t.insert(0,f);
			t.push(f);
			res.push(t);
		}
		res.push( v!([c+2] = f) );
		res
	}
	fn s(&mut self) -> String { String::from_utf8(self.vb()).expect("invalid utf8") }
	fn i(&mut self) ->    i32 { self.p() }
	fn l(&mut self) ->    i64 { self.p() }
	fn u(&mut self) ->  usize { self.p() }
	fn f(&mut self) ->    f64 { self.p() }
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn ii(&mut self, n: usize) -> impl Iterator<Item=i32> { self.ip(n).into_iter() }
	fn iu(&mut self, n: usize) -> impl Iterator<Item=usize> { self.ip(n).into_iter() }
	fn p<T: FromStr>(&mut self) -> T where T::Err: Debug {
		let w = self.vb(); str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()
	}
	fn vp<T: FromStr>(&mut self, n: usize) -> Vec<T> where T::Err: Debug {
		(0..n).map(|_|self.p()).collect()
	}
	fn ip<T: FromStr>(&mut self, n: usize) -> impl Iterator<Item=T> where T::Err: Debug {
		self.vp(n).into_iter()
	}
	fn graph(&mut self, n: usize, m: usize) -> Vec<Vec<usize>> {
		let mut e = v!([n][]); rp!{[m] l!(a,b = self.u()-1); e[a].push(b); e[b].push(a); } e
	}
	fn graph_w<T: Copy+FromStr>(&mut self, n: usize, m: usize) -> Vec<Vec<(usize,T)>> where T::Err: Debug {
		let mut e=v!([n][]);rp!{[m]l!(a,b=self.u()-1);let c:T=self.p();e[a].push((b,c));e[b].push((a,c));}e
	}
}
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

	l!(n,m = rin.u());
	let mut s = v!([2*m]);
	let mut dsu = DSU::new(n);
	rp!{[m]
		l!(a,b = rin.u()-1);
		dsu.union(a,b);
		let (a,b) = (min(a,b), max(a,b));
		s.push( (a,0) );
		s.push( (b,1) );
	}
	let mut ans = 0;
	s.sort();
	let mut l = None;
	let mut c = 0;
	for (i,k) in s {
		if k == 0 {
			if c == 0 {
				l = Some(i)
			}
			c += 1;
		} else {
			c -= 1;
			if c == 0 {
				let p = l.unwrap();
				let r = i;
				for i in p+1..=r {
					if dsu.union(p,i) {
						ans += 1;
					}
				}
				l = None;
			}
		}
	}
	writeln!(rout, "{}", ans).unwrap();
}
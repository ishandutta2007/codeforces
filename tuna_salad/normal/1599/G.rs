//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
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
	fn f(&mut self) ->    f64 { self.p() }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn sqr(x: f64) -> f64 {
	x*x
}

fn dist(p: &[(f64,f64)], a: usize, b: usize) -> f64 {
	(sqr(p[a].0-p[b].0) + sqr(p[a].1-p[b].1)).sqrt()
}

// rec(gn-1, gs, 0, 0.0, &mut v, &mut ans, &p, &g);
fn rec(n: usize, u: usize, uu: usize, mut d: f64, vis: &mut [bool], ans: &mut f64, p: &[(f64,f64)], g: &[[usize;2]]) {
	d += dist(&p, g[u][0], g[u][1]);
	if n > 0 {
		vis[u] = true;
		for v in 0..g.len() {
			if !vis[v] {
				vis[v] = true;
				for j in 0..2 {
					let mut dd = d;
					dd += dist(&p, g[u][uu^1], g[v][j]);
					rec(n-1, v, j, dd, vis, ans, p, g);
				}
				vis[v] = false;
			}
		}
		vis[u] = false;
	} else {
		min!(*ans, d);
	}
}

fn main() {
	let (mut rin,mut rout) = rio();
	const E: f64 = 1e-7;

	let n = rin.u();
	let s = rin.u()-1;
	let mut p = v!([n]);
	rp!{[n]
		l!(x,y = rin.f());
		p.push((x,y));
	}
	let mut o = None;
	'ok: for i in 0..2 {//'
		for j in i+1..3 {
			let d0 = dist(&p, i, j);
			let mut c = 0;
			let mut t = 0;
			for k in 0..n {
				let di = dist(&p, i, k);
				let dj = dist(&p, j, k);
				if (di + dj - d0).abs() < E || ((di - dj).abs() - d0).abs() < E {
					c += 1;
				} else {
					t = k;
				}
			}
			if c >= n-1 {
				assert!(c == n-1);
				o = Some(t);
				break 'ok;//'
			}
		}
	}
	let (p,s,c) = {
		let o = o.unwrap();
		let f = {
			let mut f = 0;
			let mut d = -1.0;
			for i in 0..n {
				if max!(d, dist(&p, i, o)) {
					f = i;
				}
			}
			f
		};
		let mut a = v!([n-1]);
		for i in 0..n {
			if i != o {
				a.push((dist(&p, i, f), i));
			}
		}

		a.sort_by(|x,y| x.partial_cmp(y).unwrap());
		let mut pp = v!([n]);
		let mut ss = n-1;
		for (_,i) in a {
			if i == s {
				ss = pp.len();
			}
			pp.push(p[i]);
		}
		pp.push(p[o]);
		let mut c = 0;
		let mut d = 1e9;
		for i in 0..n-1 {
			if min!(d, dist(&pp, n-1, i)) {
				c = i;
			}
		}
		(pp, ss, c)
	};
	// writeln!(rout, "s {} {:?}  c {} {:?}", s, p[s], c, p[c]).unwrap();
	// writeln!(rout, "{:?}", p).unwrap();
	let mut g = v!([]);
	let m1 = s.min(c);
	let m2 = s.max(c);
	if m1 > 0 {
		g.push([0,m1-1]);
	}
	g.push([m1,m1]);
	if m1+2 <= m2 {
		g.push([m1+1,m2-1]);
	}
	if m1 < m2 {
		g.push([m2,m2]);
	}
	if m2 < n-2 {
		g.push([m2+1,n-2])
	}
	if m2 < n-1 {
		g.push([n-1,n-1]);
	}
	let gn = g.len();
	let mut gs = None;
	for i in 0..gn {
		if g[i][0] == s {
			gs = Some(i);
			break;
		}
	}
	let gs = gs.unwrap();
	let mut v = v!([gn] = false);
	let mut ans = 1e20;
	rec(gn-1, gs, 0, 0.0, &mut v, &mut ans, &p, &g);
	writeln!(rout, "{:.6}", ans).unwrap();
}
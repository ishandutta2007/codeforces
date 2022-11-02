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
}
//----------}}}

fn dfs(u: usize, p: usize, e: &[Vec<usize>], par: &mut [usize], depth: &mut [i32]) {
	for &v in &e[u] {
		if v != p {
			par[v] = u;
			depth[v] = depth[u] + 1;
			dfs(v, u, e, par, depth);
		}
	}
}

fn main() {
	let (mut rin,mut rout) = rio();
	const K: usize = 17;

	l!(n,m,q = rin.u());
	let mut e = v!([n+1][]);
	rp!{[n-1]
		l!(a,b = rin.u());
		e[a].push(b);
		e[b].push(a);
	}
	e[0].push(1);
	let mut p = v!([n+1][]);
	for i in 1..=m {
		p[rin.u()].push(i);
	}
	for i in 1..=n {
		p[i].sort();
		p[i].truncate(10);
	}
	let combine = |a: &[usize], b: &[usize], k: usize| -> Vec<usize> {
		let mut res = a.to_vec();
		res.extend_from_slice(b);
		res.sort();
		// res.dedup();
		res.truncate(k);
		res
	};
	l!(mut par,depth = v!([n+1] = 0));
	dfs(0, 0, &e, &mut par, &mut depth);
	let mut jump = v!([K][n+1] = (0,v!([])));
	for i in 1..=n {
		jump[0][i] = (par[i], p[i].clone());
	}
	for k in 1..K {
		for i in 1..=n {
			let j = jump[k-1][i].0;
			let res = combine(&jump[k-1][i].1, &jump[k-1][j].1, 10);
			jump[k][i] = (jump[k-1][j].0, res);
		}
	}
	rp!{[q]
		l!(u,v,a = rin.u());
		let mut res = v!([]);
		let (mut u,mut v) = if depth[u] >= depth[v] {(u,v)} else {(v,u)};
		for i in (0..17).rev() {
			if depth[v] + (1 << i) <= depth[u] {
				let uu = &jump[i][u];
				res = combine(&res, &uu.1, a);
				u = uu.0;
			}
		}
		if u != v {
			for i in (0..17).rev() {
				let uu = &jump[i][u];
				let vv = &jump[i][v];
				if uu.0 != vv.0 {
					res = combine(&res, &uu.1, a);
					res = combine(&res, &vv.1, a);
					u = uu.0;
					v = vv.0;
				}
			}
			assert!(u != v);
			assert!(par[u] == par[v]);
			res = combine(&res, &p[u], a);
			res = combine(&res, &p[v], a);
			u = par[u];
		}
		let ans = combine(&res, &p[u], a);
		write!(rout, "{}", ans.len()).unwrap();
		for x in ans {
			write!(rout, " {}", x).unwrap();
		}
		writeln!(rout, "").unwrap();
	}
}
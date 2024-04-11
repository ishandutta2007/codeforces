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

fn dfs(u: usize, e: &[Vec<(usize,usize)>], vis: &mut [i8], ei: usize) -> bool {
	vis[u] = 1;
	for &(v,i) in &e[u] {
		if i != ei {
			if vis[v] == 1 || (vis[v] == 0 && !dfs(v, e, vis, ei)) {
				return false;
			}
		}
	}
	vis[u] = 2;
	true
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m = rin.u());
	let mut e = v!([n][]);
	for i in 0..m {
		l!(a,b = rin.u()-1);
		e[a].push((b,i));
	}
	let f = || -> Option<Vec<usize>> {
		for u0 in 0..n {
			let mut q = VecDeque::new();
			let mut from = v!([n] = None);
			q.push_back((u0,0));
			while let Some((u,d)) = q.pop_front() {
				if u == u0 && d > 0 {
					let mut res = v!([d]);
					let mut u = u0;
					rp!{[d]
						let (v,i) = from[u].unwrap();
						res.push(i);
						u = v;
					}
					return Some(res);
				}
				for &(v,i) in &e[u] {
					if from[v].is_none() {
						from[v] = Some((u,i));
						q.push_back((v,d+1));
					}
				}
			}
		}
		None
	};
	if let Some(el) = f() {
		let mut ok = false;
		for ei in el {
			let mut vis = v!([n] = 0_i8);
			let mut ok1 = true;
			for u in 0..n {
				if vis[u] > 0 {
					continue;
				}
				if !dfs(u, &e, &mut vis, ei) {
					ok1 = false;
					break;
				}
			}
			if ok1 {
				ok = true;
				break;
			}
		}
		if !ok {
			writeln!(rout, "NO").unwrap();
			return;
		}
	}
	writeln!(rout, "YES").unwrap();
}
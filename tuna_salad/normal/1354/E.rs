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

fn dfs(u: usize, c: i8, col: &mut [i8], b: &mut [Vec<usize>], e: &[Vec<usize>]) -> bool {
	col[u] = c;
	b[c as usize].push(u);
	for &v in &e[u] {
		if col[v] == -1 {
			if !dfs(v, 1-c, col, b, e) {
				return false;
			}
		} else if col[v] == c {
			return false;
		}
	}
	true
}

fn comp(u: usize, col: &mut [i8], e: &[Vec<usize>]) -> Option<[Vec<usize>;2]> {
	let mut res = [v!([]),v!([])];
	assert!(col[u] == -1);
	if !dfs(u, 0, col, &mut res, e) {
		None
	} else {
		Some(res)
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m = rin.u());
	l!(n1,n2,n3 = rin.u());
	let e = rin.graph(n,m);
	let mut col = v!([n] = -1_i8);
	let mut cc = v!([]);
	for i in 0..n {
		if col[i] == -1 {
			if let Some(x) = comp(i, &mut col, &e) {
				cc.push(x);
			} else {
				writeln!(rout, "NO").unwrap();
				return;
			}
		}
	}
	let m = cc.len();
	let mut dp = v!([m+1][n+1] = -1_i8);
	dp[0][0] = 0;
	for i in 0..m {
		let a = cc[i][0].len();
		let b = cc[i][1].len();
		for j in 0..=n {
			if dp[i][j] >= 0 {
				dp[i+1][j+a] = 0;
				dp[i+1][j+b] = 1;
			}
		}
	}
	if dp[m][n2] == -1 {
		writeln!(rout, "NO").unwrap();
		return;
	}
	let mut ans = v!([n] = 0);
	let mut x = [v!([]), v!([])];
	x[0] = v!([n2] = 2);
	x[1] = v!([n1] = 1);
	x[1].append(&mut v!([n3] = 3));
	let mut j = n2;
	for i in (1..=m).rev() {
		assert!(dp[i][j] >= 0);
		let z = if dp[i][j] == 0 {
			[0,1]
		} else {
			[1,0]
		};
		for k in 0..2 {
			for &y in &cc[i-1][k] {
				ans[y] = x[z[k]].pop().unwrap();
			}
		}
		j -= cc[i-1][z[0]].len();
	}
	writeln!(rout, "YES").unwrap();
	for x in ans {
		write!(rout, "{}", x).unwrap();
	}
}
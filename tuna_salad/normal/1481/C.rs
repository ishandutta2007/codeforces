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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		l!(n,m = rin.u());
		l!(a,b = rin.vu(n));
		let c = rin.vu(m);
		let mut d = v!([n+1][2][]);
		for i in 0..n {
			if a[i] == b[i] {
				d[b[i]][0].push(i);
			} else {
				d[b[i]][1].push(i);
			}
		}
		let mut ans = v!([m]);
		let mut q = 0;
		let mut ok = true;
		for x in c {
			q += 1;
			for i in (0..2).rev() {
				if let Some(j) = d[x][i].pop() {
					d[x][0].push(j);
					rp!{[q]
						ans.push(j);
					}
					q = 0;
					break;
				}
			}
		}
		if q > 0 {
			ok = false;
		} else {
			for i in 1..=n {
				if !d[i][1].is_empty() {
					ok = false;
					break;
				}
			}
		}
		if ok {
			writeln!(rout, "YES").unwrap();
			for x in ans {
				write!(rout, "{} ", x+1).unwrap();
			}
			writeln!(rout, "").unwrap();
		} else {
			writeln!(rout, "NO").unwrap();
		}
	}
}
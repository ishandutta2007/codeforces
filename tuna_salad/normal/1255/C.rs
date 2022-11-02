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
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let mut a = v!([n-2][3]);
	let mut b = v!([n][3]);
	let mut vis = v!([n] = false);
	for i in 0..n-2 {
		l!(x,y,z = rin.u()-1);
		a[i].push(x);
		a[i].push(y);
		a[i].push(z);
		b[x].push(i);
		b[y].push(i);
		b[z].push(i);
	}
	let mut p0 = v!([2][2]);
	for i in 0..n {
		let k = b[i].len() - 1;
		if k < 2 {
			p0[k].push(i);
		}
	}
	let mut p = p0[0][0];
	let mut ans = v!([n]);
	ans.push(p);
	vis[p] = true;
	rp!{[n-4]
		let mut p1 = None;
		let c = b[p].split_off(0);
		for i in c {
			for &j in &a[i] {
				b[j].retain(|&x| x != i);
				if b[j].len() == 1 && !vis[j] {
					p1 = Some(j);
				}
			}
		}
		if let Some(pp) = p1 {
			p = pp;
			ans.push(p);
			vis[p] = true;
		} else {
			break;
		}
	}

	for i in 0..n {
		if !vis[i] && i != p0[0][1] && i != p0[1][0] && i != p0[1][1] {
			ans.push(i);
			break;
		}
	}
	for &x in &p0[1] {
		if !vis[x] {
			ans.push(x);
		}
	}
	ans.push(p0[0][1]);
	for x in ans {
		write!(rout, "{} ", x+1).unwrap();
	}
}
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
	use std::mem::swap;

	rp!{[rin.u()]
		let n = rin.u();
		l!(mut s,t = rin.vb());
		let mut c = v!([26] = false);
		for &x in s.iter().chain(t.iter()) {
			c[(x - b'a') as usize] ^= true;
		}
		let mut ok = true;
		for a in c {
			if a {
				ok = false;
				break;
			}
		}
		if !ok {
			writeln!(rout, "No").unwrap();
			continue;
		}
		writeln!(rout, "Yes").unwrap();
		let mut ans = v!([]);
		while s != t {
			for i in 0..n {
				if s[i] != t[i] {
					let mut f = false;
					for j in i+1..n {
						if s[j] != t[j] && s[i] == s[j] {
							f = true;
							ans.push((i,j));
							swap(&mut s[i], &mut t[j]);
							break;
						}
					}
					if f {
						break;
					}
					for j in i+1..n {
						if s[j] != t[j] && s[i] == t[j] {
							ans.push((j,j));
							swap(&mut s[j], &mut t[j]);
							ans.push((j,i));
							swap(&mut s[j], &mut t[i]);
							break;
						}
					}
					break;
				}
			}
		}

		writeln!(rout, "{}", ans.len()).unwrap();
		for (i,j) in ans {
			writeln!(rout, "{} {}", i+1, j+1).unwrap();
		}
	}
}
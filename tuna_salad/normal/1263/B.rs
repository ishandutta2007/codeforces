//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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

	rp!{[rin.u()]
		let n = rin.u();
		let mut s = v!([n]);
		rp!{[n]
			s.push(rin.vb());
		}
		let mut ans = 0;
		for i in 0..n {
			let mut ok = true;
			for j in i+1..n {
				if s[i] == s[j] {
					ok = false;
					break;
				}
			}
			if !ok {
				let mut p = 0;
				let mut x = b'0';
				while !ok {
					let mut t = s[i].clone();
					if t[p] != x {
						t[p] = x;
						ok = true;
						for j in 0..n {
							if j != i && s[j] == t {
								ok = false;
								break;
							}
						}
						if ok {
							s[i] = t;
							break;
						}
					}
					x += 1;
					if x > b'9' {
						p += 1;
						assert!(p < 4);
						x = b'0';
					}
				}
				ans += 1;
			}
		}
		writeln!(rout, "{}", ans).unwrap();
		for x in s {
			writeln!(rout, "{}", String::from_utf8(x).unwrap()).unwrap();
		}
	}
}
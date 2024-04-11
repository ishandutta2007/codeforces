//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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

	for _ in 0..rin.u() {
		let s = rin.vb();
		let mut c = v!([26] = 0);
		l!(mut a,b = v!([26]));
		for &x in s.iter().rev() {
			let p = (x - b'a') as usize;
			if c[p] == 0 {
				a.push(p);
				b.push(x);
			}
			c[p] += 1;
		}
		a.reverse();
		b.reverse();
		let mut l = 0;
		let mut ok = true;
		let n = a.len();
		for i in 0..n {
			if c[a[i]] % (i+1) != 0 {
				ok = false;
				break;
			}
			l += c[a[i]] / (i+1);
		}
		if s.len() < l {
			ok = false;
		}
		if ok {
			let mut t = s[0..l].to_vec();
			let mut si = s.iter().cloned();
			for x in a {
				if !ok {
					break;
				}
				let x = x as u8 + b'a';
				let mut t1 = v!([]);
				for y in t {
					if y != x {
						t1.push(y);
					}
					if Some(y) != si.next() {
						ok = false;
						break;
					}
				}
				t = t1;
			}
			if si.next() != None {
				ok = false;
			}
		}
		if ok {
			let ans1 = str::from_utf8(&s[0..l]).unwrap();
			let ans2 = str::from_utf8(&b[..]).unwrap();
			writeln!(rout, "{} {}", ans1, ans2).unwrap();
		} else {
			writeln!(rout, "-1").unwrap();
		}
	}
}
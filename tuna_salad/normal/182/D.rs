//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

// Z-Algorithm {{{
fn z_fn(s: &[u8]) -> Vec<i32> {
	let n = s.len();
	assert!(n > 0);
	l!(mut l,r = 0);
	let mut z = vec![0; n];
	z[0] = -1;
	for i in 1..n {
		if i <= r && z[i-l] < (r as i32) - (i as i32) +1 {
			z[i] = z[i-l];
		} else {
			l = i;
			max!(r, l);
			while r < n && s[r-l] == s[r] {
				r += 1;
			}
			z[i] = (r as i32) - (l as i32);
			r -= 1;
		}
	}
	z
}//}}}

fn gcd(mut a: usize, mut b: usize) -> usize {
	while b != 0 {
		let c = a % b;
		a = b;
		b = c;
	}
	a
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(a,b = rin.vb());
	let an = a.len();
	let bn = b.len();
	for i in 0..an.max(bn) {
		if a[i % an] != b[i % bn] {
			writeln!(rout, "0").unwrap();
			return;
		}
	}
	let c = gcd(a.len(),b.len());
	for x in &[&a,&b] {
		for i in 0..x.len() {
			if x[i] != x[i%c] {
				writeln!(rout, "0").unwrap();
				return;
			}
		}
	}
	let z = z_fn(&a[0..c]);
	let mut ans = 1;
	for i in 1..c {
		if z[i] as usize + i == c && c % i == 0 {
			ans += 1;
		}
	}
	writeln!(rout, "{}", ans).unwrap();
}
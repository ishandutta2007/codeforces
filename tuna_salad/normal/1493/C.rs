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

fn rec(k: usize, m: usize, eq: bool, s: &[u8], c: &mut [usize], ans: &mut Vec<u8>) -> bool {
	// println!(
	//	"rec {} {} {} {} {:?} {}",
	//	k, m, eq, str::from_utf8(s).unwrap(),
	//	c, str::from_utf8(ans).unwrap(),
	// );
	if s.len() > 0 {
		let a = if eq {(s[0] - b'a') as usize} else {0};
		for i in a..26 {
			let x = if c[i] == 0 && m > 0 {
				c[i] += k;
				1
			} else {
				0
			};
			if c[i] > 0 {
				c[i] -= 1;
				let y = i as u8 + b'a';
				ans.push(y);
				if rec(k, m-x, eq && s[0] == y, &s[1..], c, ans) {
					return true;
				}
				ans.pop();
				c[i] += 1;
				if x > 0 {
					c[i] = 0;
				}
			}
		}
		false
	} else {
		true
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		l!(n,k = rin.u());
		let s = rin.vb();
		if n % k != 0 {
			writeln!(rout, "-1").unwrap();
			continue;
		}
		let mut c = v!([26] = 0);
		let mut ans = v!([n]);
		let res = rec(k, n/k, true, &s, &mut c, &mut ans);
		assert!(res);
		writeln!(rout, "{}", String::from_utf8(ans).unwrap()).unwrap();
	}
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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

fn rec(u: usize, t: &mut Vec<[usize;27]>, s: &[(u8,bool)]) {
	if s.len() > 0 {
		let (c,g) = s[0];
		let p = (c - b'a') as usize;
		if t[u][p] == 0 {
			let v = t.len();
			t[u][p] = v;
			t.push([0;27]);
			t[v][26] = t[u][26] + g as usize;
		}
		rec(t[u][p], t, &s[1..]);
	}
}

fn count(u: usize, k: usize, t: &[[usize;27]], ans: &mut usize) {
	if t[u][26] <= k {
		*ans += 1;
		for p in 0..26 {
			if t[u][p] != 0 {
				count(t[u][p], k, t, ans);
			}
		}
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(s,g = rin.vb());
	let k = rin.u();
	let n = s.len();
	let s = {
		let mut ss = v!([n]);
		for c in s {
			ss.push( (c, g[(c - b'a') as usize] == b'0') );
		}
		ss
	};
	let mut t = v!([]);
	t.push([0;27]);
	for i in 0..n {
		rec(0, &mut t, &s[i..]);
	}
	let mut ans = 0;
	count(0, k, &t, &mut ans);
	ans -= 1;
	writeln!(rout, "{}", ans).unwrap();
}
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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
	fn l(&mut self) ->    i64 { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	l!(n,m = rin.u());
	let b = {
		let k = rin.l();
		let mut b = v!([n]);
		rp!{[n]
			b.push(rin.vl(m));
		}
		b[0][0] ^= k;
		b
	};
	if min(n,m) == 1 {
		let mut s = 0;
		for i in 0..n {
			for j in 0..m {
				s ^= b[i][j];
			}
		}
		let ans = if s == 0 {1} else {0};
		writeln!(rout, "{}", ans).unwrap();
		return;
	}
	let mut h = HashMap::<(usize,i64),(i32,i32)>::new();
	let k = (n+m-2) / 2;
	'st: for mut bb in 0..1 << k {
		l!(mut i,j = 0);
		let mut x = b[0][0];
		rp!{[k]
			if bb & 1 == 0 {
				j += 1;
			} else {
				i += 1;
			}
			if i >= n || j >= m {
				continue 'st;
			}
			x ^= b[i][j];
			bb >>= 1;
		}
		h.entry((i,x)).or_insert((0,0)).0 += 1;
	}
	let k = (n+m-1) / 2;
	'st2: for mut bb in 0..1 << k {
		let mut i = n;
		let mut j = m;
		let mut x = 0;
		rp!{[k]
			x ^= b[i-1][j-1];
			if bb & 1 == 0 {
				j -= 1;
			} else {
				i -= 1;
			}
			if min(i,j) == 0 {
				continue 'st2;
			}
			bb >>= 1;
		}
		h.entry((i-1,x)).or_insert((0,0)).1 += 1;
	}
	let mut ans = 0;
	for (_,(x,y)) in h {
		ans += x as i64 * y as i64;
	}
	writeln!(rout, "{}", ans).unwrap();
}
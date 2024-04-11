//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const X: usize = 600;
	const N: usize = 505;

	l!(n,q = rin.u());
	let a = rin.vu(n);
	let mut buckets = v!([N][]);
	let mut ans = v!([q] = 0);
	for i in 0..q {
		l!(l,r = rin.u()-1);
		buckets[r/X].push( (l,r,i) );
	}
	l!(mut l,r = 0);
	l!(mut c,cc = v!([n+1] = 0));
	c[a[0]] = 1;
	cc[0] = n;
	cc[1] = 1;
	let add = |c: &mut [usize], cc: &mut [usize], p: usize, c_max: &mut usize| {
		cc[c[p]] -= 1;
		c[p] += 1;
		cc[c[p]] += 1;
		max!(*c_max, c[p]);
	};
	let sub = |c: &mut [usize], cc: &mut [usize], p: usize, c_max: &mut usize| {
		cc[c[p]] -= 1;
		c[p] -= 1;
		cc[c[p]] += 1;
		if cc[*c_max] == 0 {
			*c_max -= 1;
		}
	};
	let mut c_max = 1;
	for i in 0..N {
		buckets[i].sort();
		for (ll,rr,id) in buckets[i].drain(..) {
			while r < rr {
				r += 1;
				add(&mut c, &mut cc, a[r], &mut c_max);
			}
			while ll < l {
				l -= 1;
				add(&mut c, &mut cc, a[l], &mut c_max);
			}
			while rr < r {
				sub(&mut c, &mut cc, a[r], &mut c_max);
				r -= 1;
			}
			while l < ll {
				sub(&mut c, &mut cc, a[l], &mut c_max);
				l += 1;
			}
			let m = c_max;
			let o = r - l + 1 - m;
			ans[id] = max(o+1, m) - o;
		}
	}
	for x in ans {
		writeln!(rout, "{}", x).unwrap();
	}
}
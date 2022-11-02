//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};}
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
	fn i(&mut self) ->    i32 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const K: usize = 300;

	let n = rin.u();
	let a = rin.vu(n);
	let g = (n + K - 1) / K;
	let mut b = v!([g] = VecDeque::with_capacity(K+1));
	let mut c = v!([g][n+1] = 0);
	let mut ii = v!([g]);
	for i in 0..g {
		let x = i * K;
		let y = ((i+1)*K - 1).min(n-1);
		ii.push((x,y));
	}
	for i in 0..n {
		let j = i / K;
		let x = a[i];
		b[j].push_back(x);
		c[j][x] += 1;
	}
	let mut last_ans = 0;
	rp!{[rin.u()]
		let t = rin.i();
		l!(mut l,r = (last_ans + rin.u() - 1) % n);
		if l > r {
			std::mem::swap(&mut l, &mut r);
		}
		if t == 1 {
			let gl = l / K;
			let gr = r / K;
			let x0 = b[gr].remove(r - ii[gr].0).unwrap();
			b[gl].insert(l - ii[gl].0, x0);
			if gl < gr {
				c[gr][x0] -= 1;
				for i in (gl+1..=gr).rev() {
					let x = b[i-1].pop_back().unwrap();
					c[i-1][x] -= 1;
					b[i].push_front(x);
					c[i][x] += 1;
				}
				c[gl][x0] += 1;
			}
		} else {
			let x = (last_ans + rin.u() - 1) % n + 1;
			let mut ans = 0;
			for i in 0..g {
				let ll = l.max(ii[i].0);
				let rr = r.min(ii[i].1);
				if (ll,rr) == ii[i] {
					ans += c[i][x];
				} else if ll <= rr {
					for j in ll..=rr {
						if b[i][j - ii[i].0] == x {
							ans += 1;
						}
					}
				}
			}
			writeln!(rout, "{}", ans).unwrap();
			last_ans = ans;
		}
	}
}
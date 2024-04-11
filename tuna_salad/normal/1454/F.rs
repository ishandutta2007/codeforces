//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

mod sparse {
	use super::*;
	type S = i32;
	fn combine(a: S, b: S) -> S {
		min(a,b)
	}
	pub struct Table {
		n: usize,
		t: Vec<Vec<S>>,
	}
	impl Table {
		pub fn new(a: Vec<S>) -> Self {
			let n = a.len();
			assert!(n >= 1);
			let m = Self::base(n) + 1;
			let mut t = v!([m]);
			t.push(a);
			for i in 1..m {
				let l = 1 << i;
				let l2 = l >> 1;
				let mut s = v!([n-l+1]);
				for j in 0..=n-l {
					s.push( min(t[i-1][j], t[i-1][j+l2]) );
				}
				t.push(s);
			}
			Self {n, t}
		}
		fn base(n: usize) -> usize {
			assert!(n >= 1);
			let mut m = 1;
			while (1 << m) <= n {
				m += 1;
			}
			m - 1
		}
		pub fn calc(&self, l: usize, r: usize) -> S {
			assert!(l <= r);
			assert!(r < self.n);
			let n = r - l + 1;
			let m = Self::base(n);
			combine(self.t[m][l], self.t[m][r+1-(1<<m)])
		}
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		let n = rin.u();
		let a = rin.vi(n);
		let st = sparse::Table::new(a.clone());
		l!(mut ml,mr = v!([n]));
		{
			l!(mut x,y = 0);
			for i in 0..n {
				max!(x, a[i]);
				ml.push(x);
				max!(y, a[n-i-1]);
				mr.push(y);
			}
			mr.reverse();
		}
		let mut l = 0;
		let mut r = n-1;
		let mut ans = None;
		while l <= r {
			if ml[l] < mr[r] {
				l += 1;
			} else if ml[l] > mr[r] {
				r -= 1;
			} else {
				let mut ll = l;
				while ll+1 < n && ml[l] == ml[ll+1] {
					ll += 1;
				}
				if ll >= r {
					for i in l+1..r {
						if a[i] == ml[l] {
							ans = Some( (i,1,n-i-1) );
							break;
						}
					}
					break;
				}
				let mut rr = r;
				while rr > 0 && mr[rr-1] == mr[r] {
					rr -= 1;
				}
				assert!(ll + 1 < rr);
				let mid = st.calc(ll+1, rr-1);
				if mid == ml[l] {
					ans = Some( (ll+1, rr-ll-1, n-rr) );
					break;
				} else if mid > ml[l] {
					if l < ll && a[ll] == ml[l] {
						ans = Some( (ll, rr-ll, n-rr) );
						break;
					}
					if rr < r && a[rr] == mr[r] {
						ans = Some( (ll+1, rr-ll, n-rr-1) );
						break;
					}
				}
				l = ll+1;
				r = rr-1;
			}
		}
		if let Some( (x,y,z) ) = ans {
			writeln!(rout, "YES").unwrap();
			writeln!(rout, "{} {} {}", x, y, z).unwrap();
		} else {
			writeln!(rout, "NO").unwrap();
		}
	}
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
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

fn manacher_sub(s: &[u8]) -> (Vec<usize>,Vec<usize>) {
	let n = s.len();
	let ni = n as i32;
	l!(mut r_odd, r_even = vec![0; n]);
	let mut l = 0_i32;
	let mut r = -1_i32;
	for i in 0..n {
		let ii = i as i32;
		let mut k = if ii > r {
			1
		} else {
			(r_odd[(l + r - ii) as usize] as i32).min(r + 1 - ii)
		};
		while 0 <= ii - k && ii + k < ni && s[i - k as usize] == s[i + k as usize] {
			k += 1;
		}
		r_odd[i] = k as usize;
		k -= 1;
		if r < ii + k {
			l = ii - k;
			r = ii + k;
		}
	}
	l = 0;
	r = -1;
	for i in 0..n {
		let ii = i as i32;
		let mut k = if ii > r {
			0
		} else {
			(r_even[(l + r + 1 - ii) as usize] as i32).min(r + 1 - ii)
		};
		while 0 <= ii - k - 1 && ii + k < ni && s[i - k as usize - 1] == s[i + k as usize] {
			k += 1;
		}
		r_even[i] = k as usize;
		k -= 1;
		if r < ii + k {
			l = ii - k - 1;
			r = ii + k;
		}
	}
	(r_odd, r_even)
}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		let s = rin.vb();
		let n = s.len();
		let (o,e) = manacher_sub(&s);
		let mut l = 0;
		let mut r = n;
		while l < r {
			if s[l] != s[r-1] {
				break;
			}
			l += 1;
			r -= 1;
		}
		if l >= r {
			writeln!(rout, "{}", String::from_utf8(s).unwrap()).unwrap();
		} else {
			let mut ans = 2*l;
			let mut res = (0,0);
			for p in l..n-l {
				let x = o[p];
				let mut t = None;
				if p*2 < n {
					if p <= x+l-1 {
						t = Some(p-l+1);
					}
				} else {
					if p+x >= n-l {
						t = Some(n-l-p);
					}
				}
				if let Some(t) = t {
					if max!(ans, 2*l + 2*t - 1) {
						res = (p+1-t, p+t);
					}
				}
			}
			for p in l+1..n-l {
				let x = e[p];
				let mut t = None;
				if p*2 < n {
					if p-l <= x {
						t = Some(p-l);
					}
				} else {
					if p+x >= n-l {
						t = Some(n-l-p);
					}
				}
				if let Some(t) = t {
					if max!(ans, 2*l + 2*t) {
						res = (p-t, p+t);
					}
				}
			}
			for x in vec![0..l, res.0..res.1, n-l..n] {
				for i in x {
					write!(rout, "{}", s[i] as char).unwrap();
				}
			}
			writeln!(rout, "").unwrap();
		}
	}
}
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
	fn u(&mut self) ->  usize { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let put = |t: &mut Vec<(i32, [usize;2])>, x: i32, a: i32| {
		let mut u = 0;
		t[u].0 += a;
		for i in (0..30).rev() {
			let j = ((x >> i) & 1) as usize;
			if t[u].1[j] == 0 {
				t[u].1[j] = t.len();
				t.push((0,[0,0]));
			}
			u = t[u].1[j];
			t[u].0 += a;
		}
	};
	let find = |t: &[(i32, [usize;2])], x: i32| -> i32 {
		l!(mut u,res = 0);
		for i in (0..30).rev() {
			res <<= 1;
			let j = ((x >> i) & 1) as usize ^ 1;
			let j = if t[u].1[j] > 0 && t[t[u].1[j]].0 > 0 {
				res |= 1;
				j
			} else {
				j^1
			};
			u = t[u].1[j];
		}
		res
	};

	let mut t = v!([1] = (0,[0,0]));
	put(&mut t, 0, 1);

	rp!{[rin.u()]
		let c = rin.vb()[0];
		let x = rin.i();
		if c == b'?' {
			let ans = find(&t, x);
			writeln!(rout, "{}", ans).unwrap();
		} else {
			let a = if c == b'+' {
				1
			} else {
				-1
			};
			put(&mut t, x, a);
		}
	}
}
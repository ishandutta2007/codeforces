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
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

// Coordinate compression {{{
fn compress<T: Ord>(a: &[T], start_from: usize) -> (usize, Vec<usize>) {
	let n = a.len();
	let mut t = Vec::with_capacity(n);
	for i in 0..n {
		t.push(i);
	}
	t.sort_by(|x,y| a[*x].cmp(&a[*y]));
	let mut b = vec![0; n];
	let mut v = start_from;
	for i in 0..n {
		if i > 0 && a[t[i-1]] < a[t[i]] {
			v += 1;
		}
		b[t[i]] = v;
	}
	(v, b)
}//}}}

// Fenwick Tree {{{
mod fenwick {
	type V = i32;
	pub struct Tree {
		n: usize,
		pub arr: Box<[V]>
	}
	impl Tree {
		pub fn new(n: usize) -> Self {
			let arr = vec![0; n + 1].into_boxed_slice();
			Self { n, arr }
		}
		pub fn add(&mut self, p: usize, v: V) {
			let mut p = p as i32 + 1;
			let n = self.n as i32;
			while p <= n {
				self.arr[p as usize] += v;
				p += p & -p;
			}
		}
		pub fn sum(&self, p: usize) -> V {
			let mut p = p as i32 + 1;
			let mut res = 0;
			while p > 0 {
				res += self.arr[p as usize];
				p -= p & -p;
			}
			res
		}
	}
}//}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	l!(mut o,s = v!([n]));
	rp!{[n]
		l!(a,b,c = rin.u());
		o.push((a,b));
		s.push(c);
	}
	let (m,ss) = compress(&s,0);
	let m = m+1;
	let mut ot = v!([m][]);
	for i in 0..n {
		ot[ss[i]].push(o[i].1);
	}
	let mut ft = v!([m]);
	for i in 0..m {
		let (z,mut t) = compress(&ot[i],0);
		assert!(z+1 == ot[i].len());
		t.reverse();
		ot[i] = t;
		ft.push(fenwick::Tree::new(z+1));
	}
	for i in 0..n {
		let j = ss[i];
		let a = o[i].0;
		let b = ot[j].pop().unwrap();
		if a == 3 {
			let ans = ft[j].sum(b);
			writeln!(rout, "{}", ans).unwrap();
		} else {
			let v = if a == 1 {1} else {-1};
			ft[j].add(b, v);
		}
	}
}
//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
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
}
//----------}}}

mod fenwick {
	type V = i64;
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
}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let mut ft = fenwick::Tree::new(n);
	let mut a = rin.vl(n);
	let mut ans = 0;
	let mut s = v!([n]);
	let mut t = BTreeMap::new();
	for i in 0..n {
		if a[i] >= 0 {
			if a[i] > 0 {
				t.insert(i, a[i]);
			}
			ft.add(i, a[i]);
			ans += 1;
		} else {
			s.push( (-a[i], i) );
		}
	}
	s.sort();
	for (mut v,i) in s {
		if ft.sum(i) >= v {
			let mut z = v!([]);
			let mut it = t.range(..i).rev();
			while v > 0 {
				let (&j,&y) = it.next().unwrap();
				if y <= v {
					z.push( (j,0) );
					v -= y;
				} else {
					z.push( (j,y-v) );
					v = 0;
				}
			}
			for (j,y) in z {
				ft.add(j, y-a[j]);
				a[j] = y;
				if y == 0 {
					t.remove(&j);
				} else {
					t.insert(j,y);
				}
			}
			ans += 1;
		}
	}
	writeln!(rout, "{}", ans).unwrap();
}
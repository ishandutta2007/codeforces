//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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
	fn i(&mut self) ->    i32 { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let f = |h: &mut HashMap<i32,i32>, l: &mut BTreeSet<(i32,i32)>, x: i32, y: i32| {
		let e = h.entry(x).or_insert(0);
		l.remove( &(*e,x) );
		*e += y;
		l.insert( (*e,x) );
	};
	let mut h = HashMap::new();
	let mut l = BTreeSet::new();
	rp!{[rin.u()]
		f(&mut h, &mut l, rin.i(), 1);
	}
	rp!{[rin.u()]
		let y = if rin.vb()[0] == b'+' {1} else {-1};
		let x = rin.i();
		f(&mut h, &mut l, x, y);
		let mut a = l.iter().rev().take(3).map(|&(z,_)| z).collect::<Vec<_>>();
		let mut ok = true;
		for &c in &[4,2,2] {
			ok = false;
			for x in a.iter_mut() {
				if *x >= c {
					*x -= c;
					ok = true;
					break;
				}
			}
			if !ok {
				break;
			}
		}
		if ok {
			writeln!(rout, "YES").unwrap();
		} else {
			writeln!(rout, "NO").unwrap();
		}
	}
}
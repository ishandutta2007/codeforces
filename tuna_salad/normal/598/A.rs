//spnauti-rust
use std::io::*;
use std::str::*;
use std::fmt::Debug;
#[allow(unused_imports)] use std::cmp::Ordering::*;
#[allow(unused_imports)] use std::collections::*;

#[allow(unused_macros)]
macro_rules! a {
    ($c: tt, $x: expr, $y: expr) => {{
        let b = $y; let a = &mut $x;
        if b $c *a { *a = b; true } else { false }
    }};
}
struct WordReader<'a> { it : SplitAsciiWhitespace<'a>, }
#[allow(dead_code)]
impl<'a> WordReader<'a> {
    fn new<T: Read>(b: &mut String, mut r: T) -> WordReader {
        b.clear();
        r.read_to_string(b).ok();
        WordReader { it: b.split_ascii_whitespace() }
    }
    fn from_stdin(b: &mut String) -> WordReader {
        WordReader::new(b, stdin())
    }
    fn sl(&mut self) ->  &str { self.it.next().unwrap() }
    fn bs(&mut self) -> &[u8] { self.sl().as_bytes()    }
    fn s(&mut self) -> String { String::from(self.sl()) }
    fn i(&mut self) ->    i32 { self.p()                }
    fn u(&mut self) ->  usize { self.p()                }
    fn vi(&mut self, n: usize) -> Vec<i32> {
        self.vp::<i32>(n)
    }
    fn p<T: FromStr>(&mut self) -> T where T::Err: Debug {
        self.sl().parse::<T>().unwrap()
    }
    fn vp<T: FromStr>(&mut self, n: usize) -> Vec<T> where T::Err: Debug {
        (0..n).map(|_| self.p()).collect()
    }
}

#[allow(dead_code)]
fn build_counting_hashmap<K: Eq + std::hash::Hash, T>(i: T) -> HashMap<K,usize>
    where T: Iterator<Item = K> {
    let mut m = HashMap::new();
    for k in i {
        let n = 1 + if let Some(&n) = m.get(&k) { n } else { 0 };
        m.insert(k, n);
    }
    m
}

fn main() {
    let mut bin = String::new();
    let mut input = WordReader::from_stdin(&mut bin);
    let mut bout = BufWriter::new(stdout());

    let q = input.u();
    for _ in 0..q {
        let n: i64 = input.p();
        let mut res = n * (n + 1) / 2;
        let mut x = 1;
        while x <= n {
            x <<= 1;
            res -= x;
        }
        writeln!(bout, "{}", res).ok();
    }
}
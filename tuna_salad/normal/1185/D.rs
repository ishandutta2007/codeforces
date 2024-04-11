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

fn test(a: &Vec<(usize,i32)>, p: usize) -> bool {
    let mut b = a.clone();
    b.remove(p);
    let d = b[1].1 - b[0].1;
    for i in 1..b.len() {
        if b[i].1 - b[i-1].1 != d {
            return false;
        }
    }
    true
}

fn main() {
    let mut bin = String::new();
    let mut input = WordReader::from_stdin(&mut bin);

    let n = input.u();
    if n == 2 {
        println!("1");
        return;
    }
    let mut a = input.vi(n).into_iter().enumerate().collect::<Vec<(usize,i32)>>();
    a.sort_by(|(a,b),(c,d)| if b != d { b.cmp(&d) } else { a.cmp(&c) });
    for i in 0..3 {
        if test(&a, i) {
            println!("{}", a[i].0 + 1);
            return;
        }
    }

    if a[2].1 - a[1].1 != a[1].1 - a[0].1 {
        println!("-1");
        return;
    }
    for i in 3..n {
        if a[i].1 - a[i-1].1 != a[i-1].1 - a[i-2].1 {
            if test(&a, i) {
                println!("{}", a[i].0 + 1);
                return;
            }
            break;
        }
    }
    println!("-1");
}
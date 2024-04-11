//spnauti-rust
#[allow(unused_macros)]
macro_rules! a {
    ($c: tt, $x: expr, $y: expr) => {{
        let b = $y; let a = &mut $x;
        if b $c *a { *a = b; true } else { false }
    }};
}
use std::io::*;
use std::str::*;
use std::fmt::Debug;
struct WordReader<'a> { it : SplitAsciiWhitespace<'a>, }
#[allow(dead_code)]
impl<'a> WordReader<'a> {
    fn new<T: Read>(b: &mut String, mut r: T) -> WordReader {
        b.clear();
        r.read_to_string(b).unwrap();
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

fn main() {
    let mut bin = String::new();
    let mut input = WordReader::from_stdin(&mut bin);

    let n = input.i();
    let x: i64 = input.p();
    let sol = (0..n).fold((x,0), |(i,d),_| {
        let plus = input.bs()[0] == b'+';
        let a: i64 = input.p();
        if plus {
            (i + a, d)
        } else if i >= a {
            (i - a, d)
        } else {
            (i, d + 1)
        }
    });
    println!("{} {}", sol.0, sol.1);
}
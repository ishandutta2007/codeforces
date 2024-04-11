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
    let mut bout = BufWriter::new(stdout());

    let find_c_in_rc = |s: &[u8]| {
        if s[0] == b'R' && s[1] <= b'9' {
            s[2..].iter().position(|&x| x == b'C')
        } else {
            None
        }
    };
    let to_a1 = |mut c: i32| -> String {
        c -= 1;
        let mut x = 1;
        for l in 1.. {
            x *= 26;
            if c < x {
                let mut a = vec![0; l];
                for i in (0..l).rev() {
                    a[i] = (b'A' as i32 + c % 26) as u8;
                    c /= 26;
                }
                return String::from_utf8(a).unwrap();
            }
            c -= x;
        }
        String::new()
    };
    let to_c = |a: &[u8]| -> i32 {
        let mut res1 = 0;
        let mut res2 = 0;
        let mut x = 1;
        let l = a.len();
        for i in 0..l {
            res1 *= 26;
            res1 += (a[i] - b'A') as i32;
            res2 += x;
            x *= 26;
        }
        res1 + res2
    };

    let n = input.u();
    for _ in 0..n {
        let s = input.bs();
        if let Some(p) = find_c_in_rc(s) {
            let p = p + 2;
            let r = String::from_utf8(s[1..p].to_vec()).unwrap();
            let c = String::from_utf8(s[p+1..].to_vec()).unwrap();
            writeln!(bout, "{}{}", to_a1(c.parse().unwrap()), r).ok();
        } else {
            let p = s.iter().position(|&c| c <= b'9').unwrap();
            let r = String::from_utf8(s[p..].to_vec()).unwrap();
            writeln!(bout, "R{}C{}", r, to_c(&s[..p])).ok();
        }
    }
}
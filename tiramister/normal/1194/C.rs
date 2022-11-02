use std::io::*;
use std::str::FromStr;

fn solve(s: Vec<char>, t: Vec<char>, p: Vec<char>) -> bool {
    let mut pcnt = vec![0; 26];
    for c in p {
        let idx = (c as u8 - b'a') as usize;
        pcnt[idx] += 1;
    }

    let mut si = 0;
    for c in t {
        if si < s.len() && s[si] == c {
            si += 1;
        } else {
            let idx = (c as u8 - b'a') as usize;
            if pcnt[idx] == 0 {
                return false;
            } else {
                pcnt[idx] -= 1;
            }
        }
    }
    si == s.len()
}

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let q: usize = sc.next();
    for _ in 0..q {
        let s = sc.chars();
        let t = sc.chars();
        let p = sc.chars();
        println!("{}", if solve(s, t, p) { "YES" } else { "NO" });
    }
}

/* ========== Scanner ========== */

struct Scanner<R: Read> {
    reader: R,
}

#[allow(dead_code)]
impl<R: Read> Scanner<R> {
    fn new(reader: R) -> Scanner<R> {
        Scanner { reader: reader }
    }

    fn read<T: FromStr>(&mut self) -> Option<T> {
        let token = self
            .reader
            .by_ref()
            .bytes()
            .map(|c| c.unwrap() as char)
            .skip_while(|c| c.is_whitespace())
            .take_while(|c| !c.is_whitespace())
            .collect::<String>();
        if token.is_empty() {
            None
        } else {
            token.parse::<T>().ok()
        }
    }

    fn next<T: FromStr>(&mut self) -> T {
        if let Some(s) = self.read() {
            s
        } else {
            writeln!(stderr(), "Terminated with EOF").unwrap();
            std::process::exit(0);
        }
    }

    fn vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next()).collect()
    }

    fn chars(&mut self) -> Vec<char> {
        self.next::<String>().chars().collect()
    }

    fn char(&mut self) -> char {
        self.next::<String>().chars().next().unwrap()
    }
}
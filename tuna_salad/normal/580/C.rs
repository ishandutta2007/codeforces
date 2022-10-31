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

use std::vec::Vec;
struct Graph {
    edges: Vec<Vec<usize>>,
    visited: Vec<bool>,
    cat: Vec<bool>
}

fn rec(g: &mut Graph, m: usize, u: usize, c: usize) -> usize {
    g.visited[u] = true;
    let c = if g.cat[u] { c + 1 } else { 0 };
    if c > m { return 0; }

    let a = {
        let a = g.edges[u].clone();
        a.into_iter().filter(|&x| !g.visited[x]).collect::<Vec<_>>()
    };
    if a.len() == 0 { return 1; }

    a.into_iter().map(|v| rec(g, m, v, c)).sum()
}

fn main() {
    let mut bin = String::new();
    let mut input = WordReader::from_stdin(&mut bin);

    let n = input.u();
    let m = input.u();
    let mut g = {
        let cat = input.vi(n).into_iter()
            .map(|x| x == 1).collect();
        let mut edges = vec![vec![]; n];
        for _ in 1..n {
            let (a, b) = (input.u() - 1, input.u() - 1);
            edges[a].push(b);
            edges[b].push(a);
        }
        let visited = vec![false; n];
        Graph { edges, visited, cat }
    };
    let sol = rec(&mut g, m, 0, 0);
    println!("{}", sol);
}
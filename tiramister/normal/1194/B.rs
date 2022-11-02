use std::io::*;
use std::str::FromStr;

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let q: usize = sc.next();

    for _ in 0..q {
        let n: usize = sc.next();
        let m: usize = sc.next();

        let grid: Vec<Vec<char>> = (0..n)
            .map(|_| sc.next::<String>().chars().collect())
            .collect();

        let col: Vec<usize> = (0..n)
            .map(|i| (0..m).filter(|&j| grid[i][j] == '.').count())
            .collect();
        let row: Vec<usize> = (0..m)
            .map(|j| (0..n).filter(|&i| grid[i][j] == '.').count())
            .collect();

        let mut ans: usize = std::usize::MAX;
        for i in 0..n {
            for j in 0..m {
                let mut sum = col[i] + row[j];
                if grid[i][j] == '.' {
                    sum -= 1;
                }
                ans = std::cmp::min(ans, sum);
            }
        }

        println!("{}", ans);
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

    fn char(&mut self) -> char {
        self.next::<String>().chars().next().unwrap()
    }
}
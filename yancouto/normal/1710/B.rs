use std::collections::*;

fn get_line() -> String {
    let mut line = String::new();
    while line.is_empty() {
        std::io::stdin().read_line(&mut line).unwrap();
    }
    line
}

macro_rules! read_line {
    ( $($name:ident : $typ:ty),+ ) => {
        let line = get_line();
        let mut tokens = line.split_ascii_whitespace();
        $(
            let $name: $typ = tokens.next().unwrap().parse().unwrap();
        )+
        debug_assert_eq!(tokens.next(), None);
    };
}

fn accumulate(acc: &mut BTreeMap<i64, i64>, eq_middle: bool) {
    let mut sum = 0i64;
    let mut last = -1000000003i64;
    let mut prev_raw = 0i64;
    for (i, v) in acc {
        let prev_v = *v;
        if eq_middle {
            // sum's in the middle
            *v += sum + prev_raw * (i - last - 1);
        } else {
            // 0's in the middle
            *v += sum;
        }
        prev_raw = prev_v;
        sum = *v;
        last = *i;
    }
}

struct SegTree {
    v: Vec<i64>,
    n: usize,
}

impl SegTree {
    fn new(val: &[i64]) -> Self {
        let mut seg = Self {
            v: vec![0; 4 * val.len() + 100],
            n: val.len(),
        };
        seg.init(1, 0, val.len() - 1, val);
        seg
    }
    fn init(&mut self, i: usize, l: usize, r: usize, val: &[i64]) {
        if l == r {
            self.v[i] = val[l];
            return;
        }
        let m = (l + r) / 2;
        self.init(2 * i, l, m, val);
        self.init(2 * i + 1, m + 1, r, val);
        self.v[i] = self.v[2 * i].max(self.v[2 * i + 1]);
    }
    fn max_impl(&self, i: usize, l: usize, r: usize, ql: usize, qr: usize) -> i64 {
        if l > qr || r < ql {
            return i64::MIN;
        }
        if l >= ql && r <= qr {
            return self.v[i];
        }
        let m = (l + r) / 2;
        self.max_impl(2 * i, l, m, ql, qr)
            .max(self.max_impl(2 * i + 1, m + 1, r, ql, qr))
    }
    fn max(&self, l: usize, r: usize) -> i64 {
        let ans = self.max_impl(1, 0, self.n - 1, l, r);
        ans
    }
}

fn solve() {
    let mut acc: BTreeMap<i64, i64> = BTreeMap::new();
    read_line!(n: usize, m: i64);
    let mut xp = Vec::with_capacity(n);
    for _ in 0..n {
        read_line!(xi: i64, pi: i64);
        xp.push((xi, pi));
        acc.entry(xi - pi).or_insert(0);
        *acc.entry(xi - pi + 1).or_insert(0) += 1;
        acc.entry(xi).or_insert(0);
        *acc.entry(xi + 1).or_insert(0) -= 2;
        acc.entry(xi + pi - 1).or_insert(0);
        acc.entry(xi + pi).or_insert(0);
        *acc.entry(xi + pi + 1).or_insert(0) += 1;
    }
    accumulate(&mut acc, false);
    accumulate(&mut acc, true);
    let values_plus: Vec<i64> = acc.iter().map(|(i, xi)| xi + i).collect();
    let values_minus: Vec<i64> = acc.iter().map(|(i, xi)| xi - i).collect();
    let values_normal: Vec<i64> = acc.iter().map(|(_, xi)| *xi).collect();
    let mut idx_map: BTreeMap<i64, usize> = BTreeMap::new();
    let mut idx: usize = 0;
    for (i, _) in acc {
        idx_map.insert(i, idx);
        idx += 1;
    }
    let idx = |i: i64| *idx_map.get(&i).unwrap();
    let seg_plus = SegTree::new(&values_plus);
    let seg_minus = SegTree::new(&values_minus);
    let seg_normal = SegTree::new(&values_normal);
    for (x, p) in xp {
        let floods = seg_normal.max(idx(x + p), idx_map.len() - 1) > m
            || seg_normal.max(0, idx(x - p)) > m
            || seg_minus.max(idx(x - p + 1), idx(x)) > m + p - x
            || seg_plus.max(idx(x), idx(x + p - 1)) > m + p + x;
        if floods {
            print!("0");
        } else {
            print!("1");
        }
    }
    println!("");
}

fn main() {
    read_line!(t: usize);
    for _ in 0..t {
        solve();
    }
}
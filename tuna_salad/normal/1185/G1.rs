//spnauti-rust
use std::io::*;
use std::str::*;
use std::fmt::Debug;
#[allow(unused_imports)] use std::cmp::Ordering::{self,*};
#[allow(unused_imports)] use std::ops::*;
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

const P5: i32 = 1_000_000_007;
const P6: i64 = P5 as i64;
#[derive(Debug,Clone,Copy)]
struct Field(i32);
#[allow(dead_code)]
impl Field {
    fn new<T: Into<i64>>(a: T) -> Self { Self(Self::cv(a)) }
    fn new_unchecked(a: i32) -> Self { Self(a) }
    fn hi(mut a: i32) -> i32 { if a >= P5 { a -= P5; } a }
    fn lo(mut a: i32) -> i32 { if a < 0 { a += P5; } a }
    fn cv<T: Into<i64>>(a: T) -> i32 { Self::lo((a.into() % P6) as i32) }
}
impl Add for Field { type Output = Self; fn add(self, a: Self) -> Self::Output { Self(Self::hi(self.0 + a.0)) }}
impl Sub for Field { type Output = Self; fn sub(self, a: Self) -> Self::Output { Self(Self::lo(self.0 - a.0)) }}
impl Mul for Field { type Output = Self; fn mul(self, a: Self) -> Self::Output { Self(Self::cv(self.0 as i64 * a.0 as i64)) }}
impl Neg for Field { type Output = Self; fn neg(self) -> Self::Output { Self(Self::lo(-self.0)) }}
impl AddAssign for Field { fn add_assign(&mut self, a: Self) { *self = *self + a; } }
impl SubAssign for Field { fn sub_assign(&mut self, a: Self) { *self = *self - a; } }
impl MulAssign for Field { fn mul_assign(&mut self, a: Self) { *self = *self * a; } }
use std::fmt::{Display, Formatter, Result};
impl Display for Field { fn fmt(&self, f: &mut Formatter) -> Result { write!(f, "{}", self.0) } }
// impl Default for Field { fn default() -> Self { Field(0) }}
impl Default for &Field { fn default() -> Self { &Field(0) }}
impl PartialEq for Field { fn eq(&self, a: &Self) -> bool { self.0 == a.0 } }
impl PartialOrd for Field { fn partial_cmp(&self, a: &Self) -> Option<Ordering> { Some(self.0.cmp(&a.0)) } }
impl Eq for Field {}
impl Ord for Field { fn cmp(&self, a: &Self) -> Ordering { self.0.cmp(&a.0) } }

fn main() {
    let mut bin = String::new();
    let mut input = WordReader::from_stdin(&mut bin);

    let n = input.u();
    let tt = input.i();
    let mut t = vec![0; n];
    let mut g = vec![0; n];
    let mut z = vec![0; 4];
    for i in 0..n {
        t[i] = input.i();
        g[i] = input.i();
        z[g[i] as usize] += 1;
    }
    let sumt: i32 = t.iter().sum();

    let dp2 = {
        let mut dp2 = HashMap::<(i32,i32,i32),Field>::new();
        let mut dp = HashMap::<(i32,i32,i32,i32,i32),Field>::new();
        for g in 1..4 {
            dp.insert((0,0,0,0,g), Field(1));
        }
        for _i in 0..n {
            let mut d = HashMap::<(i32,i32,i32,i32,i32),Field>::new();
            for ((h,a,b,c,l), y) in dp.into_iter() {
                let mut p = [0,a,b,c];
                let mut pf = [Field(0),Field(a),Field(b),Field(c)];
                for g in 1..4 {
                    let gu = g as usize;
                    if (h == 0 && g != l) || (h > 0 && g == l) {
                        continue;
                    }
                    p[gu] += 1;
                    pf[gu] += Field(1);
                    if (1..4).all(|i| p[i] <= z[i]) {
                        let key = (h + 1, p[1], p[2], p[3], g);
                        let res = y * pf[g as usize] + *d.get(&key).unwrap_or_default();
                        d.insert(key, res);
                    }
                    p[gu] -= 1;
                    pf[gu] -= Field(1);
                }
            }

            for (&(_,a,b,c,_),&x) in d.iter() {
                let key = (a,b,c);
                let res = *dp2.get(&key).unwrap_or_default();
                dp2.insert(key, res + x);
            }
            dp = d;
            // println!("\n-----------------------: {}", _i);
            // for ((h,a,b,c,g),x) in dp.iter() {
            // println!("{} {} {} {} {}: {}", h,a,b,c,g,x);
            // }
        }
        dp2
    };
    // eprintln!("DP2");
    // for ((a,b,c),x) in dp2.iter() {
        // println!("dp2    {} {} {} : {}", a,b,c,x);
    // }

    let dp1 = {
        let mut st = [0; 3];
        st[2] = 1;
        st[1] = st[2] * (z[2] + 1);
        st[0] = st[1] * (z[1] + 1);
        let st = st;
        let sz = (st[0] * (sumt + 1)) as usize;

        let mut aa = vec![Field(0); sz];
        let mut dp = HashSet::<i32>::new();
        dp.insert(0);
        aa[0] = Field(1);
        for i in 0..n {
            if g[i] == 3 { continue; }

            let mut d = HashSet::<i32>::new();
            let mut a = vec![Field(0); sz];
            let x = t[i];
            let g = g[i] as usize;
            for &s in dp.iter() {
                let key = s + (x * st[0]) + st[g];
                d.insert(key);
                a[key as usize] += aa[s as usize];
            }
            for key in d.into_iter() {
                let s = key as usize;
                aa[s] += a[s];
                dp.insert(key);
            }
        }
        let mut dp1 = HashMap::<(i32,i32,i32),Field>::new();
        for s in dp.into_iter() {
            let t = s / st[0];
            let a = s % st[0] / st[1];
            let b = s % st[1] / st[2];
            dp1.insert((t,a,b),aa[s as usize]);
        }
        dp1
    };
    // eprintln!("DP1");
    // for ((a,b,c),x) in dp1.iter() {
        // println!("dp1    {} {} {} : {}", a,b,c,x);
    // }

    let dp3 = {
        let mut st = [0; 4];
        st[3] = 1;
        st[0] = st[3] * (z[3] + 1);
        let st = st;
        let sz = (st[0] * (sumt + 1)) as usize;

        let mut aa = vec![Field(0); sz];
        let mut dp = HashSet::<i32>::new();
        dp.insert(0);
        aa[0] = Field(1);
        for i in 0..n {
            if g[i] != 3 { continue; }

            let mut d = HashSet::<i32>::new();
            let mut a = vec![Field(0); sz];
            let x = t[i];
            let g = g[i] as usize;
            for &s in dp.iter() {
                let key = s + (x * st[0]) + st[g];
                d.insert(key);
                a[key as usize] += aa[s as usize];
            }
            for key in d.into_iter() {
                let s = key as usize;
                aa[s] += a[s];
                dp.insert(key);
            }
        }
        let mut dp3 = HashMap::<(i32,i32),Field>::new();
        for s in dp.into_iter() {
            let t = s / st[0];
            let c = s % st[0] / st[3];
            dp3.insert((t,c),aa[s as usize]);
        }
        dp3
    };
    // eprintln!("DP3");
    // for ((a,b),x) in dp3.iter() {
        // println!("dp3    {} {} : {}", a,b,x);
    // }

    let dp1 = {
        let mut dp = HashMap::<(i32,i32,i32),Field>::new();
        for ((tab,a,b),res1) in dp1 {
            let tc = tt - tab;
            if tc < 0 { continue; }
            for c in 0..=z[3] {
                if let Some(&res2) = dp3.get(&(tc,c)) {
                    let res3 = *dp.get(&(a,b,c)).unwrap_or_default();
                    dp.insert((a,b,c), res3 + res1*res2);
                }
            }
        }
        dp
    };
    // println!("DP1");
    // println!("DP1");
    // for ((a,b,c),&x) in dp1.iter() {
        // println!("dpX    {} {} {} : {}", a,b,c,x);
    // }

    let mut sol = Field::new_unchecked(0);
    for a in 0..=z[1] as i32 {
        for b in 0..=z[2] as i32 {
            for c in 0..=z[3] as i32 {
                let x = *dp1.get(&(a,b,c)).unwrap_or_default();
                let y = *dp2.get(&(a,b,c)).unwrap_or_default();
                sol += x * y;
            }
        }
    }
    println!("{}", sol);
}
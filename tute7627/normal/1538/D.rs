
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        let mut next = || { iter.next().unwrap() };
        input_inner!{next, $($r)*}
    };
    ($($r:tt)*) => {
        let stdin = std::io::stdin();
        let mut bytes = std::io::Read::bytes(std::io::BufReader::new(stdin.lock()));
        let mut next = move || -> String{
            bytes
                .by_ref()
                .map(|r|r.unwrap() as char)
                .skip_while(|c|c.is_whitespace())
                .take_while(|c|!c.is_whitespace())
                .collect()
        };
        input_inner!{next, $($r)*}
    };
}

macro_rules! input_inner {
    ($next:expr) => {};
    ($next:expr, ) => {};

    ($next:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($next, $t);
        input_inner!{$next $($r)*}
    };
}

macro_rules! read_value {
    ($next:expr, ( $($t:tt),* )) => {
        ( $(read_value!($next, $t)),* )
    };

    ($next:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($next, $t)).collect::<Vec<_>>()
    };

    ($next:expr, chars) => {
        read_value!($next, String).chars().collect::<Vec<char>>()
    };

    ($next:expr, usize1) => {
        read_value!($next, usize) - 1
    };

    ($next:expr, $t:ty) => {
        $next().parse::<$t>().expect("Parse error")
    };
}

fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>().split_whitespace()
        .map(|e| e.parse().ok().unwrap()).collect()
}

fn read_vec2<T: std::str::FromStr>(n: u32) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}


fn main(){
    let mut primes: Vec<i32> = Vec::new();
    for p in 2..40000{
        let mut is_prime = true;
        let mut div: i32 = 2;
        while div * div <= p{
            if p % div == 0{
                is_prime = false;
            }
            div += 1;
        }
        if is_prime{
            primes.push(p);
        }
    }
    input!{
        t: usize,
        v: [(i32, i32, i32); t],
    }
    for x in v.iter(){
        let a = std::cmp::max(x.0, x.1);
        let b = std::cmp::min(x.0, x.1);
        let k = x.2;
        let mut num = 0;
        for _n in vec![a, b].iter(){
            let mut n = *_n;
            for i in 0..primes.len(){
                if primes[i] * primes[i] > n{
                    break;
                }
                while n % primes[i] == 0{
                    n /= primes[i];
                    num += 1;
                }
            }
            if n > 1{
                num += 1;
            }
        }
        if num < k || (k == 0 && a != b) || (k == 1 && (a == b || a % b != 0)){
            println!("NO");
        }
        else{
            println!("YES");
        }
    }
}
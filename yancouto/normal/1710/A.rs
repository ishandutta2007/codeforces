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

fn read_line_vec<T>() -> Vec<T>
where
    T: std::str::FromStr,
    T::Err: std::fmt::Debug,
{
    get_line()
        .split_ascii_whitespace()
        .map(|s| s.parse::<T>())
        .collect::<Result<Vec<T>, _>>()
        .unwrap()
}

fn can(n: usize, m: usize, a: &Vec<usize>) -> bool {
    let rows: Vec<usize> = a
        .iter()
        .copied()
        .map(|x| (x / m))
        .map(|x| if x < 2 { 0 } else { x })
        .filter(|x| *x > 0)
        .collect();
    let sum: usize = rows.iter().sum();
    let any_more_than_2: bool = rows.iter().any(|x| *x > 2);
    if !any_more_than_2 {
        sum >= n && (n % 2) == 0
    } else {
        sum >= n
    }
}

fn main() {
    read_line!(t: usize);
    for _ in 0..t {
        read_line!(n: usize, m: usize, _k: usize);
        let a: Vec<usize> = read_line_vec();
        if can(n, m, &a) || can(m, n, &a) {
            println!("Yes");
        } else {
            println!("No");
        }
    }
}
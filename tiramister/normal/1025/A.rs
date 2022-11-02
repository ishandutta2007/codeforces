use std::io::*;
use std::str::FromStr;

#[allow(dead_code)]
fn get_line() -> String {
    let stdin = stdin();
    let mut line = String::new();
    stdin.lock().read_line(&mut line).expect("io error.");
    line.trim().to_string()
}

#[allow(dead_code)]
fn get_word<T: FromStr>() -> T {
    (&get_line()).parse().ok().expect("parse error.")
}

#[allow(dead_code)]
fn get_vec<T: FromStr>() -> Vec<T> {
    (&get_line()).split(' ').map(|x| x.parse().ok().expect("parse error.")).collect()
}

fn main() {
    let n = get_word::<u64>();
    let s = get_line();

    if n == 1 {
        println!("Yes");
        return;
    }

    let mut cnt = [0u64; 26];
    for c in s.chars() {
        cnt[((c as u8) - ('a' as u8)) as usize] += 1;
    }

    for k in cnt.iter() {
        if *k > 1 {
            println!("Yes");
            return;
        }
    }

    println!("No");
}
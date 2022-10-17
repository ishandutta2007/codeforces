use std::cmp;

fn max(x: i32, y: i32, z: i32) -> i32{
    cmp::max(x, cmp::max(y, z))
}
fn min(x: i32, y: i32, z: i32) -> i32{
    cmp::min(x, cmp::min(y, z))
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|x| {x.parse::<i32>().unwrap()});
    
    let x = it.next().unwrap();
    let y = it.next().unwrap();
    let z = it.next().unwrap();

    println!("{}", max(x, y, z) - min(x, y, z));
}
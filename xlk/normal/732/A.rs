fn f(k: i32, r: i32) -> i32{
	for i in 1..11 {
		if k * i % 10 == r || k * i % 10 == 0 {
			return i;
		}
	}
	return 0;
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|x| {x.parse::<i32>().unwrap()});
    
    let k = it.next().unwrap();
    let r = it.next().unwrap();

    println!("{}", f(k, r));
}
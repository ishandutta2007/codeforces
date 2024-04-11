fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input);
    let t: u32 = input.trim().parse().unwrap();
    for c in 0..t {
        input.clear();
        std::io::stdin().read_line(&mut input);
        let s = input.trim();
        if s.ends_with("po") {
            println!("FILIPINO");
        } else if s.ends_with("desu") || s.ends_with("masu") {
            println!("JAPANESE");
        } else {
            println!("KOREAN");
        }
    }
}
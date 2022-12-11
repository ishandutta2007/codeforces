fn main(){
	let mut line = String::new();

	std::io::stdin().read_line(&mut line)
	.expect("Reading n error!");
	
	let mut iter = line.split_whitespace();

	let n:usize = iter.next().expect("").parse()
	.expect("Error while parsing!");
	
	let m:usize = iter.next().expect("").parse()
	.expect("Error while parsing!");
	
	let d:i64 = iter.next().expect("").parse()
	.expect("Error while parsing!");
	
	let mut v1 = Vec::new();
	let mut v2 = Vec::new();
	
	for i in 0..n {
	    let mut line = String::new();
	    std::io::stdin().read_line(&mut line).expect("");
	    let mut iter = line.split_whitespace();
	    
	    let c:i64 = iter.next().expect("").parse().expect("");
	    let w:i64 = iter.next().expect("").parse().expect("");
	    
	    v1.push((c, -w));
	}
	
	for i in 0..m {
	    let mut line = String::new();
	    std::io::stdin().read_line(&mut line).expect("");
	    let mut iter = line.split_whitespace();
	    
	    let c:i64 = iter.next().expect("").parse().expect("");
	    let w:i64 = iter.next().expect("").parse().expect("");
	    
	    v2.push((c, -w));
	}
	
	v1.sort();
	v2.sort();
	
	for i in 0..n {
	    v1[i].1 = -v1[i].1;
	}
	
	for i in 0..m {
	    v2[i].1 = -v2[i].1;
	}
	
	for i in 1..n {
	    v1[n - i - 1].0 += v1[n - i].0;
	    v1[n - i - 1].1 += v1[n - i].1;
	}
	
	for i in 1..m {
	    v2[m - i - 1].0 += v2[m - i].0;
	    v2[m - i - 1].1 += v2[m - i].1;
	}

	let mut ans:i64 = 0 as i64;
	
	for i in v1 {
	    let mut lo:usize = 1;
	    let mut hi:usize = m;
	    while lo <= hi
	    {
	        let mid = (lo + hi) / 2;
	        if i.1 + v2[mid - 1].1 > d
	        {
	            lo = mid + 1;
	        }
	        else
	        {
	            ans = std::cmp::max(ans, i.0 + v2[mid - 1].0);
	            hi = mid - 1;
	        }
	    }
	}
	
	println!("{}", ans);
}
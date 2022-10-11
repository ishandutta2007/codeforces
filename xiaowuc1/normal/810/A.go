package main

import "fmt"

func main() {
    var n int
    var k int
    fmt.Scanf("%d %d\n", &n, &k)
    sum := 0
    for i := 0; i < n; i++ {
    	var x int
    	fmt.Scanf("%d", &x)
    	sum += x
    }
    ret := 0
    for 2 * sum < (ret + n) * (2 * k - 1) {
    	/*
    	sum / (ret + n) >= (k - 0.5)
    	2 * sum / (ret + n) >= 2 * k - 1
    	2 * sum >= (ret + n) * (2 * k - 1)
    	*/
    	sum += k
    	ret += 1
    }
    fmt.Printf("%d\n", ret)
}
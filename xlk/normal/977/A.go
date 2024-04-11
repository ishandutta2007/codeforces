package main

import "fmt"

func main() {
	var n, k int
	fmt.Scanf("%d%d", &n, &k)
	for i := 0; i < k; i++ {
		if n % 10 > 0 {
			n--
		} else {
			n /= 10
		}
	}
	fmt.Println(n)
}
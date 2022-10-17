package main

import "fmt"

func main() {
	var n uint64
	fmt.Scan(&n)
	if n == 0 {
		fmt.Println(0)
	} else {
		fmt.Println((n + 1) >> (n % 2))
	}
}
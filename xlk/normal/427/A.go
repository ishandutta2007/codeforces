package main

import (
	"fmt"
)

func main() {
	n, x, l, z := 0, 0, 0, 0
	fmt.Scanf("%d ", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &x);
		if x == -1 {
			if l > 0 {
				l--
			} else {
				z++
			}
		} else {
			l += x
		}
	}
	fmt.Println(z)
}
package main

import "fmt"
import "bufio"
import "os"

func main() {
    in := bufio.NewReader(os.Stdin)
	var n int
    fmt.Fscan(in, &n)
    var aa int
	countOdd := 0
	countEven := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &aa)
		if aa % 2 == 1 {
			countOdd++
		} else {
			countEven++
		}
	}
    count := 0
	for {
		if (countOdd == 0) {
			break
		}
		if (countEven > 0) {
			count++
			countOdd--
			countEven--
		} else if (countOdd >= 3) {
			count++;
			countOdd -= 3
		} else {
			break
		}
	}
	fmt.Println(count)
}
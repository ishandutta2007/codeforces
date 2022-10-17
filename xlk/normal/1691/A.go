package main
import (
	"bufio"
	"fmt"
	"os"
)
var fin = bufio.NewReader(os.Stdin)
var fout = bufio.NewWriter(os.Stdout)
func main() {
	defer fout.Flush()
	t := 0
	fmt.Fscan(fin, &t)
	for tt := 0; tt < t; tt++ {
		n := 0
		fmt.Fscan(fin, &n)
		c := [2]int{}
		for i := 0; i < n; i++ {
			x := 0
			fmt.Fscan(fin, &x)
			c[x % 2] += 1
		}
		if c[0] < c[1] {
			fmt.Fprintln(fout, c[0])
		} else {
			fmt.Fprintln(fout, c[1])
		}
	}
}
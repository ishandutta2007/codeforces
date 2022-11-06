package main
import (
	. "fmt"
	"bufio"
	"os"
)

func main(){
	read := bufio.NewReader(os.Stdin)
	write := bufio.NewWriter(os.Stdout)
	
	defer write.Flush()
	
	var tc int 
	
	for Fscan (read, &tc); tc > 0; tc -- {
		var n int 
		Fscan (read, &n)
		min, max, min_ind, max_ind := 1 << 30, 0, -1, -1
		
		for i := 1; i <= n; i++ {
			var val int 
			Fscan (read, &val)
			if val < min {
				min, min_ind = val, i
			}
			if val > max {
				max, max_ind = val, i
			}
		}
		Fprintln(write, min_ind, max_ind)
	}
}
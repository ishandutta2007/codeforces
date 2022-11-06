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
		var n, k int 
		
		Fscan (read, &n, &k)
		
		mp, ans := map[int]bool{}, 0
		for i := 1; i <= n; i++ {
		    var val int
		    Fscan (read, &val)
		    mp[val] = true
		}
		
		for key, _ := range mp {
		    if mp[key + k] {
		        ans = 1
		    }
		}
		
		if ans == 1 {
		    Fprintln(write, "YES")
		} else {
		    Fprintln(write, "NO")
		}
	}
}
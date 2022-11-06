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
		
		isOne := false
		
		vals := map[int]bool{}
		
		for i := 1; i <= n; i++ {
		    var val int
		    Fscan (read, &val)
		    if val == 1{
		        isOne = true
		    }
		    vals[val] = true
		}
		
		if !isOne {
		    Fprintln (write, "YES")
		} else{
		    ok := true
		    for key, _ := range vals {
		        if vals[key + 1] {
		            ok = false
		        }
		    }
		    if ok {
		        Fprintln (write, "YES")
		    } else {
		        Fprintln (write, "NO")
		    }
		}
	}
}
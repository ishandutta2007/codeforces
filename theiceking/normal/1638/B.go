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
    Fscanf(read, "%d\n", &tc)
    
    for tt := 0; tt < tc; tt++ {
        var n int
        Fscanf(read, "%d\n", &n)        
        
        ok := true 
        last_odd, last_even := 0, 0
        for i := 0; i < n; i++ {
            var val int 
            Fscanf (read, "%d", &val)
            if val % 2 == 1 {
                if val < last_odd {
                    ok = false
                } else {
                    last_odd = val
                }
            } else{
                if val < last_even {
                    ok = false
                } else {
                    last_even = val
                }
            }
        }
        Fscanf(read, "\n")
        if ok {
            Fprintln(write, "Yes")
        } else{
            Fprintln(write, "No")
        }
    }


}
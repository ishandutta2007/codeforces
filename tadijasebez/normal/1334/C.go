package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func max(a,b int) int {
	if a>b {
		return a
	} else {
		return b
	}
}
func min(a,b int64) int64 {
	if a>b {
		return b
	} else {
		return a
	}
}

func main() {

	defer writer.Flush()
	
	var t int
	scanf("%d\n",&t)
	for ;t>0;t-- {
	    var n int
	    scanf("%d\n",&n)
	    var a, b []int64
	    for i:=0;i<n;i++ {
	        var x, y int64
	        scanf("%d %d\n",&x,&y)
	        a=append(a,x)
	        b=append(b,y)
	    }
	    var sum int64 = 0
	    var mn int64
	    mn=b[0]
	    for i:=0;i<n;i++ {
	        b[i]=min(b[i],a[(i+1)%n])
	        mn=min(mn,b[i])
	        sum+=a[i]-b[i]
	    }
	    printf("%d\n",sum+mn)
	}

}
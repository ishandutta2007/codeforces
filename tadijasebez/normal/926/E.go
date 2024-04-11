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
func min(a,b int) int {
	if a>b {
		return b
	} else {
		return a
	}
}

func main() {

	defer writer.Flush()

	var n int
	var a[200050] int
	var stk[] int
	
	scanf("%d\n",&n)
	for i:=1;i<=n;i++ {
	    scanf("%d",&a[i])
	    for len(stk)>0 && stk[len(stk)-1]==a[i] {
	        a[i]++
	        stk=stk[:len(stk)-1]
	    }
	    stk=append(stk,a[i])
	}
	
	printf("%d\n",len(stk))
	for i:=0;i<len(stk);i++ {
	    printf("%d ",stk[i])
	}
}
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

func main() {
    
	defer writer.Flush()
	
	var t int
	var a, was, ans [1000050]int
	for scanf("%d\n",&t);t>0;t-- {
		var n int
		scanf("%d\n",&n)
		for i:=1;i<=n;i++ {
			scanf("%d",&a[i])
			a[i]=i-a[i]
			was[i]=0
		}
		scanf("\n");
		var x int=1
		for was[x]==0 {
			was[x]=1
			x=a[x]
		}
		var cnt int=0
		for was[x]==1 {
			was[x]=2
			ans[cnt]=x
			cnt++
			x=a[x]
		}
		printf("%d\n",cnt)
		for i:=0;i<cnt;i++ {
			printf("%d ",ans[i])
		}
		printf("\n")
	}
}
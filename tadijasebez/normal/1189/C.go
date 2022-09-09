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

const L,N uint=17,100050

var table [L][N]int
var a,sum [N]int
func get(l,r int) int {
	ans:=sum[r]-sum[l-1]
	if ans<0 {
		return ans+10
	} else {
		return ans
	}
}
func main() {

	defer writer.Flush()

	var n int
	scanf("%d\n",&n)
	for i:=1;i<=n;i++ {
		scanf("%d ",&a[i])
		sum[i]=(sum[i-1]+a[i])%10
	}
	scanf("\n")
	
	var j uint
	for j=1;j<L;j++ {
		for i:=1;i<=n-(1<<j)+1;i++ {
			table[j][i]=table[j-1][i]+table[j-1][i+(1<<(j-1))]
			if get(i,i+(1<<(j-1))-1)+get(i+(1<<(j-1)),i+(1<<j)-1)>=10 {
				table[j][i]++
			}
			//printf("(%d %d) %d\n",i,i+(1<<j)-1,table[j][i])
		}
	}

	var q int
	scanf("%d\n",&q)
	for ;q>0;q-- {
		var l,r int
		scanf("%d %d\n",&l,&r)
		log:=0
		for sz:=r-l+1;sz>1;sz/=2 {
			log++
		}
		printf("%d\n",table[log][l])
	}
}
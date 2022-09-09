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
    var a int

    scanf("%d\n",&t)
    
    for br:=0;br<t;br++ {
        var n, s int
        scanf("%d %d\n",&n,&s)
        var sum int64
        sum=0;
        var mx int
        mx=0
        var ans int
        ans=0
        var taj int
        taj=0
        var ind int
        ind=0
        for i:=1;i<=n;i++ {
            scanf("%d",&a);
            sum+=int64(a);
            if mx<a {
                mx=a
                ind=i
            }
            if sum<=int64(s) {
                ans=i
                taj=0
            }
            if sum-int64(mx)<=int64(s) {
                if ans<i-1 {
                    ans=i-1
                    taj=ind
                }
            }
        }
        scanf("\n")
        printf("%d\n",taj);
    }
}
package main
 
import (
	"bufio"
	"fmt"
	"os"
)
 
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
 
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }
 
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
 
const N = 105
 
var a [N][N]byte
 
func main() {
	defer writer.Flush()
 
	var t int
	scanf("%d\n", &t)
	for ; t > 0; t-- {
		var n, m int
		scanf("%d %d\n", &n, &m)
		for i := 1; i <= n; i++ {
			for j := 1; j <= m; j++ {
				if (i+j)%2 == 0 {
					a[i][j] = 'B'
				} else {
					a[i][j] = 'W'
				}
			}
		}
		if (n*m)%2 == 0 {
		    var flag bool = true
			for i := 1; i <= n; i++ {
			    for j := 1; j <= m; j++ {
			        if a[i][j]=='W' && flag {
			            flag = false
			            a[i][j] = 'B'
			        }
			    }
			}
		}
		for i := 1; i <= n; i++ {
			for j := 1; j <= m; j++ {
				printf("%c", a[i][j])
			}
			printf("\n")
		}
	}
}
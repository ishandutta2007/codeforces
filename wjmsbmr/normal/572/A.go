package main
import (
  "bufio"
  "fmt"
  "os"
)

const maxN = 100005
var a,b [maxN]int

func main() {
  var nA, nB, k, m int
  stdin := bufio.NewReader(os.Stdin)

  fmt.Fscanf(stdin, "%d %d\n", &nA, &nB)
  fmt.Fscanf(stdin, "%d %d\n", &k, &m)

  for i := 0; i < nA; i++ {
    if i != nA - 1 {
      fmt.Fscanf(stdin, "%d ", &a[i])
    } else {
      fmt.Fscanf(stdin, "%d\n", &a[i])
    }
  }
  for i := 0; i < nB; i++ {
    if i != nB - 1 {
      fmt.Fscanf(stdin, "%d ", &b[i])
    } else {
      fmt.Fscanf(stdin, "%d\n", &b[i])
    }
  }
  if (a[k-1] < b[nB-m]) {
    fmt.Println("YES")
  } else {
    fmt.Println("NO")
  }
}
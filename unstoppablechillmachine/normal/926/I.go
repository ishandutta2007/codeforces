package main
import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	var arr [110]int
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		var a int
		var b int
		var c int
		var d int
		a = (int(s[0]))
		b = (int(s[1]))
		c = (int(s[3]))
		d = (int(s[4]))
		arr[i] = (a * 10 + b) * 60 + c * 10 + d
	}
	for i := 0; i < n; i++ {
	    for j := 1; j < n; j++ {
	        if arr[j - 1] > arr[j] {
	            var f int
	            f = arr[j - 1]
	            arr[j - 1] = arr[j]
	            arr[j] = f
	        }
	    }
	}
	arr[n] = arr[0] + 24 * 60
	var ans int
	ans = 0
	for i := 1; i <= n; i++ {
		if arr[i] - arr[i - 1] > ans {
		    ans = arr[i] - arr[i - 1]
		}
	}
	ans--
	//fmt.Println(ans)
	var h int 
	h = ans / 60
	var m int
	m = ans % 60
	//fmt.Println(h)
	//fmt.Println(m)
	if h < 10 {
	    fmt.Printf("%d", 0)
	}
	fmt.Printf("%d", h)
	fmt.Printf("%c", ':')
	if m < 10 {
	    fmt.Printf("%d", 0)
	}
	fmt.Printf("%d", m)
}
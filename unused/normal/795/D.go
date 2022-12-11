package main

import (
    "io/ioutil"
    "os"
    "fmt"
    "sort"
)

func getInts() []int {
    //assumes POSITIVE INTEGERS. Check v for '-' if you have negative.
    var buf []byte
    buf, _ = ioutil.ReadAll(os.Stdin)
    var ints []int
    num := 0
    found := false
    for _, v := range buf {
        if '0' <= v && v <= '9' {
            num = 10*num + int(v - '0') //could use bitshifting here.
            found = true
        } else if found {
            ints = append(ints, num)
            found = false
            num = 0
        }
    }
    if found {
        ints = append(ints, num)
        found = false
        num = 0
    }
    return ints
}

func main() {
    var ints []int
    
    ints = getInts()
    
	var n, l, r int
	n = ints[0]
	l = ints[1]
	r = ints[2]
	
	var a []int
	var b []int
	
	a = ints[3:3+n]
	b = ints[3+n:3+2*n]
	
	sort.Ints(a[l-1:r])
	sort.Ints(b[l-1:r])
	
	for i := 0; i < n; i++ {
	    if a[i] != b[i] {
	        fmt.Println("LIE")
	        return
	    }
	}
	
	fmt.Println("TRUTH")
}
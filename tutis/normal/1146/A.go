/*input
xaxxxxa
*/
package main

import "fmt"
//import "bufio"
//import "os"
import "math/rand"
type node struct {
	v int
	w, sz int
	l, r *node
}
func merge(a, b *node) *node {
	if(a == nil) {
		return b
	}
	if(b == nil) {
		return a
	}
	if(a.w < b.w) {
		a.sz += b.sz
		a.r = merge(a.r, b)
		return a
	} else {
		b.sz += a.sz
		b.l = merge(a, b.l)
		return b
	}
}
func virs(x int) *node {
	return &node{
	v:x, 
	w:rand.Int(),
	sz:1,
	l:nil, 
	r:nil, }
}
func split(a *node, x int) (*node, *node) {
// (<=x), (>x)
	if(a == nil) {
		return nil, nil
	}
	if(a.v <= x) {
		l, r := split(a.r, x)
		a.r = l
		if(r != nil) {
			a.sz -= r.sz;
		}
		return a, r
	} else {
		l, r := split(a.l, x)
		a.l = r
		if(l != nil) {
			a.sz -= l.sz;
		}
		return l, a
	}
}
func Print(a *node) {
	if(a==nil) {
		return;
	}
	Print(a.l);
	fmt.Printf("%d ", a.v);
	Print(a.r);
}
func size(x *node) int {
	if(x == nil) {
		return 0
	}
	return x.sz
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func main() {
	var s string
	fmt.Scan(&s)
	ka := 0;
	for i:=0;i<len(s);i++{
		if(s[i]=='a'){
			ka++;
		}
	}
	fmt.Println(min(2 * ka - 1, len(s)));
}
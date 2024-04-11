package main

import (
  "bufio"
  "fmt"
  "os"
  "sort"
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

type vector_i []int
func (v *vector_i) pb(x int) {
	*v=append(*v,x)
}
func (v *vector_i) size() int {
	return len(*v)
}
func (v *vector_i) pop() {
	if !(*v).empty() {
		*v=(*v)[:len(*v)-1]
	}
}
func (v *vector_i) reverse() {
	n:=(*v).size()
	for i:=0;i*2<n;i++ {
		(*v)[i],(*v)[n-i-1]=(*v)[n-i-1],(*v)[i]
	}
}
func (v *vector_i) clear() {
	*v=(*v)[:0]
}
func (v *vector_i) empty() bool {
	return (*v).size()==0
}
func (v *vector_i) sort() {
	sort.Slice(*v, func (i, j int) bool {
		return (*v)[i]<(*v)[j]
	})
}
type fun_ii_b func (i, j int) bool
func (v *vector_i) sort_fun(f fun_ii_b) {
	sort.Slice(*v,f)
}
func (v *vector_i) lb(x int) int {
	var l,r int = 0,(*v).size()
	for l<r {
		mid:=(l+r)/2
		if (*v)[mid]<x {
			l=mid+1 
		} else {
			r=mid 
		}
	}
	return l
}
func (v *vector_i) ub(x int) int {
	var l,r int = 0,(*v).size()
	for l<r {
		mid:=(l+r)/2
		if (*v)[mid]<=x {
			l=mid+1 
		} else {
			r=mid 
		}
	}
	return l
}
func (v *vector_i) del(pos int) {
	if pos>=0 && pos<len(*v) {
		for i:=pos;i<len(*v)-1;i++ {
			(*v)[i]=(*v)[i+1]
		}
		(*v).pop()
	}
}
func (v *vector_i) ins(pos, val int) {
	(*v).pb(0)
	for i:=len(*v)-1;i>pos;i-- {
		(*v)[i]=(*v)[i-1]
	}
	(*v)[pos]=val
}
func (v *vector_i) substr(l, r int) vector_i {
	var ans vector_i=make(vector_i,r-l+1)
	for i:=l;i<=r;i++ {
		ans.pb((*v)[i])
	}
	return ans
}
func (v *vector_i) resize(n int) {
	for len(*v)>n {
		(*v).pop()
	}
	for len(*v)<n {
		(*v).pb(0)
	}
}

func main() {

	defer writer.Flush()

	var t int
	scanf("%d\n",&t)
	for ;t>0;t-- {
		var p,id vector_i
		var n int
		scanf("%d\n",&n)
		for i:=1;i<=n;i++ {
			var x int
			scanf("%d ",&x)
			p.pb(x)
			id.pb(i)
		}
		scanf("\n")
		id.sort_fun(func(i,j int) bool {
			return p[id[i]-1]<p[id[j]-1]
		})
		var mn,mx int=1e9,-1e9
		for j,i:=range id {
			mn=min(mn,i)
			mx=max(mx,i)
			if mx-mn==j {
				printf("1")
			} else {
				printf("0")
			}
		}
		printf("\n")
	}
}
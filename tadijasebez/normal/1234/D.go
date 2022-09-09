package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"math/rand"
	"time"
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

type Treap struct {
	ls,rs,sz,x,y vector_i
	root int
	multi bool
}
func (t *Treap) init(multi bool) {
	t.ls.resize(1)
	t.rs.resize(1)
	t.sz.resize(1)
	t.x.resize(1)
	t.y.resize(1)
	t.root=0
	t.multi=multi
	rand.Seed(time.Now().UnixNano())
}
const lim_rand int=2000000000
func (t *Treap) MakeNode(x int) int {
	t.ls.pb(0)
	t.rs.pb(0)
	t.sz.pb(1)
	t.x.pb(x)
	t.y.pb(rand.Intn(lim_rand))
	return t.x.size()-1;
}
func (t *Treap) val(c int) int {
	return t.x[c]
}
func (t *Treap) pull(c int) {
	t.sz[c]=t.sz[t.ls[c]]+1+t.sz[t.rs[c]]
}
func (t *Treap) upd(c int) {

}
func (t *Treap) push(c int) {

}
func (t *Treap) Split_val(c int, l,r *int, x int) {
	if c==0 {
		*l=0
		*r=0
	} else {
		(*t).push(c)
		if t.x[c]<=x {
			*l=c
			(*t).Split_val(t.rs[c],&t.rs[*l],r,x)
		} else {
			*r=c
			(*t).Split_val(t.ls[c],l,&t.ls[*r],x)
		}
		(*t).pull(c)
	}
}
func (t *Treap) Split_sz(c int, l,r *int, k int) {
	if c==0 {
		*l=0
		*r=0
	} else {
		(*t).push(c)
		if t.sz[t.ls[c]]+1<=k {
			*l=c
			(*t).Split_sz(t.rs[c],&t.rs[*l],r,k-t.sz[t.ls[c]]-1)
		} else {
			*r=c
			(*t).Split_sz(t.ls[c],l,&t.ls[*r],k)
		}
		(*t).pull(c)
	}
}
func (t *Treap) Merge(c *int, l,r int) {
	if l==0 || r==0 {
		*c=l^r;
	} else {
		if t.y[l]>t.y[r] {
			(*t).push(l)
			*c=l
			(*t).Merge(&t.rs[*c],t.rs[l],r)
		} else {
			(*t).push(r)
			*c=r
			(*t).Merge(&t.ls[*c],l,t.ls[r])
		}
		(*t).pull(*c)
	}
}
func (t *Treap) Search_pos(c,k int) int {
	if c==0 {
		return 0
	} else {
		(*t).push(c)
		if t.sz[t.ls[c]]+1==k {
			return c
		} else if t.sz[t.ls[c]]+1<k {
			return (*t).Search_pos(t.rs[c],k-t.sz[t.ls[c]]-1)
		} else {
			return (*t).Search_pos(t.ls[c],k)
		}
	}
}
func (t *Treap) has(c,x int) bool {
	if c==0 {
		return false
	} else {
		(*t).push(c)
		if t.x[c]==x {
			return true
		} else if t.x[c]<x {
			return (*t).has(t.rs[c],x)
		} else {
			return (*t).has(t.ls[c],x)
		}
	}
}
func (t *Treap) ins(x int) {
	if t.multi || !(*t).has(t.root,x) {
		tmp:=(*t).MakeNode(x)
		var a,b int=0,0
		(*t).Split_val(t.root,&a,&b,x)
		(*t).Merge(&t.root,a,tmp)
		(*t).Merge(&t.root,t.root,b)
	}
}
func (t *Treap) del_val(x int) {
	var a,b,c int=0,0,0
	(*t).Split_val(t.root,&a,&b,x-1)
	(*t).Split_val(b,&b,&c,x)
	(*t).Merge(&t.root,a,c)
}
func (t *Treap) del_pos(k int) {
	var a,b,c int=0,0,0
	(*t).Split_sz(t.root,&a,&b,k-1)
	(*t).Split_sz(b,&b,&c,1)
	(*t).Merge(&t.root,a,c)
}
func (t *Treap) at(k int) int {
	return (*t).Search_pos(t.root,k)
}
func (t *Treap) val_at(k int) int {
	return t.x[(*t).at(k)]
}
func (t *Treap) Search_lb(c,x int) int {
	if c==0 {
		return 0
	} else {
		(*t).push(c)
		if t.x[c]==x {
			return c
		} else if t.x[c]<x {
			return (*t).Search_lb(t.rs[c],x)
		} else {
			ans:=(*t).Search_lb(t.ls[c],x)
			if ans==0 {
				ans=c
			}
			return ans
		}
	}
}
func (t *Treap) lb(x int) int {
	return (*t).Search_lb(t.root,x)
}
func (t *Treap) ub(x int) int {
	return (*t).Search_lb(t.root,x+1)
}
func (t *Treap) size() int {
	return t.sz[t.root]
}
func (t *Treap) print(c int) {
	if c!=0 {
		(*t).print(t.ls[c])
		printf("(%d %d) ",t.x[c],t.sz[c])
		(*t).print(t.rs[c])
	}
}

func main() {

	defer writer.Flush()

	var st [26]Treap
	for i:=0;i<26;i++ {
		st[i].init(false)
	}
	var str string
	var byt []byte
	byt=append(byt,0)
	scanf("%s\n",&str)
	for i:=1;i<=len(str);i++ {
		x:=int(str[i-1])-int('a')
		byt=append(byt,str[i-1])
		st[x].ins(i)
	}
	var q int
	scanf("%d\n",&q)
	for ;q>0;q-- {
		var t int
		scanf("%d ",&t)
		if t==1 {
			var p int
			var c byte
			scanf("%d %c\n",&p,&c)
			x:=int(byt[p])-int('a')
			y:=int(c)-int('a')
			byt[p]=c
			st[x].del_val(p)
			st[y].ins(p)
		} else {
			var l,r int
			scanf("%d %d\n",&l,&r)
			ans:=0
			for i:=0;i<26;i++ {
				lb:=st[i].lb(l)
				if lb!=0 && st[i].val(lb)<=r {
					ans++
				}
			}
			printf("%d\n",ans)
		}
	}
}
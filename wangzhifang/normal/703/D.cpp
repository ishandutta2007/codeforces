#pragma GCC optimize(2)
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_n 1000000
#define max_m 1000000
using namespace std;
int num[max_n+1];
struct node{
	int l,r,id;
	friend bool operator<(const node&x,const node&y){
		return (num[x.l]!=num[y.l])?(num[x.l]<num[y.l]):((num[x.l]&1)?(x.r<y.r):(x.r>y.r));
	}
};
node mque[max_m+1];
int st[max_n+1];
int a[max_n+1],b[max_n+1],c[max_n+1],ans[max_n+1];
int answer;
void ins(int pos){
	(st[c[pos]]++)&&(answer^=a[pos]);
}
void del(int pos){
	(--st[c[pos]])&&(answer^=a[pos]);
}
template<typename T>inline void read(T&x){
	char ch;
	while(!isdigit(ch=getchar()));
	x=ch^'0';
	while(isdigit(ch=getchar()))
		x=x*10+(ch^'0');
}
template<typename T>void write(T x){
	if(x>9)
		write(x/10);
	putchar((x%10)|'0');
}
template<typename T>void writeln(T x){
	write(x);
	putchar('\n');
}
int main(){
	int n,m,sqrtn;
	read(n);
	for(int i=0; ++i<=n; read(a[i]));
	memcpy(b,a,sizeof(a));
	stable_sort(b+1,b+n+1);
	int*lst=unique(b+1,b+n+1);
	for(int i=0; ++i<=n; c[i]=lower_bound(b+1,lst,a[i])-b);
	read(m);
	sqrtn=n/(sqrt(m*0.9)+1),answer=0;
	for(int i=0; ++i<=n; num[i]=i/sqrtn);
	for(int i=0; ++i<=m; read(mque[i].l),read(mque[i].r),mque[i].id=i);
	stable_sort(mque+1,mque+m+1);
	int l=mque[1].l,r=mque[1].r;
	for(int i=l-1; ++i<=r; ins(i));
	ans[mque[1].id]=answer;
	node x;
	for(int i=1; ++i<=m; ){
		x=mque[i];
		while(l<x.l)
			del(l++);
		while(l>x.l)
			ins(--l);
		while(r<x.r)
			ins(++r);
		while(r>x.r)
			del(r--);
		ans[x.id]=answer;
	}
	for(int i=0; ++i<=m; writeln(ans[i]));
	return 0;
}
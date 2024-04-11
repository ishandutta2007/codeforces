#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int l1[N],r1[N],l2[N],r2[N],tot,a[N],n,f[N],g[N],l;
struct Tree{
	int l,r,num,flag;
}T[N*4];
int ef(int x){
	int l=1,r=tot;
	while (l<r){
		int mid=(l+r)/2;
		if (a[mid]<x)l=mid+1;
		else r=mid;
	}
	return l;
}
void build(int x,int l,int r){
	T[x].l=l;T[x].r=r;T[x].num=T[x].flag=0;
	if (l==r){
		T[x].num=0;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
void down(int x){
	if (T[x].flag){
		T[x*2].num=T[x*2+1].num=T[x*2].flag=T[x*2+1].flag=1;
		T[x].flag=0;
		return;
	}
}
void insert(int x,int l,int r){
	if (T[x].l>r||l>T[x].r)return;
	if (T[x].l>=l&&T[x].r<=r){
		T[x].num=T[x].flag=1;
		return;
	}
	down(x);
	insert(x*2,l,r);
	insert(x*2+1,l,r);
	T[x].num=T[x*2].num|T[x*2+1].num;
}
int find(int x,int l,int r){
	if (T[x].l>r||l>T[x].r)return 0;
	if (T[x].l>=l&&T[x].r<=r)return T[x].num;
	down(x);
	return find(x*2,l,r)|find(x*2+1,l,r);
}
int cmp1(int x,int y){
	return l1[x]<l1[y];
}
int cmp2(int x,int y){
	return l2[x]<l2[y];
}
void ddown(int x){
	int i=x;
	if (x*2<=l&&r1[g[x*2]]<r1[g[x]])i=x*2;
	if (x*2<l&&r1[g[x*2+1]]<r1[g[i]])i=x*2+1;
	if (i!=x){
		swap(g[i],g[x]);
		ddown(i);
	}
}
void up(int x){
	if (x==1)return;
	if (r1[g[x/2]]>r1[g[x]]){
		swap(g[x],g[x/2]);
		up(x/2);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d%d%d%d",&l1[i],&r1[i],&l2[i],&r2[i]),f[i]=i;
	for (int i=1;i<=n;i++)a[++tot]=l1[i],a[++tot]=l2[i],a[++tot]=r1[i],a[++tot]=r2[i];
	sort(a+1,a+tot+1);
	int num=1;
	for (int i=2;i<=tot;i++)
		if (a[i]!=a[num])a[++num]=a[i];
	tot=num;
	for (int i=1;i<=n;i++){
		l1[i]=ef(l1[i]);
		l2[i]=ef(l2[i]);
		r1[i]=ef(r1[i]);
		r2[i]=ef(r2[i]);
	}
	sort(f+1,f+n+1,cmp1);
	build(1,1,tot);
	for (int i=1,j=1;i<=n;i++){
		while (l&&r1[g[1]]<l1[f[i]]){
			insert(1,l2[g[1]],r2[g[1]]);
			g[1]=g[l--];
			ddown(1);
			j++;
		}
		if (find(1,l2[f[i]],r2[f[i]])){
			puts("No");
			return 0;
		}
		g[++l]=f[i];
		up(l);
	}
	swap(l1,l2);
	swap(r1,r2);
	sort(f+1,f+n+1,cmp1);
	build(1,1,tot);
	for (int i=1,j=1;i<=n;i++){
		while (l&&r1[g[1]]<l1[f[i]]){
			insert(1,l2[g[1]],r2[g[1]]);
			g[1]=g[l--];
			down(1);
			j++;
		}
		if (find(1,l2[f[i]],r2[f[i]])){
			puts("No");
			return 0;
		}
		g[++l]=f[i];
		up(l);
	}	
	puts("Yes");
}
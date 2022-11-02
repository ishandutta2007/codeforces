#include<bits/stdc++.h>
using namespace std;
const int N=200005;
#define int long long
#define mp make_pair
#define fi first
#define se second
struct Tree{
	int l,r,flag;
	pair<int ,int > num;
}T[N*4]; 
void update(int x){
	if (T[x*2].num.fi<T[x*2+1].num.fi)T[x].num=T[x*2].num;
	else T[x].num=T[x*2+1].num;
}
void build(int x,int l,int r){
	T[x].l=l;T[x].r=r;
	if (l==r){
		scanf("%lld",&T[x].num.fi);
		T[x].num.se=l;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	update(x);
}
void down(int x){
	T[x*2].flag+=T[x].flag;
	T[x*2+1].flag+=T[x].flag;
	T[x*2].num.fi+=T[x].flag;
	T[x*2+1].num.fi+=T[x].flag;
	T[x].flag=0;
}
void insert(int x,int l,int r,int z){
	if (T[x].l>r||l>T[x].r)return;
	if (T[x].l>=l&&T[x].r<=r){
		T[x].flag+=z;
		T[x].num.fi+=z;
		return;
	}
	down(x);
	insert(x*2,l,r,z);
	insert(x*2+1,l,r,z);
	update(x);
}
void del(int x,int y){
	if (T[x].l==T[x].r){
		T[x].num.fi=1e18;
		return;
	}
	down(x);
	int mid=(T[x].l+T[x].r)/2;
	if (y<=mid)del(x*2,y);
	else del(x*2+1,y);
	update(x); 
}
int n,a[N];
signed main(){
	scanf("%lld",&n);
	build(1,1,n);
	for (int i=1;i<=n;i++){
		int t=T[1].num.se;
		del(1,t);
		insert(1,t,n,-i);
		a[t]=i;
	}
	for (int i=1;i<=n;i++)printf("%lld ",a[i]);
}
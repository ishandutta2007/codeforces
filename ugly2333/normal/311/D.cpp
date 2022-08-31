//CF 
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 111111;
const int mod = 95542721;
const int M = 48;
int n,a[N][M],tmp[N];
struct node{
	int h;
	int p[M];
}T[N<<2];
void pushd(int k){
	int i,x=k<<1,y=k<<1|1,z=T[k].h%M;
	if(!z)
		return;
	for(i=0;i<M;i=i+1)
		tmp[i]=T[k].p[(i+z)%M];
	for(i=0;i<M;i=i+1)
		T[k].p[i]=tmp[i];
	T[k].h=0;
	if(x>=(N<<2))
		return;
	T[x].h+=z;
	T[y].h+=z;
}
void upd(int k){
	int i,x=k<<1,y=k<<1|1;
	pushd(x),pushd(y);
	for(i=0;i<M;i=i+1)
		T[k].p[i]=(T[x].p[i]+T[y].p[i])%mod;
}
void build(int k=1,int l=1,int r=n){
	if(l==r){
		int i;
		for(i=0;i<M;i=i+1)
			T[k].p[i]=a[l][i];
		return;
	}
	int x=l+r>>1;
	build(k<<1,l,x);
	build(k<<1|1,x+1,r);
	upd(k);
}
void modify(int L,int R,int k=1,int l=1,int r=n){
	if(l>R||L>R||L>r)
		return;
	pushd(k);
	if(L<=l&&r<=R){
		T[k].h++;
		return;
	}
	int x=l+r>>1;
	modify(L,R,k<<1,l,x);
	modify(L,R,k<<1|1,x+1,r);
	upd(k);
}
int query(int L,int R,int k=1,int l=1,int r=n){
	if(l>R||L>R||L>r)
		return 0;
	pushd(k);
	if(L<=l&&r<=R)
		return T[k].p[0];
	int x=l+r>>1,q;
	q=query(L,R,k<<1,l,x);
	q+=query(L,R,k<<1|1,x+1,r);
	upd(k);
	return q%mod;
}
int main()
{
	int i,j,x,q;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		for(j=0;j<M;j=j+1){
			a[i][j]=x;
			x=(LL)x*x%mod*x%mod;
		}
	}
	build();
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&x,&i,&j);
		if(x==2)
			modify(i,j);
		else
			cout<<query(i,j)<<endl;
	}
	return 0;
}
/*
8
1 2 3 4 5 6 7 8
9
1 2 5
2 2 5
1 2 5
2 3 6
1 4 7
1 4 4
1 5 5
1 6 6
1 7 7

*/
//CF1179C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 333333;
const int M = 1<<21;
const int W = 1e6+5;
int n,m,q,a[N],b[N];
int t[M],p[M];
void modify(int L,int R,int V,int k=1,int l=1,int r=W){
	if(L<=l&&r<=R){
		p[k]+=V;
		t[k]+=V;
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,V,k<<1,l,h);
	if(h<R)
		modify(L,R,V,k<<1|1,h+1,r);
	t[k]=max(t[k<<1],t[k<<1|1])+p[k];
}
int query(int V=0,int k=1,int l=1,int r=W){
	if(t[k]+V<=0)
		return -1;
	if(l==r)
		return l;
	int h=l+r>>1;
	V+=p[k];
	if(t[k<<1|1]+V>0)
		return query(V,k<<1|1,h+1,r);
	return query(V,k<<1,l,h);
}
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		modify(1,a[i],1);
	}
	for(i=1;i<=m;i=i+1){
		scanf("%d",b+i);
		modify(1,b[i],-1);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&i,&x,&y);
		if(i==1){
			modify(1,a[x],-1);
			a[x]=y;
			modify(1,a[x],1);
		}
		else{
			modify(1,b[x],1);
			b[x]=y;
			modify(1,b[x],-1);
		}
		printf("%d\n",query());
	}
	return 0;
}
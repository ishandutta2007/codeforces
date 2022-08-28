//CF853C_2
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
const int N = 222222;
int n,a[N],b[N][22],c[N][22],t[N];
void build(int l,int r,int k){
	if(l==r)
		return;
	int h=l+r>>1,i,x=l,y=h+1;
	for(i=l;i<=r;i=i+1){
		if(a[i]<=h)
			b[i][k]=x,c[i][k]=y-1,t[x++]=a[i];
		else
			b[i][k]=x-1,c[i][k]=y,t[y++]=a[i];
	}
	for(i=l;i<=r;i=i+1)
		a[i]=t[i];
	build(l,h,k+1);
	build(h+1,r,k+1);
}
int query(int L,int R,int x,int l=1,int r=n,int k=0){
	if(x<l)
		return 0;
	if(L<=l&&r<=R)
		return x-l+1;
	int h=l+r>>1,o=0;
	if(L<=h)
		o+=query(L,R,b[x][k],l,h,k+1);
	if(h<R)
		o+=query(L,R,c[x][k],h+1,r,k+1);
	return o;
}
int Q(int l,int r,int u,int d){
	return query(l,r,d)-query(l,r,u-1);
}
LL ans;
void f(int x){
	ans+=(LL)x*(x-1)/2;
}
int main()
{
	int q,i,x,l,r,u,d;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1)
		scanf("%d",&x),a[x]=i;
	build(1,n,0);
	while(q--){
		scanf("%d%d%d%d",&l,&u,&r,&d);
		ans=0;
		f(l-1),f(n-r),f(u-1),f(n-d);
		ans=-ans,f(n);
		f(Q(1,l-1,1,u-1));
		f(Q(r+1,n,1,u-1));
		f(Q(1,l-1,d+1,n));
		f(Q(r+1,n,d+1,n));
		printf("%lld\n",ans);
	}
	return 0;
}
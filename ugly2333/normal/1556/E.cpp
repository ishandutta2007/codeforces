//CF1556E
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
const int N = 1<<18;
const LL inf = 1e18;
int n,q,a[N];
LL s[N],t[N],p[N];
void build(int k=1,int l=1,int r=n){
	if(l==r){
		t[k]=s[l];
		p[k]=s[l];
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	t[k]=max(t[k<<1],t[k<<1|1]);
	p[k]=min(p[k<<1],p[k<<1|1]);
}
LL x,y;
void query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		x=max(x,t[k]);
		y=min(y,p[k]);
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		query(L,R,k<<1,l,h);
	if(h<R)
		query(L,R,k<<1|1,h+1,r);
}
int main()
{
	int i,o,l,r;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		scanf("%d",&o),a[i]=o-a[i];
	for(i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	build();
	for(i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		x=-inf;
		y=inf;
		query(l,r);
		x-=s[l-1];
		y-=s[l-1];
		if(y<0||s[r]!=s[l-1])
			printf("-1\n");
		else
			printf("%lld\n",x);
	}
	return 0;
}
#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int m,n,k,t;
int a[maxn];
struct Seg
{
	int l,r,w;
	Seg(int L=0,int R=0,int W=0):l(L),r(R),w(W){}
}b[maxn];
vector<int> rpos[maxn];
bool check(int x)
{
	for(int i=1;i<=n+1;++i)rpos[i].clear();
	int res=n+1;
	for(int i=1;i<=k;++i)if(b[i].w>x)rpos[b[i].l].push_back(b[i].r);
	for(int i=1;i<=n+1;++i)if(rpos[i].size())
	{
		int r=i;
		for(int j=i;j<=r;++j)
			for(int x:rpos[j])r=max(r,x);
		res+=2*(r-i+1);
		i=r;
	}
	return res<=t;
}
int main()
{
	scanf("%d%d%d%d",&m,&n,&k,&t);
	for(int i=1;i<=m;++i)scanf("%d",&a[i]);
	for(int i=1;i<=k;++i)scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].w);
	int l=0,r=200000,ans=200001;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	int tot=0;
	for(int i=1;i<=m;++i)if(a[i]>=ans)tot++;
	printf("%d\n",tot);
}
#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,m,q;
int p[maxn],a[maxn];
int Ans[maxn];
int to[maxn],nxt[maxn][22],lst[maxn];
int minr[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=m;++i)scanf("%d",&a[i]);
	for(int i=1;i<n;++i)to[p[i]]=p[i+1];
	to[p[n]]=p[1];
	for(int i=1;i<=n;++i)lst[i]=m+1;
	nxt[m+1][0]=m+1;
	for(int i=m;i>=1;--i)
	{
		nxt[i][0]=lst[to[a[i]]];
		lst[a[i]]=i;
	}
	for(int j=1;j<=19;++j)
		for(int i=1;i<=m+1;++i)nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	for(int i=1;i<=m;++i)
	{
		int x=n-1,r=i;
		for(int j=19;j>=0;--j)if(x-(1<<j)>=0)x-=(1<<j),r=nxt[r][j];
		minr[i]=r;
	}
	for(int i=m-1;i>=1;--i)minr[i]=min(minr[i],minr[i+1]);
	for(int i=1;i<=q;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(r>=minr[l])Ans[i]=1;
	}
	for(int i=1;i<=q;++i)printf("%d",Ans[i]);
	return 0;
}
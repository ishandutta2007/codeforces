#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,q;
vector<int> a[maxn],b[maxn];
int rmax[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int j=0;j<=m;++j)b[0].push_back(0),a[0].push_back(0);
	for(int i=1;i<=n;++i)
	{
		a[i].push_back(0),b[i].push_back(0);
		for(int j=1;j<=m;++j)
		{
			int x;
			scanf("%d",&x);
			a[i].push_back(x);
			b[i].push_back(0);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]>=a[i-1][j])b[i][j]=b[i-1][j]+1;
			else b[i][j]=1;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)rmax[i]=max(rmax[i],b[i][j]);
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int len=r-l+1;
		if(rmax[r]>=len)puts("Yes");
		else puts("No");
	}
	return 0;
}
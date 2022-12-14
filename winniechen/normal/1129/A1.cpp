#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 5005
#define ll long long
int mn[N],b[N],n,m,mx;
inline int dis(int x,int y){if(y<x)return n-x+y;return y-x;}
int main()
{
	scanf("%d%d",&n,&m);
	memset(mn,0x3f,sizeof(mn));
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);if(x==y)continue;
		b[x]++,mn[x]=min(mn[x],dis(x,y));
	}
	for(int i=1;i<=n;i++)mx=max(mx,b[i]);
	if(!mx){for(int i=1;i<=n;i++)printf("0 ");puts("");return 0;}
	for(int i=1;i<=n;i++)
	{
		ll ans=0;
		for(int j=1;j<=n;j++)
			if(b[j])ans=max((ll)(b[j]-1)*n+mn[j]+dis(i,j),ans);
		printf("%lld ",ans);
	}puts("");
}
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
int n,m,a,b,ans1[N],ans2[N],vis[N];
bool check(int x)
{
	int la=a,lb=b;n=m=0;memset(vis,0,sizeof(vis));
	for(int i=x;i;i--)if(la>=i)la-=i,ans1[++n]=i,vis[i]=1;
	for(int i=x;i;i--)
	{
		if(vis[i])continue;
		if(i>lb)return 0;
		lb-=i;ans2[++m]=i;
	}return 1;
}
int main()
{
	scanf("%d%d",&a,&b);
	int l=0,r=100001;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}l--;check(l);
	printf("%d\n",n);
	for(int i=1;i<=n;i++)printf("%d ",ans1[i]);puts("");
	printf("%d\n",m);
	for(int i=1;i<=m;i++)printf("%d ",ans2[i]);puts("");
}
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 1000005
struct node{int to,next;}e[N<<1];
int f[N],head[N],cnt,val,ans,n,in1[N];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;in1[x]++;}
void dfs(int x,int from)
{
	if(in1[x]==1)f[x]=0;else f[x]=-0x3f3f3f3f;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)
		{
			dfs(to1,x);
			if(f[x]+f[to1]+1>val)
			{
				ans++;
				f[x]=min(f[x],f[to1]+1);
			}else f[x]=max(f[x],f[to1]+1);
		}
	}
	// printf("%d %d\n",x,f[x]);
}
int main()
{
	scanf("%d%d",&n,&val);memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(int i=1;i<=n;i++)if(in1[i]!=1){dfs(i,0);break;}
	printf("%d\n",ans+1);return 0;
}
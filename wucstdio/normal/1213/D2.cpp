#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
#define lson o<<1
#define rson o<<1|1
using namespace std;
int n,k,size[1000005];
ll sum[1000005];
priority_queue<int>q[200005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		for(int j=0;v;j++,v>>=1)
		{
			q[v].push(j);
			sum[v]+=j;
			size[v]++;
			if(q[v].size()>k)
			{
				int x=q[v].top();
				sum[v]-=x;
				q[v].pop();
			}
		}
	}
	ll ans=1e9;
	for(int i=1;i<=200000;i++)
	{
		if(size[i]>=k)
		  ans=min(ans,sum[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
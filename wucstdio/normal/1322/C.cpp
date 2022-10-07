#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
int t,n,m,col[500005];
ll sum[500005],c[500005];
vector<int>to[500005];
bool cmp(int i,int j)
{
	return col[i]<col[j];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=max(n,m);i++)col[i]=0,sum[i]=0,to[i].clear();
		for(int i=1;i<=n;i++)scanf("%lld",&c[i]),sum[0]+=c[i];
		while(m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			to[u].push_back(v);
		}
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			sort(to[i].begin(),to[i].end(),cmp);
			int pre=-1;
			for(auto j:to[i])
			{
				if(col[j]!=pre)pre=col[j],tot++;
				sum[pre]-=c[j];
				col[j]=tot;
				sum[tot]+=c[j];
			}
		}
		ll ans=0;
		for(int i=1;i<=tot;i++)ans=__gcd(ans,sum[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
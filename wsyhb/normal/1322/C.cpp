#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a; 
}
const int max_n=5e5+5;
long long c[max_n];
vector<int> edge[max_n];
typedef pair<int,int> P;
map<P,long long> sum;
const int mod=1e9+7;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",c+i);
			edge[i].clear();
		}
		for(int i=1;i<=m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			edge[v].push_back(u);
		}
		sum.clear();
		for(int i=1;i<=n;++i)
		{
			if(edge[i].empty())
				continue;
			sort(edge[i].begin(),edge[i].end());
			int v=0;
			for(vector<int>::iterator it=edge[i].begin();it!=edge[i].end();++it)
				v=(v*(n+1ll)+(*it))%mod;
			sum[P(edge[i].size(),v)]+=c[i];
		}
		long long ans=0;
		for(map<P,long long>::iterator it=sum.begin();it!=sum.end();++it)
			ans=gcd(ans,it->second);
		printf("%lld\n",ans);
	}
	return 0;
}
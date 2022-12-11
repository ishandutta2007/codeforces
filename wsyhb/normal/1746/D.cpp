#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
vector<int> son[max_n];
int s[max_n],sum[max_n];
typedef pair<long long,int> P;
P dfs(int x,int fa,int k)
{
	sum[x]=sum[fa]+s[x];
	if(son[x].empty())
		return P(1ll*k*sum[x],sum[x]);
	int d=son[x].size();
	long long res1=0;
	vector<int> val;
	for(int y:son[x])
	{
		P res=dfs(y,x,k/d);
		res1+=res.first;
		val.push_back(res.second);
	}
	sort(val.begin(),val.end(),greater<int>());
	for(int i=0;i<k%d;++i)
		res1+=val[i];
	return P(res1,val[k%d]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=2;i<=n;++i)
		{
			int p;
			scanf("%d",&p);
			son[p].push_back(i);
		}
		for(int i=1;i<=n;++i)
			scanf("%d",s+i);
		printf("%lld\n",dfs(1,0,k).first);
		for(int i=1;i<=n;++i)
			son[i].clear();
	}
	return 0;
}
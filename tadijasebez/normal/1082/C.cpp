#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
int s[N],r[N];
vector<int> Q[N];
set<int> work;
ll sum[N];
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i %i",&s[i],&r[i]),Q[s[i]].push_back(r[i]);
	for(i=1;i<=m;i++) sort(Q[i].begin(),Q[i].end()),reverse(Q[i].begin(),Q[i].end());
    for(i=1;i<=m;i++) work.insert(i);
    ll sol=0,ans=0;
    for(i=1;i<=n;i++)
	{
		vector<int> del;
		for(auto p:work)
		{
			if(Q[p].size()<i) ans-=sum[p],del.pb(p);
			else
			{
				sum[p]+=Q[p][i-1];
				ans+=Q[p][i-1];
				if(sum[p]<0)
				{
					ans-=sum[p];
					del.pb(p);
				}
			}
		}
		for(auto p:del) work.erase(p);
		sol=max(sol,ans);
	}
	printf("%lld\n",sol);
	return 0;
}
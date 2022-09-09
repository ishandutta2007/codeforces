#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll inf=9e18;
const int N=100050;
vector<int> E[N];
int cnt[N],sz;
void DFS(int u, int p, int d)
{
	cnt[d]++;sz=max(sz,d);
	for(int v:E[u]) if(v!=p) DFS(v,u,d+1);
}
int main()
{
	int n,k,p,i,u,v;
	scanf("%i %i %i",&n,&k,&p);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0,0);
	k=min(k,n-1);
	int ans=1,top=k,bot=2,mid;
	while(top>=bot)
	{
		mid=top+bot>>1;
		ll cost=0,mn=inf,sum=0;
		int j=1;
		for(i=1;i<=sz;i++)
		{
			cost+=sum;
			sum+=cnt[i];
			while(j<i && sum-cnt[j]>=mid)
			{
				cost-=(ll)cnt[j]*(i-j);
				sum-=cnt[j];
				j++;
			}
			if(sum<mid) continue;
			ll ost=sum-mid;
			ll tmp=cost-ost*(i-j);
			mn=min(mn,tmp);
		}
		if(mn<=p) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	printf("%i\n",ans);
	return 0;
}
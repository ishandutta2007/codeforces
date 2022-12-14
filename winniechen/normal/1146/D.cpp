#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
#define N 100005
ll n,ans,tmp;int f[N<<1],a,b,vis[N<<1],s[N<<1],lim,gcd;
void Dijkstra()
{
	memset(f,0x3f,sizeof(f));
	priority_queue<pair<int ,int > >q;
	q.push(make_pair(0,0));f[0]=0;
	while(!q.empty())
	{
		int x=q.top().second;q.pop();if(vis[x])continue;vis[x]=1;
		if(x+a<lim&&f[x+a]>max(f[x],x+a))f[x+a]=max(f[x],x+a),q.push(make_pair(-f[x+a],x+a));
		if(x-b>=0&&f[x-b]>f[x])f[x-b]=f[x],q.push(make_pair(-f[x-b],x-b));
	}
}
int main()
{
	scanf("%lld%d%d",&n,&a,&b);lim=a+b;
	gcd=__gcd(a,b);
	if(n>=lim)
	{
		ll tt=n/gcd;
		ans=gcd*(lim/gcd+tt+1)*(tt-lim/gcd)/2;
		for(ll i=tt*gcd;i<=n;i++)ans+=tt+1;
	}
	Dijkstra();
	for(int i=0;i<lim&&i<=n;i++)if(f[i]<lim)s[f[i]]++;
	for(int i=0;i<lim&&i<=n;i++)s[i]+=s[i-1],ans+=s[i];
	printf("%lld\n",ans);
}
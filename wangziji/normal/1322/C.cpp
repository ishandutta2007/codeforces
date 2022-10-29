#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#pragma GCC optimize 2
#define int long long
using namespace std;
inline int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y; 
}
int a[500005];
vector <int> e[500005],qwq;
int bel[500005],vis[500005],s[500005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) bel[i]=0,e[i].clear();
		int cnt=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%lld%lld",&u,&v);
			e[u].push_back(v);
		}
		for(int i=1;i<=n;i++)
		{
			for(auto j:e[i])
			{
				if(!vis[bel[j]]) vis[bel[j]]=++cnt,qwq.push_back(bel[j]);
				bel[j]=vis[bel[j]],s[bel[j]]=0;
			}
			for(auto j:qwq) vis[j]=0;
			qwq.clear();
		}
		for(int i=1;i<=n;i++)
			s[bel[i]]+=a[i];
		int ans=0;
		for(int i=1;i<=cnt;i++) ans=gcd(ans,s[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
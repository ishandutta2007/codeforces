#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, x, y) for(ll i = (x); i <= (y); ++i)
#define FOr(i, x, y) for(ll i = (x); i >= (y); --i)
#define pb push_back
#define N 200050
ll n,m,s;
vector<ll>G[N];
ll pre[N],bel[N];
inline ll read()
{
	ll x = 0, f = 1;
	char ch = 0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-48;
	return x*f;	
}
bool vis[N];
void solve()
{
	queue<ll> q;
	for(auto v:G[s]) vis[v] = 1, pre[v] = s, q.push(v), bel[v] = v;
	vis[s] =1 ;
	while (!q.empty())
	{
		ll f = q.front(); q.pop();
		for(auto v:G[f])
		{
		//	cerr<<f<<','<<v<<endl;
			if (vis[v])
			{
				
				if(v==s || bel[f] == bel[v]) continue;
				puts("Possible");
				vector<ll> ans1, ans2;
				ans1.clear(), ans2.clear();
				ll x = v;
				while (x!=s) ans1.pb(x), x=pre[x];
				ans1.pb(s);
				
				ans2.pb(v); x = f;
				while (x!=s) ans2.pb(x), x=pre[x];
				ans2.pb(s);
				printf("%lld\n",(ll)ans1.size());
				FOr(i, (ll)ans1.size()-1, 0) printf("%lld%c",ans1[i],i==0?10:32);
				printf("%lld\n",(ll)ans2.size());
				FOr(i, (ll)ans2.size()-1, 0) printf("%lld%c",ans2[i],i==0?10:32);

				exit(0);
			}
			pre[v] = f, vis[v] = 1;
			bel[v] = bel[f];
			q.push(v);
		}
	}
	puts("Impossible");
}
int main()
{
	n = read();m = read(), s = read();
	For(i, 1, m)
	{
		ll u = read(), v = read();
		G[u].pb(v);
		
	}
	solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll mod=1e9+7;
typedef map<ll,int> mm;

ll x[maxn],ans;
vector<int>e[maxn];

void dfs(int u=1,int pre=0,mm lst={})
{
    mm now;
    now[x[u]]++;
    for(auto i:lst)
    {
        now[__gcd(i.first,x[u])]+=i.second;
    }
    for(auto i:now)
    {
        ans=(ans+i.first*i.second)%mod;
    }
    for(auto i:e[u])
    {
        if(i!=pre)
            dfs(i,u,now);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x[i]);
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs();
    printf("%lld",ans);
	return 0;
}
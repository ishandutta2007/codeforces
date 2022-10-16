#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll fac[maxn+5];
ll ans;
vi e[maxn+5];

void dfs(int now,int fa)
{
    int br=0;
    for(auto v: e[now]) if(v!=fa) dfs(v,now),br++;
    if(now==1) ans=ans*fac[br]%mod;
    else ans=ans*fac[br+1]%mod;
}

int main()
{
    fac[0]=1;
    rep(i,1,maxn) fac[i]=fac[i-1]*i%mod;

    int n; scanf("%d",&n);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    ans=1;
    dfs(1,0);
    printf("%I64d\n",ans*n%mod);
    return 0;
}
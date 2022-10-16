#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5];
int in[maxn+5],out[maxn+5],cnt;
vi e[maxn+5];
vector<pii> vec[maxn+5];

void dfs(int now,int dep)
{
    in[now]=++cnt;
    vec[dep].pb({cnt,vec[dep].back().SE^(1<<(s[now]-'a'))});
    for(auto v: e[now]) dfs(v,dep+1);
    out[now]=cnt;
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,2,n)
    {
        int x; scanf("%d",&x);
        e[x].pb(i);
    }
    scanf("%s",s+1);
    rep(i,1,n) vec[i].pb({0,0});
    dfs(1,1);
    rep(i,1,m)
    {
        int v,h; scanf("%d%d",&v,&h);
        int l=lower_bound(vec[h].begin(),vec[h].end(),mp(in[v],-1))-vec[h].begin()-1;
        int r=upper_bound(vec[h].begin(),vec[h].end(),mp(out[v],inf))-vec[h].begin()-1;
        int x=vec[h][l].SE^vec[h][r].SE;
        if(x-(x&-x)) puts("No");
        else puts("Yes");
    }
    return 0;
}
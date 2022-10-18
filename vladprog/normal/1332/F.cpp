#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int MOD=998244353;
const int N=3e5+100;

vector<int> g[N];
int dp[N],dpv[N],dpe[N],dpve[N];

int calc(int v,int p,bool is,bool isv,bool ise,bool isve)
{
    int res=1;
    for(int to:g[v])
        if(to!=p)
        {
            int cur=0;
            if(is) cur+=dp[to];
            if(isv) cur+=dpv[to];
            if(ise) cur+=dpe[to];
            if(isve) cur+=dpve[to];
            res=res*cur%MOD;
        }
    return res;
}

void dfs(int v,int p)
{
    for(int to:g[v])
        if(to!=p)
            dfs(to,v);
    dp[v]=calc(v,p,1,1,1,1);
    dpv[v]=(calc(v,p,1,1,1,0)-calc(v,p,1,1,0,0)+MOD)%MOD;
    dpe[v]=calc(v,p,1,1,1,1);
    dpve[v]=calc(v,p,1,1,1,0);
//    cout<<v<<" : "<<dp[v]<<" "<<dpv[v]<<" "<<dpe[v]<<" "<<dpve[v]<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<(dp[1]+dpv[1]+MOD-1)%MOD;
}
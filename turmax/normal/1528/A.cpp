#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
vector <int> a[maxn];
int l[maxn];
int r[maxn];
bool used[maxn];
int dp[maxn][2];
void dfs(int x)
{
    used[x]=1;
    dp[x][0]=0;dp[x][1]=0;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
            dp[x][0]+=max(dp[v][0]+abs(l[x]-l[v]),dp[v][1]+abs(l[x]-r[v]));
            dp[x][1]+=max(dp[v][0]+abs(r[x]-l[v]),dp[v][1]+abs(r[x]-r[v]));
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;++i) {a[i].clear();used[i]=0;}
        for(int i=0;i<n;++i) {cin>>l[i]>>r[i];}
        for(int i=0;i<(n-1);++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].push_back(y);a[y].push_back(x);
        }
        dfs(0);
        cout<<max(dp[0][0],dp[0][1])<<'\n';
    }
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;

int n,ans[N];
vi edg[N];
unordered_map<int,int>mp[N];
void dfs(int u,int f=0,int d=0)
{
//    cout<<u<<' '<<f<<endl;
    mp[u][d]++;
    ans[u]=d;
    for(auto v:edg[u])if(v!=f)
    {
        dfs(v,u,d+1);
        if(mp[v].size()>mp[u].size())
        {
            mp[u].swap(mp[v]);
            ans[u]=ans[v];
        }
        for(auto i:mp[v])
        {
            mp[u][i.fi]+=i.se;
            if(mp[u][i.fi]>mp[u][ans[u]])
            {
                ans[u]=i.fi;
            }
            else if(mp[u][i.fi]==mp[u][ans[u]])
            {
                ans[u]=min(ans[u],i.fi);
            }
        }
        mp[v].clear();
        ans[v]-=d+1;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
    return 0;
}
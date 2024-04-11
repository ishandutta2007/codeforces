#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
int arr[N],n,D[N],U[N],cnt;
vi edg[N];
map<int,int>mp,m[N];
int dfs2(int u=1,int f=0)
{
    if(D[u])return 0;
    int ret=(U[u]==cnt);
    for(auto v:edg[u])if(v!=f)
    {
        U[v]+=U[u];
        ret+=dfs2(v,u);
    }
    return ret;
}
void dfs(int u=1,int f=0)
{
    m[u][arr[u]]++;
    for(auto v:edg[u])if(v!=f)
    {
        dfs(v,u);
        if(m[v].find(arr[u])!=m[v].end())U[v]++,cnt++;

        if(m[v].size()>m[u].size())m[u].swap(m[v]);
        for(auto i:m[v])m[u][i.fi]+=i.se;
        m[v].clear();
    }
    if(m[u][arr[u]]!=mp[arr[u]])D[u]=1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs();
    cout<<dfs2();
    return 0;
}
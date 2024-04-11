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
const int N = 100 + 10;
const int mod = 1e9 + 7;
int n,k,len[N],son[N],vis[N];
vi edg[N];
void dfs(int u=1)
{
    len[u]=0;
    son[u]=0;
    for(auto v:edg[u])
    {
        dfs(v);
        if(len[v]>len[u])
        {
            len[u]=len[v];
            son[u]=v;
        }
    }
    len[u]++;
}
void dfs2(int u=1)
{
    cout<<u<<' ';
    if(!vis[u])k--;

    for(auto v:edg[u])if(k&&v!=son[u])
    {
        dfs2(v);
        cout<<u<<' ';
    }
    if(son[u])
    {
        if(k||vis[u])
        {
            dfs2(son[u]);
            if(!vis[u])cout<<u<<' ';
        }
    }
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)edg[i].clear();
    for(int i=2;i<=n;i++)
    {
        int a;cin>>a;
        edg[a].push_back(i);
    }
    dfs();
    if(k<=len[1])
    {
        cout<<k-1<<endl;
        int id=1;
        while(k--)
        {
            cout<<id<<' ';
            id=son[id];
        }
        cout<<endl;
        return;
    }

    cout<<k*2-len[1]-1<<endl;
    memset(vis,0,sizeof(vis));
    int id=1;
    while(id)
    {
        vis[id]=1;
        id=son[id];
    }
    k-=len[1];
    dfs2();
    cout<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)solve();
	return 0;
}
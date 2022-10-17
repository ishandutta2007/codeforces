#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int sz[1005],f[1005],mk[1005];
int rt=0,n;
vector<int> g[1005];
void dfs(int u,int fa)
{
    sz[u]=1;
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        f[u]=max(f[u],sz[v]);
    }
    f[u]=max(f[u],n-sz[u]);
    if(f[rt]>f[u]) rt=u;
}
void dfs2(int u,int fa)
{
    sz[u]=1;
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs2(v,u);
        sz[u]+=sz[v];
    }
}
bool cmp(int a,int b) {return sz[a]<sz[b];}
vector<pair<pair<int,int>,int>> ans;
int a1[1005],a2[1005];
int p1=1,p2=1;
void dfs4(int u,int fa,int dis)
{
    ans.push_back({{fa,u},a1[p1]-dis});
    dis+=a1[p1]-dis;
    p1++;
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs4(v,u,dis);
    }
}
void dfs5(int u,int fa,int dis)
{
    ans.push_back({{fa,u},a2[p2]-dis});
    dis+=a2[p2]-dis;
    p2++;
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs5(v,u,dis);
    }
}
int main()
{
    cin>>n;
    if(n==1) return 0;
    if(n==2) return cout<<"1 2 1"<<endl,0;
    int t=2*n*n/9;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    f[0]=n;
    dfs(1,-1);
    dfs2(rt,-1);
    int cnt1=0,cnt2=n-1;
    while(1)
    {
        memset(mk,0,sizeof(mk));
        cnt1=0,cnt2=n-1;
        random_shuffle(g[rt].begin(),g[rt].end());
        int ok=0;
        for(int i : g[rt])
        {
            mk[i] = 1;
            cnt1 += sz[i];
            cnt2 -= sz[i];
            if(cnt1 * cnt2 + cnt1 + cnt2 >= t)
            {
                ok = 1;
                break;
            }
        }
        if(ok) break;
    }
    for(int i=1;i<=cnt1;++i) a1[i]=i;
    for(int i=1;i<=cnt2;++i) a2[i]=(cnt1+1)*i;
    for(int i:g[rt])
    {
        if(mk[i]==1) dfs4(i,rt,0);
        else dfs5(i,rt,0);
    }
    for(auto p:ans)
        cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;
}
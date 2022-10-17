#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int par[200005],sz[200005];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
struct edge
{
    int u,v,w;
    bool operator < (const edge & e) const
    {
        return w < e.w;
    }
}es[200005];
ll w[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ii par[i]=i;
    ii sz[i]=1;
    for(int i=1;i<n;++i) cin>>es[i].u>>es[i].v>>es[i].w;
    sort(es+1,es+n);
    int l = 1;
    ll ans = 0;
    for(int i=1;i<n;++i)
    {
        if(es[i].w != es[i+1].w)
        {
            for(int j = l; j <= i; ++j)
            {
                int x = find(es[j].u), y = find(es[j].v);
                if(x != y)
                {
                    ans += 1ll * sz[x] * sz[y];
                    par[x] = y;
                    sz[y] += sz[x];
                }
            }
            w[es[i].w] = ans;
            l = i+1;
        }
    }
    for(int i=1;i<=200000;++i) if(!w[i]) w[i]=w[i-1];
    while(m--)
    {
        int tmp;
        cin>>tmp;
        cout<<w[tmp]<<" ";
    }
    cout<<endl;
}
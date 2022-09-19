#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e3+5;
int a[maxn];int par[maxn];int sz[maxn];vector<int> v[maxn];
int get(int x)
{
    if(par[x]==(-1)) return x;
    int ans=get(par[x]);par[x]=ans;return ans;
}
void merg(int x,int y,int w)
{
    w^=a[x];w^=a[y];
    x=get(x);y=get(y);if(x==y) assert(false);
    if(sz[x]>sz[y]) swap(x,y);
    assert(!a[x]);assert(!a[y]);par[x]=y;for(auto h:v[x]) v[y].push_back(h); sz[y]+=sz[x];
    if(w) for(int u:v[x]) a[u]^=1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int b[n][n];for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin>>b[i][j];
        for(int i=0;i<n;++i) {a[i]=0;par[i]=(-1);sz[i]=1;v[i]={i};}
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(b[i][j]==b[j][i]) continue;
                if(get(i)==get(j)) continue;
                if(b[i][j]<b[j][i])
                {
                    merg(i,j,0);
                }
                else
                {
                    merg(i,j,1);
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(a[i]^a[j]) swap(b[i][j],b[j][i]);
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cout<<b[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
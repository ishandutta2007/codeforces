#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 2005;
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
struct edge {
    int u,v;
    ll w;
    bool operator < (const edge & e) const
    {
        return w < e.w;
    }
}es[maxn*maxn+maxn];
int tot = 0;
int x[maxn],y[maxn],c[maxn],k[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;++i) par[i]=i;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
    ii cin>>c[i];ii cin>>k[i];
    ii es[++tot] = {0,i,c[i]};
    for(int i=1;i<=n;++i) {
        for(int j=i+1;j<=n;++j)
            es[++tot] = {i,j,1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]) ) };
    }
    sort(es+1,es+1+tot);
    ll ans = 0;
    vector<pair<int,int>> v;
    vector<int> p;
    for(int i=1;i<=tot;++i)
    {
        int x=find(es[i].u), y = find(es[i].v);
        if(x == y) continue;
        par[x] = y;
        if(es[i].u == 0) p.push_back(es[i].v);
        else v.push_back({es[i].u, es[i].v});
        ans += es[i].w;
    }
    cout<<ans<<endl;
    cout<<p.size()<<endl;
    for(int i:p) cout<<i<<" ";cout<<endl;
    cout<<v.size()<<endl;
    for(pair<int,int> i:v) cout<<i.first<<" "<<i.second<<endl;
}
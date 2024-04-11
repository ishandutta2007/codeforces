#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 5005;
int a[maxn],b[maxn],c[maxn];
pair<int,int> es[5005];
int vis[5005];
vector<int> g[5005];
int mx[5005];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    ii cin>>a[i]>>b[i]>>c[i];
    ii es[i]={c[i],i};
    sort(es+1,es+1+n,[&](pair<int,int> a,pair<int,int> b){return a.first>b.first;});
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        g[v].push_back(u);
    }
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        if(k < a[i])
        {
            cout << -1 << endl;
            return 0;
        }
        mx[i-1] = k-a[i];
        k += b[i];
        mx[i] = k;
    }
    for(int i=n-1;i>=1;--i) mx[i]=min(mx[i],mx[i+1]);
    for(int i=1;i<=n;++i)
    {
        int maxx = es[i].second;
        for(int v : g[es[i].second]) maxx = max(maxx, v);
        if(mx[maxx])
        {
            ans += es[i].first;
            for(int j=maxx;j<=n;++j) mx[j]--;
            for(int i=n-1;i>=1;--i) mx[i]=min(mx[i],mx[i+1]);
        }
    }
    cout << ans << endl;
}
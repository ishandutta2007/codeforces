#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

struct edge {
    int v,id;
};
vector<edge> g[100005];
int ans[100005];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    int f = 0;
    vector<int> v;
    for(int i=1;i<=n;++i)
    {
        if(f) break;
        if(g[i].size() > 2)
            for(int j=0;j<3;++j) ans[g[i][j].id] = j, f++, v.push_back(g[i][j].id);
    }
    for(int i=0;i<n-1;++i)
        if(find(v.begin(), v.end(), i) == v.end()) ans[i] = f++;
    for(int i=0;i<n-1;++i) cout<<ans[i]<<" ";cout<<endl;
}
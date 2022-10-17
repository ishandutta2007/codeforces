
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
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 200005;
vector<int> g[maxn];
int a[maxn],b[maxn];
int vis[maxn];
vector<int> v;
void dfs(int u)
{
    v.push_back(u);
    vis[u] = 1;
    for(int v : g[u])
    {
        if(vis[v]) continue;
        dfs(v);
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ii cin>>a[i];
    ii
    {
        int tmp;
        cin>>tmp;
        g[tmp].push_back(i);
        g[i].push_back(tmp);
        b[i] = tmp;
    }
    int ans = 0;
    ii
    {
        if(vis[i]) continue;
        v.clear();
        dfs(i);
        int a1 = v[0];
        for(int i=1;i<=v.size()+2;++i) a1 = b[a1];
        int mn = a[a1];
        int p = b[a1];
        while(p != a1)
        {
            mn = min(mn, a[p]);
            p = b[p];
        }
        ans += mn;
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 100005;
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
int a[10005];
vector<int> g[maxn];
int main() {
    int t;
    cin >> t;
    while(t--)  {
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n*m;++i) cin>>a[i];
        for(int i=1;i<=n*m;++i) par[i]=i;
        auto get = [&](int i,int j) {return (i-1)*m+j;};
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=m;++j) {
                int x=get(i,j),y=get(n+1-i,j),z=get(i,m+1-j);
                par[find(x)]=find(y);
                par[find(y)]=find(z);
            }
        }
        for(int i=1;i<=n*m;++i) g[i].clear();
        for(int i=1;i<=n*m;++i) g[find(i)].push_back(i);
        ll ans = 0;
        for(int i=1;i<=n*m;++i) {
            if(g[i].empty()) continue;
            vector<int> v;
            for(int j : g[i]) v.push_back(a[j]);
            sort(all(v));
            int mid = v[v.size()/2];
            for(int k : v) ans += abs(mid - k);
        }
        cout << ans << endl;
    }
}
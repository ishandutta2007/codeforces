
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 42(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 200005;
set<int> g[maxn];
//vi g[maxn];
int deg[maxn], ok[maxn];
pii es[maxn];
int main() {
    int t;
    cin>>t;
    int ca=0;
    while(t--) {
        int n,k;
        cin>>n>>k;
//        memset(deg, 0, sizeof(deg));
//        memset(ok, 0, sizeof(ok));
        ok[0] = deg[0] = 0;
        ii g[i].clear(), deg[i]=0, ok[i]=0;
        for(int i=1;i<n;++i) {
            int u,v;
            cin>>u>>v;
            g[u].insert(v);
            g[v].insert(u);
            deg[u]++;
            deg[v]++;
            es[i]={u,v};
        }
        ++ca;
//        cout << "Case " << ca << ": " << endl;
//        cout << n << " " << k << endl;
//        for(int i=1;i<n;++i) {
//            auto p=es[i];
//            cout<<p.first<<" "<<p.second<<endl;
//        }

        if(k == 1) {
            cout << n-1 << endl;
            continue;
        }
        queue<int> q;
        for(int i=1;i<=n;++i) if(deg[i]==1) q.push(i);
        int ans = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(deg[cur] == 0) continue;
            assert(cur <= n && cur >= 1);
            int v = *g[cur].begin();
//            cout << v << endl;
            assert(v <= n && v >= 1);
            g[v].erase(cur);
            deg[v]--;
            ok[v]++;
            if(ok[v] == k) ok[v]=0,++ans;
            if(deg[v] == 1 && ok[v] == 0) q.push(v);
        }
        cout << ans << endl;
    }
}
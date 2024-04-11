
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

int deg[200005],rk[200005];
vector<int> g[200005];
struct edge {
    int u,v;
}es[200005];
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i) deg[i]=0;
        for(int i=1;i<=n;++i) g[i].clear();
        int tp=0;
        for(int i=1;i<=m;++i) {
            int t,u,v;
            cin>>t>>u>>v;
            if(t==1) {
                g[u].push_back(v);
                deg[v]++;
            } else {
                es[++tp]={u,v};
            }
        }

        queue<int> q;
        for(int i=1;i<=n;++i) if(!deg[i]) q.push(i);
        int cnt=0;
        while(!q.empty()) {
            int cur=q.front();q.pop();
            ++cnt;rk[cur]=cnt;
            for(int v:g[cur]) {
                deg[v]--;
                if(!deg[v]) q.push(v);
            }
        }
        if(cnt != n) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int i=1;i<=tp;++i) {
            int u=es[i].u,v=es[i].v;
            if(rk[u] < rk[v]) g[u].pb(v);
            else g[v].pb(u);
        }
        for(int i=1;i<=n;++i) {
            for(int v:g[i]) cout<<i<<" "<<v<<endl;
        }
        
    }
}

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
int a[maxn], b[maxn], rt[maxn];
ll dp[maxn];
vi g[maxn], lst[maxn], nxt[maxn];
ll ans = 0;
void dfs(int u,int fa) {
    dp[u] = a[u];
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        if(dp[v] >= 0) {
            dp[u] += dp[v];
            lst[u].pb(v);
        } else {
            nxt[u].pb(v);
        }
    }
    ans += dp[u];
}
vi ansv;
void print(int u) {
    for(int v : lst[u]) {
        print(v);
    }
    ansv.pb(u);
    for(int v : nxt[u]) {
        print(v);
    }
}
int main() {
    int n;
    cin>>n;
    ii cin>>a[i];
    ii {
        cin>>b[i];
        if(b[i]!=-1) g[b[i]].pb(i);
        else rt[i]=1;
    }
    for(int i=1;i<=n;++i) {
        if(rt[i]) {
            dfs(i,0);
            print(i);
        }
    }
    cout << ans << endl;
    for(int i:ansv)cout<<i<<" ";cout<<endl;

}
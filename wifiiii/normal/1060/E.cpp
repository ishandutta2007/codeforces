#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 200005;
vector<int> g[maxn];
ll dp[maxn][2], dp2[maxn][2], sz[maxn];
ll ans = 0;
void dfs(int u, int fa) {
    dp[u][0] = 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        for(int i=0;i<2;++i) {
            for(int j=0;j<2;++j) {
                int r=(i+j+1)%2;
                ll sum = dp2[u][i] * dp[v][j] + dp2[v][j] * dp[u][i] + dp[u][i] * dp[v][j];
                ll cnt = dp[u][i] * dp[v][j];
                ans += (sum + cnt * ((2-r)%2)) / 2;
            }
        }
        dp[u][0] += dp[v][1];
        dp[u][1] += dp[v][0];
        dp2[u][0] += dp2[v][1] + dp[v][1];
        dp2[u][1] += dp2[v][0] + dp[v][0];
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<n;++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
}
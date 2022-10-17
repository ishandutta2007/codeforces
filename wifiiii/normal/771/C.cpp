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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 200005;
ll dp[maxn][5],dp2[maxn][5],ans;
vector<int> g[maxn];
int n,k;
void dfs(int u,int fa) {
    dp[u][0]=1;
    ll la=ans;
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        ll la2=ans;
        for(int i=0;i<k;++i)
            for(int j=0;j<k;++j) {
                ll cnt=dp[u][i]*dp[v][j],cnt2=dp[v][j]*dp2[u][i]+dp[u][i]*dp2[v][j]+dp[u][i]*dp[v][j],len=i+j+1;
                ans+=(cnt2+cnt*((k-len%k)%k))/k;
            }
        for(int i=0;i<k;++i) dp2[u][(i+1)%k]+=dp2[v][i]+dp[v][i];
        for(int i=0;i<k;++i) dp[u][(i+1)%k]+=dp[v][i];
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    cout<<ans<<endl;
}
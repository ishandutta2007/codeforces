#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 500005;
int a[maxn], n, mx[maxn], dp[maxn], stk[maxn], tp=0;
vector<int> g[maxn];
void add(int x, int v) {for(;x<=n;x+=x&-x) mx[x]=max(mx[x],v);}
int get(int x) {int ret=0;for(;x;x-=x&-x)ret=max(ret,mx[x]);return ret;}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        tp=0;
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i) mx[i]=dp[i]=0,g[i].clear();
        for(int i=1;i<=n;++i) {
            while(tp && a[stk[tp]] <= a[i]) --tp;
            if(tp) g[stk[tp]].push_back(i);
            stk[++tp] = i;
        }
        int ans=0;
        for(int i=1;i<=n;++i) {
            dp[i]=max(dp[i],get(a[i])+1);
            for(int v : g[i]) dp[v]=max(dp[v],get(a[v])+2);
            add(a[i],dp[i]);
            ans=max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
}
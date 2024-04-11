
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

int a[4005];
int par[4005],sz[4005],dp[4005];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=2*n;++i) cin>>a[i],par[i]=i,sz[i]=1;
        int mx=0;
        for(int i=1;i<=2*n;++i) {
            if(a[i] > mx) {
                mx = a[i];
            }
            else {
                int x = find(i-1), y = find(i);
                par[x] = y;
                sz[y] += sz[x];
            }
        }
        vi v;
        for(int i=1;i<=2*n;++i) if(par[i]==i) v.pb(sz[i]);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i : v) {
            for(int j=n;j>=i;--j) {
                dp[j] += dp[j-i];
            }
        }
        if(dp[n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
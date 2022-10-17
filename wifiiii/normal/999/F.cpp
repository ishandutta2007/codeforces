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
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

int c[10005],f[10005],h[10005];
int cnt[1005], cnt2[1005];
int dp[10005][1005];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k*n;++i) cin>>c[i];
    for(int i=1;i<=n;++i) cin>>f[i];
    for(int i=1;i<=k;++i) cin>>h[i];
    vector<int> v;
    for(int i=1;i<=n;++i) v.push_back(f[i]);
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    for(int i=1;i<=n;++i) f[i]=lower_bound(all(v),f[i])-v.begin()+1;
    for(int i=1;i<=k*n;++i) {
        if(find(all(v),c[i]) != v.end()) {
            int x=lower_bound(all(v),c[i])-v.begin()+1;
            cnt[x]++;
        }
    }
    for(int i=1;i<=n;++i) cnt2[f[i]]++;
    int ans=0;
    for(int i=1;i<=n*k;++i) {
        for(int j=1;j<=n;++j) {
            // dp[i][j] = max(dp[i][j], dp[i-x][j-1] + h[x])
            for(int x=0;x<=min(i,k);++x) {
                dp[i][j] = max(dp[i][j], dp[i-x][j-1] + h[x]);
            }
        }
    }
    for(int i=1;i<=v.size();++i) {
        ans+=dp[cnt[i]][cnt2[i]];
    }
    cout<<ans<<endl;
}
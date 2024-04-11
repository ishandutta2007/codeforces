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

int a[5005],cnt[30005];
int dp[10][30001];
// 5000 * 5000 * 6
int main() {
    int n=5000,k=4999;
    cin>>n>>k;
    vi v;
    for(int i=1;i<=n;++i) {
        int x;
        cin>>x;
        a[i]=x;
        for(int j=0;j<=5;++j) v.pb(x+j);
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    for(int i=1;i<=n;++i) {
        a[i]=lower_bound(all(v),a[i])-v.begin()+1;
        cnt[a[i]]++;
    }
    for(int i=1;i<=6*n;++i) cnt[i]+=cnt[i-1];
    int ans = 0;
    for(int i=6;i<=6*n;++i) {
        memset(dp[i%7],0,sizeof(dp[i%7]));
        for(int j=1;j<=k;++j) {
             dp[i%7][j] = max(dp[(i+6)%7][j], dp[(i+1)%7][j-1]+cnt[i]-cnt[i-6]);
             ans = max(ans, dp[i%7][j]);
        }
    }
    cout << ans << endl;
}
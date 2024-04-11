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
typedef pair<int,int> pii;

const int maxn = 2005;
ll l[maxn], r[maxn], a[maxn], sum[maxn], dp[maxn];
int main() {
    int n,k;
    cin>>n>>k;
    ii cin>>l[i]>>r[i]>>a[i];l[n+1]=2e9;
    memset(dp, 0x3f, sizeof(dp));
    ii sum[i]=sum[i-1]+a[i];
    ll cur=0,res=k;
    dp[1] = 0;
    ll ans = 8e18;
    for(int i=1;i<=n;++i) {
        cur = l[i], res = k;
        for(int j=i;j<=n;++j) {
            if(cur < l[j]) {
                cur = l[j];
                if(res == 0) res = k;
            }
            if(a[j] > res) {
                int x = a[j] - res;
                ++cur;
                ll t = (x - 1) / k;
                res = (k - x % k) % k;
                cur += t;
            } else res -= a[j];
            if(cur > r[j]) break;
            if(cur < l[j+1]) {
                if(j == n) ans = min(ans, dp[i] + sum[j] - sum[i-1]);
                else dp[j+1] = min(dp[j+1], dp[i] + (sum[j] - sum[i-1] + k - 1) / k * k);
            }
        }
    }
    if(ans >= 4e18) cout << -1 << endl;
    else cout << ans << endl;
}
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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<ll,int> pii;

int dfs(ll x, int dep) {
    if(!x) return 1;
    int cur = 1<<dep;
    if(cur > x) return 0;
    int ret = 0;
    for(int i=0;i<8;++i) if(x>=cur*i) ret+=dfs(x-cur*i, dep+1);
    return ret;
}
const int mod = 1e9+7;
const int inv2 = (mod+1)/2;
ll c2(ll x) {x%=mod;return x%mod*(x+1)%mod;}
ll solve(ll n) {
    n = n / 2 + 1;
    ll ret = c2((n+1)/2);
    if(n & 1) ret -= (n+1)/2;
    ret %= mod;
    if(ret < 0) ret += mod;
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}
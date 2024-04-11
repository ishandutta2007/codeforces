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
#define prt(a, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 200005;
int prea[maxn],pre[maxn],sufc[maxn],suf[maxn];
ll pw[maxn];
const int mod = 1e9+7;
int main() {
    int n;
    pw[0] = 1;
    cin >> n;
    for(int i=1;i<=n;++i) pw[i]=pw[i-1]*3%mod;
    string s;
    cin >> s;
    for(int i=1;i<=n;++i)
    {
        char c = s[i-1];
        pre[i] = pre[i-1] + (c == '?');
        prea[i] = prea[i-1] + (c == 'a');
    }
    for(int i=n;i>=1;--i) {
        char c = s[i-1];
        suf[i] = suf[i+1] + (c == '?');
        sufc[i] = sufc[i+1] + (c == 'c');
    }
    ll ans = 0;
    for(int i=2;i<=n-1;++i) {
        if(s[i-1] == 'b' || s[i-1] == '?') {
            ll x = pre[i-1], y = prea[i-1], p = suf[i+1], q = sufc[i+1];
            ans += y*q%mod*pw[x+p]%mod;
            ans += x*q%mod*pw[x+p-1]%mod;
            ans += y*p%mod*pw[x+p-1]%mod;
            ans += x*p%mod*pw[x+p-2]%mod;
        }
    }
    ans %= mod;
    cout << ans << endl;
}
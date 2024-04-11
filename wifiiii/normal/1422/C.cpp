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
typedef pair<int,int> pii;

const int maxn = 100005;
const int mod = 1e9+7;
const int inv2 = (mod+1)/2;
ll pw[maxn],a[maxn];
ll c2(ll x) {return x*(x+1)%mod*inv2%mod;}
int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    pw[0] = a[0] = 1;
    for(int i=1;i<=n;++i) pw[i]=pw[i-1]*10%mod,a[i]=(a[i-1]+pw[i]*(i+1))%mod;
    for(int i=n-1;i>=0;--i) {
        int m=n-i-1,x=s[i]-'0';ll tmp=0;
        tmp += pw[m] * c2(i) % mod;
        if(m) tmp += a[m-1];
        tmp %= mod;
        tmp = tmp * x % mod;
        ans += tmp;
    }
    ans %= mod;
    cout << ans << endl;
}
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 2005;
const int mod = 1e9+7;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b) {
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
void init(int n) {
    f[0] = 1;
    for(int i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
    rf[n] = fpow(f[n],mod-2);
    for(int i=n-1;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k||k<0)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
int main() {
    init(2000);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a.begin(), a.end(), greater<int>());
        int x=0,y=k;
        for(int i=0;i<n;++i) {
            if(a[i]==a[k-1]) ++x;
            if(a[i]>a[k-1]) --y;
        }
        cout<<comb(x,y)<<endl;
    }
}
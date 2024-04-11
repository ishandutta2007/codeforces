#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
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

const int maxn = 105;
int prime[maxn],np[maxn],mu[maxn],tot=0;
void init(int n) {
   np[1]=mu[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot] = i, mu[i] = -1;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>n) break;
           np[i*prime[j]] = 1;
           mu[i*prime[j]] = -mu[i];
           if(i%prime[j]==0) {
               mu[i*prime[j]] = 0;
               break;
           }
       }
   }
}
const ll inf = 2e18;
ll fpow(ll a,ll b){
    ll r=1;
    for(;b;) {
        if(b&1) {
            if(1.0*r*a>inf) return inf;
            r=r*a;
        }
        b>>=1;
        if(!b) break;
        if(1.0*a*a>inf) return inf;
        a=a*a;
    }
    return r;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(60);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        for(int i=1;i<=60;++i) {
            if(!mu[i]) continue;
            ll p = pow(n, (ld)1.0 / i);
            while(fpow(p, i) <= n) ++p; --p;
            ans += (p-1) * mu[i];
        }
        cout << ans << endl;
    }
}
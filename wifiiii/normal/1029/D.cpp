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

#define int ll
int a[200005], b[200005];
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
ll inv(ll a, ll m) {
    ll M = m;
    ll u = 0, v = 1;
    while (a != 0) {
        ll t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return (u % M + M) % M;
}
int32_t main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
//    cin >> t;
//    const int inf = 1000;
    while(t--) {
        int n = 100, k = mrand() % 100 + 2;
        cin >> n >> k;
        unordered_map<int,vector<int>> mp;
//    vector<pair<int,int>> qry;
        for(int i=1;i<=n;++i) {
//            a[i] = mrand() % inf + 1;
            cin >> a[i];
            int x = a[i];
            b[i] = 1;
            while(x) {
                b[i] *= 10;
                x /= 10;
            }
            // for every j, aj * bi + ai =  0  (mod k)
            //                   aj * bi = -ai (mod k)
            //
            b[i] %= k;
            int g = gcd(b[i], k);
            if(a[i] % g) continue; // no solution
            int kk = k/g, aij = inv(b[i]/g, k/g) * (-a[i]/g) % (k/g);
            if(aij < 0) aij += k/g;
            // aj = aij (mod k/g)
            mp[k/g].push_back(aij);
        }
        // ll rr=0;
        // for(int i=1;i<=n;++i)for(int j=1;j<=n;++j) if(i!=j && (1ll*a[i]*b[j]+a[j])%k==0)++rr;

        ll ans = 0;
        for(auto p : mp) {
            int M = p.first;
            unordered_map<int,int> cnt;
            for(int i=1;i<=n;++i) cnt[a[i]%M]++;
            vector<int> &v = p.second;
            for(int i : p.second) ans += cnt[i];
        }
        for(int i=1;i<=n;++i) {
            if((1ll * a[i] * b[i] + a[i]) % k == 0) --ans;
        }
        // assert(rr == ans);
        // cout << rr << endl;
        cout << ans << endl;
    }
}
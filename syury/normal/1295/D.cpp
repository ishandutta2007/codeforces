//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;


void solve(){
    ll a, m;
    cin >> a >> m;
    ll G = __gcd(a, m);
    vector<ll> divs;
    for(ll d = 1; d * d <= m; d++){
        if(m%d == 0){
            divs.push_back(d);
            if(d*d != m)
                divs.push_back(m/d);
        }
    }
    sort(all(divs));
    ll ans = 0;
    for(auto d: divs){
        if(d%G != 0)
            continue;
        ll mu = 1;
        ll kek = d/G;
        for(auto d1: divs){
            if(d1 > d/G)break;
            if(d1 != 1 && kek%d1 == 0){
                kek /= d1;
                mu = -mu;
                if(kek%d1 == 0){
                    mu = 0; break;
                }
            }
        }
        ll cnt = m/d;
        //cerr << d << ' ' << mu << ' ' << cnt << endl;
        ans += cnt * mu;
    }
    cout << ans << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    T = 1;
    cin >> T;
    while(T--)
        solve();
    //cerr << fixed << clock()/(double)CLOCKS_PER_SEC << endl;
    return 0;
}
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

inline ll cost(ll a, ll parts){
    ll d = a/parts;
    ll r = a%parts;
    return d * d * parts + (2*d+1) * r;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> p(n, 1);
    set<pair<ll, int> > nxt;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += cost(a[i], 1);
        nxt.insert(make_pair(cost(a[i], 2) - cost(a[i], 1), i));
    }
    k -= n;
    while(k){
        --k;
        ll d;
        int i;
        tie(d, i) = *nxt.begin();
        nxt.erase(nxt.begin());
        ans += d;
        ++p[i];
        nxt.insert(make_pair(cost(a[i], p[i] + 1) - cost(a[i], p[i]), i));
    }
    cout << ans << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
ll inv(ll a, ll m) {
    ll M = m; a %= m;
    if(a < 0) a += m;
    ll u = 0, v = 1;
    while (a != 0) {
        ll t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return (u % M + M) % M;
}
vector<int> g[1000005];
const int maxn = 5e5+5;
int a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        g[a[i]].push_back(i);
    }
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
        g[b[i]].push_back(i);
    }
    ll M = lcm(n, m), G = gcd(n, m), Inv = inv(m / G, n / G);
    vector<pair<ll,ll>> v;
    for(int i = 1; i <= 2 * max(n, m); ++i) {
        if(g[i].size() > 1) {
            assert(g[i].size() == 2);
            int l = g[i][0], r = g[i][1];
            ll d = l - r, mod = n / G;
            if(d % G) continue;
            d /= G;
            ll k = d * Inv % mod;
            ll p = (r + k * m) % M;
            p %= M;
            if(p < 0) p += M;
            v.push_back({p + 1, M});
        }
    }
    ll lo = 1, hi = 1e18;
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        ll tot = mid;
        for(auto p : v) {
            if(mid >= p.first) tot -= 1 + (mid - p.first) / p.second;
        }
        if(tot >= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, T;

struct DS {
    map<pll, ll> m;
    void init() { m[pll(0, T)] = -INF; }
    void insert(ll s, ll e, ll v) {
        // printf("%lld, %lld, %lld\n", s, e, v);
        auto it = prev(m.upper_bound(pll(s, INF)));
        pll t = (*it).first;
        ll tv = (*it).second;
        auto nit = next(it);
        m.erase(it);
        if (t.first < s) {
            m[pll(t.first, s)] = tv + (t.second - s);
        }
        if (t.second > e) {
            m[pll(e, t.second)] = tv;
            m[pll(s, e)] = v;
            return;
        }
        it = nit;
        while (it != m.end() && (*it).first.second <= e) {
            auto nnit = next(it);
            m.erase(it);
            it = nnit;
        }
        if (it != m.end() && (*it).first.first < e) {
            t = (*it).first;
            tv = (*it).second;
            m.erase(it);
            m[pll(e, t.second)] = tv;
        }
        m[pll(s, e)] = v;
    }
    ll getv(int x) {
        x %= T;
        auto it = prev(m.upper_bound(pll(x, INF)));
        if ((*it).second < 0) {
            return 0;
        }
        return (*it).second + ((*it).first.second - x);
    }
    ll get_min() {
        auto it = m.begin();
        ll ans = LINF;
        while (it != m.end()) {
            if ((*it).second < 0) return 0;
            ans = min(ans, (*it).second + 1);
            it++;
        }
        return ans;
    }
} ds;

ll G[200100], C[200100];
ll D[200100];

int main() {
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++) {
        scanf("%lld%lld", &G[i], &C[i]);
    }
    ll tot = 0;
    for (int i = 1; i < N; i++) {
        scanf("%lld", &D[i]);
        tot += D[i];
        D[i] = (D[i] + D[i - 1]) % T;
    }
    ds.init();
    for (int i = N - 1; i >= 0; i--) {
        C[i] = (C[i] + D[i]) % T;
        if (G[i] < C[i]) {
            ll v = ds.getv(T - C[i]);
            ds.insert(0, T - C[i], v);
            ds.insert(G[i] + T - C[i], T, v + T - C[i]);
        } else {
            ll v = ds.getv(T - C[i]);
            ds.insert(G[i] - C[i], T - C[i], v);
        }
    }
    printf("%lld\n", ds.get_min() + tot);

    return 0;
}
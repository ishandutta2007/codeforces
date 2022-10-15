#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
struct G1 {
    using Type = T;
    inline const static T Id = 0;
    static T op(const T& x, const T& y) { return x + y; }
    static T inv(const T& x) { return -x; }
    static bool cmp(const T& x, const T& y) { return x < y; }
};

int b(int p) { return p & (-p); }

template<typename Group>
class BIT {
private:
    using G = Group;
    using T = typename G::Type;
    const int n, h;
    vector<T> ft;
    T query(int p) {
        T res = G::Id;
        for (; p; p -= b(p)) res = G::op(ft[p], res);
        return res;
    }
public:
    BIT(int n) : n(n), h(31 - __builtin_clz(n)), ft(n + 1, G::Id) { }
    BIT(const vector<T>& a) : BIT((int)size(a)) {
        for (int i = 1; i <= n; ++i) ft[i] = G::op(ft[i - 1], a[i - 1]);
        for (int i = n; i >= 1; --i) ft[i] = G::op(G::inv(ft[i - b(i)]), ft[i]);
    }
    T query(int l, int r) { return G::op(G::inv(query(l)), query(r + 1)); }
    void update(int p, T value) {
        for (++p; p <= n; p += b(p)) ft[p] = G::op(ft[p], value);
    }
    // first r such that G::cmp(query(0, r), value) == false
    int lower_bound(T value) {
        T prefix = G::Id;
        int pos = 0;
        for (int x = h; x >= 0; --x) {
            if (pos + (1 << x) <= n && G::cmp(G::op(prefix, ft[pos + (1 << x)]), value) == true) {
                pos += 1 << x;
                prefix = G::op(prefix, ft[pos]);
            }
        }
        return pos;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<char, int> mp = {{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};

    string s;
    cin >> s;
    int n = (int)size(s);

    constexpr int modmax = 10, tot = modmax * (modmax + 1) / 2;
    auto Id = [&](int ch, int x, int mod) {
        assert(x < mod);
        return ch * tot + mod * (mod - 1) / 2 + x;
    };
    vector<BIT<G1<int>>> bit((int)size(mp) * tot, BIT<G1<int>>(n));

    for (int i = 0; i < n; ++i) {
        for (int mod = 1; mod <= modmax; ++mod) {
            bit[Id(mp[s[i]], i % mod, mod)].update(i, 1);
        }
    }

    auto update = [&](int i, char ch) {
        for (int mod = 1; mod <= modmax; ++mod) {
            bit[Id(mp[s[i]], i % mod, mod)].update(i, -1);
        }
        s[i] = ch;
        for (int mod = 1; mod <= modmax; ++mod) {
            bit[Id(mp[s[i]], i % mod, mod)].update(i, +1);
        }
    };

    int q;
    cin >> q;
    for (int z = 0; z < q; ++z) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            char ch;
            cin >> i >> ch;
            --i;
            update(i, ch);
        }
        else {
            int l, r;
            string e;
            cin >> l >> r >> e;
            --l, --r;
            int k = (int)size(e), cost = 0;
            for (int j = 0; j < k; ++j) {
                cost += bit[Id(mp[e[j]], (l + j) % k, k)].query(l, r);
            }
            cout << cost << endl;
        }
    }

    exit(0);
}
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 400000, MOD = 998244353;

struct mint {
    int x;

    mint() {}

    template <class T> mint(T value) : x(value % MOD) { if (x < 0) x += MOD; }

    mint & operator+=(const mint &oth) { x += oth.x; if (x >= MOD) x -= MOD; return *this; }

    mint & operator-=(const mint &oth) { x -= oth.x; if (x < 0) x += MOD; return *this; }

    mint & operator*=(const mint &oth) { x = (long long) x * oth.x % MOD; return *this; }

    friend mint operator+(mint l, const mint &r) { return l += r; }

    friend mint operator-(mint l, const mint &r) { return l -= r; }

    friend mint operator*(mint l, const mint &r) { return l *= r; }

    mint & operator--() { if (--x == -1) x = MOD - 1; return *this; }

    mint & operator++() { if (++x == MOD) x = 0; return *this; }

    mint operator--(int) { mint temp = *this; --*this; return temp; }

    mint operator++(int) { mint temp = *this; ++*this; return temp; }

    mint operator-() const { return 0 - *this; }

    mint operator+() const { return *this; }

    friend bool operator==(const mint &l, const mint &r) { return l.x == r.x; }

    friend bool operator!=(const mint &l, const mint &r) { return l.x != r.x; }

    friend ostream & operator<<(ostream &out, const mint &a) { return out << a.x; }

    mint pow(long long e = MOD - 2) const {
        mint ans = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                ans *= b;
            }
            b *= b;
            e /= 2;
        }
        return ans;
    }
};

int sub[MAX_N], par[MAX_N], edge[MAX_N], k;
mint all[MAX_N], red[MAX_N], sum;
bool offset[MAX_N];

pair<int, bool> find(int u) {
    if (par[u] == u) {
        return {u, false};
    } else {
        auto [p, x] = find(par[u]);
        offset[u] ^= x;
        par[u] = p;
        return {par[u], offset[u]};
    }
}

void unite(int u, int v) {
    auto [a, x] = find(u);
    auto [b, y] = find(v);

    if (a != b) {
        if (sub[a] > sub[b]) {
            swap(a, b), swap(x, y);
        }

        sub[b] += sub[a];
        par[a] = b;

        offset[a] = x ^ y ^ true;
        all[b] += all[a];
        red[b] += red[a];

        if (offset[a]) {
            sum += all[a] - 2 * red[a];
            red[b] += all[a] - 2 * red[a];
        }
    }
}

void update(int u, int v) {
    all[k] = mint(2).pow(k + 1);
    sub[k] = 1, par[k] = k;

    for (auto i : {u, v}) {
        if (edge[i] == -1) {
            edge[i] = k;
        } else {
            unite(k, edge[i]);
            edge[i] = -1;
        }
    }

    ++k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    fill(edge, edge + n1 + n2, -1);

    while (m--) {
        int u, v;
        cin >> u >> v;
        update(u - 1, n1 + v - 1);
    }

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int u, v;
            cin >> u >> v;
            update(u - 1, n1 + v - 1);
            cout << sum << endl;
        } else {
            vector<int> ans;
            for (int i = 0; i < k; ++i) {
                if (find(i).second) {
                    ans.push_back(i + 1);
                }
            }

            cout << ans.size() << " ";
            for (auto i : ans) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}
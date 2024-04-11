#include <bits/stdc++.h>
using namespace std;

const int N = 100001, M = 998244353;

struct mint {
    int x;

    mint() : x(0) {}

    template <class T> mint(T value) : x(value % M) { if (x < 0) x += M; }

    mint & operator+=(const mint &oth) { x += oth.x; if (x >= M) x -= M; return *this; }

    mint & operator-=(const mint &oth) { x -= oth.x; if (x < 0) x += M; return *this; }

    mint & operator*=(const mint &oth) { x = (long long) x * oth.x % M; return *this; }

    friend mint operator+(mint l, const mint &r) { return l += r; }

    friend mint operator-(mint l, const mint &r) { return l -= r; }

    friend mint operator*(mint l, const mint &r) { return l *= r; }

    mint & operator--() { if (--x == -1) x = M - 1; return *this; }

    mint & operator++() { if (++x == M) x = 0; return *this; }

    mint operator--(int) { mint temp = *this; --*this; return temp; }

    mint operator++(int) { mint temp = *this; ++*this; return temp; }

    mint operator-() const { return 0 - *this; }

    mint operator+() const { return *this; }

    friend bool operator==(const mint &l, const mint &r) { return l.x == r.x; }

    friend bool operator!=(const mint &l, const mint &r) { return l.x != r.x; }

    friend ostream & operator<<(ostream &out, const mint &a) { return out << a.x; }

    mint pow(long long e = M - 2) const {
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

mint fact[N], inv[N];

vector<int> adj[N];
int sub[N], n, k;

map<array<int, 2>, mint> res;
mint ways[N], ans;

void fft(vector<mint>& a) {
    int n = a.size();

    vector<int> reverse(n);
    for (int i = 0; i < n; ++i) {
        reverse[i] = (reverse[i / 2] + (i % 2) * n) / 2;
        if (i < reverse[i]) {
            swap(a[i], a[reverse[i]]);
        }
    }

    for (int i = 1; i < n; i *= 2) {
        mint ratio = mint(3).pow((M - 1) / i / 2);
        for (int j = 0; j < n; j += 2 * i) {
            mint root = 1;
            for (int k = 0; k < i; ++k) {
                mint l = a[j + k];
                mint r = a[i + j + k] * root;
                a[j + k] = l + r;
                a[i + j + k] = l - r;
                root *= ratio;
            }
        }
    }
}

vector<mint> mul(vector<mint> a, vector<mint> b) {
    int n = 1, m = a.size() + b.size();
    while (n < m) {
        n *= 2;
    }

    a.resize(n), b.resize(n);
    fft(a), fft(b);

    for (int i = 0; i < n; ++i) {
        a[i] *= b[i];
    }
    fft(a);

    mint inv_n = mint(n).pow();
    for (auto &i : a) {
        i *= inv_n;
    }
    reverse(a.begin() + 1, a.end());

    a.resize(m - 1);
    return a;
}

vector<mint> calc(int l, int r, vector<int> &v) {
    if (l > r) {
        return {1};
    } else if (l == r) {
        return {1, sub[v[l]]};
    } else {
        int m = (l + r) / 2;
        return mul(calc(l, m, v), calc(m + 1, r, v));
    }
}

void dfs_sub(int u, int p = 0) {
    sub[u] = 1;
    for (auto c : adj[u]) {
        if (c != p) {
            dfs_sub(c, u);
            sub[u] += sub[c];
        }
    }
}

void dfs_ways(int u, int p = 0) {
    for (auto c : adj[u]) {
        if (c != p) {
            sub[u] -= sub[c];
            sub[c] += sub[u];
            dfs_ways(c, u);
            sub[c] -= sub[u];
            sub[u] += sub[c];
        }
    }

    map<int, int> count;
    for (auto c : adj[u]) {
        ++count[sub[c]];
    }

    int m = min(k, (int) adj[u].size());
    vector<mint> ways = calc(0, adj[u].size() - 1, adj[u]);
    for (int i = 0; i <= m; ++i) {
        ways[i] *= fact[k] * inv[k - i];
    }

    map<int, mint> memo;
    for (auto [x, y] : count) {
        mint prv = ways[0], sum = ways[0];
        for (int i = 1; i <= m; ++i) {
            prv = ways[i] - prv * (k - i + 1) * x;
            sum += prv;
        }
        memo[x] = sum;
    }

    for (auto c : adj[u]) {
        res[{u, c}] = memo[sub[c]];
    }
}

void dfs_pull(int u, int p = 0) {
    ways[u] = p > 0 ? res[{u, p}] : 0;
    for (auto c : adj[u]) {
        if (c != p) {
            dfs_pull(c, u);
            ways[u] += ways[c];
        }
    }
}

void dfs_push(int u, int p = 0) {
    for (auto c : adj[u]) {
        if (c != p) {
            ways[u] -= ways[c];
            ways[u] += res[{u, c}];
            ways[c] -= res[{c, u}];
            ways[c] += ways[u];
            dfs_push(c, u);
            ways[c] -= ways[u];
            ways[c] += res[{c, u}];
            ways[u] -= res[{u, c}];
            ways[u] += ways[c];
        }
    }

    for (auto c : adj[u]) {
        ans += ways[c] * res[{u, c}];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i;
        inv[i] = fact[i].pow();
    }

    cin >> n >> k;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == 1) {
        cout << (mint) n * (n - 1) * mint(2).pow() << "\n";
        exit(0);
    }

    dfs_sub(1);
    dfs_ways(1);
    dfs_pull(1);
    dfs_push(1);

    cout << ans * mint(2).pow() << "\n";
}
#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;

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

    mint inv = mint(n).pow();
    for (auto &i : a) {
        i *= inv;
    }
    reverse(a.begin() + 1, a.end());

    a.resize(m - 1);
    return a;
}

const int N = 250001;

vector<int> adj[N];
mint factorial[N];

void dfs(int u) {
    for (auto c : adj[u]) {
        adj[c].erase(find(adj[c].begin(), adj[c].end(), u));
        dfs(c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial[0] = 1;
    for (int i = 1; i < N; ++i) {
        factorial[i] = i * factorial[i - 1];
    }

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    vector<vector<mint>> polynomials;
    for (int i = 1; i <= n; ++i) {
        polynomials.push_back(vector<mint>{1, adj[i].size()});
    }

    while (polynomials.size() > 1) {
        vector<vector<mint>> temp;
        for (int i = 0; i < (int) polynomials.size(); i += 2) {
            if (i + 1 < (int) polynomials.size()) {
                temp.push_back(mul(polynomials[i], polynomials[i + 1]));
            } else {
                temp.push_back(polynomials[i]);
            }
        }
        swap(polynomials, temp);
    }

    mint ans = 0;
    vector<mint> ways = polynomials[0];
    for (int i = 0; i < (int) ways.size(); ++i) {
        if (i % 2 == 0) {
            ans += factorial[n - i] * ways[i];
        } else {
            ans -= factorial[n - i] * ways[i];
        }
    }

    cout << ans << "\n";
}
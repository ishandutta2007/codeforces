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

const int N = 300001, LOG_N = 20;

int nxt[N];

int par[N][LOG_N], suffix[N];
mint hash_code[N][LOG_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    int balance = 0;
    map<int, int> prv;
    for (int i = 0; i < n; ++i) {
        nxt[i] = -1;

        prv[balance] = i;
        balance += (s[i] == '(') ? 1 : -1;
        if (prv.count(balance) > 0 && (prv.count(balance - 1) == 0 || prv[balance - 1] < prv[balance])) {
            nxt[prv[balance]] = i + 1;
        }
    }

    mint base = 3 /* random between 3 and M - 1 */;

    suffix[n] = n;
    fill(par[n], par[n] + LOG_N, n);

    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = i;
        par[i][0] = suffix[i + 1];
        hash_code[i][0] = (s[i] == '(') ? 1 : 2;

        mint shift = base;
        for (int j = 1; j < LOG_N; ++j) {
            int ancestor = par[i][j - 1];
            par[i][j] = par[ancestor][j - 1];
            hash_code[i][j] = hash_code[i][j - 1] + hash_code[ancestor][j - 1] * shift;
            shift *= shift;
        }

        if (nxt[i] != -1) {
            int u = i, v = suffix[nxt[i]];
            for (int j = LOG_N - 1; j >= 0; --j) {
                if (hash_code[u][j] == hash_code[v][j]) {
                    u = par[u][j], v = par[v][j];
                }
            }

            if (s[v] < s[u]) {
                suffix[i] = suffix[nxt[i]];
            }
        }
    }

    int u = 0;
    while (u < n) {
        cout << s[u];
        u = par[u][0];
    }

    cout << "\n";
}
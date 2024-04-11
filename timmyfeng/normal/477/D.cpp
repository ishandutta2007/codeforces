#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {
    modint() : n(0) {}
    template <class T> modint(T n) { n %= M; if (n < 0) n += M; this->n = n; }

    modint & operator+=(const modint &r) { n += r.n; if (n >= M) n -= M; return *this; }
    modint & operator-=(const modint &r) { n -= r.n; if (n < 0) n += M; return *this; }
    modint & operator*=(const modint &r) { n = (int) ((long long) n * r.n % M); return *this; }

    modint & operator--() { if (--n == -1) n = M - 1; return *this; }
    modint & operator++() { if (++n == M) n = 0; return *this; }
    modint operator--(int) { modint t = *this; --*this; return t; }
    modint operator++(int) { modint t = *this; ++*this; return t; }

    modint operator-() const { return 0 - *this; }
    modint operator+() const { return *this; }

    modint pow(long long k = M - 2) const {
        modint f = 1, p = *this;
        while (k > 0) {
            if (k % 2 == 1) f *= p;
            p *= p, k /= 2;
        }
        return f;
    }

    int mod() const { return M; }

    friend modint operator+(modint l, const modint &r) { return l += r; }
    friend modint operator-(modint l, const modint &r) { return l -= r; }
    friend modint operator*(modint l, const modint &r) { return l *= r; }
    
    friend bool operator==(const modint &l, const modint &r) { return l.n == r.n; }
    friend bool operator!=(const modint &l, const modint &r) { return l.n != r.n; }

    friend ostream & operator<<(ostream &out, const modint &r) { return out << r.n; }

    int n;
};

using mint = modint<(int) (1e9 + 7)>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x; cin >> x;
    int n = x.size();

    vector lcp(n + 1, vector<short>(n + 1));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            lcp[i][j] = (x[i] == x[j]) ? lcp[i + 1][j + 1] + 1 : 0;
        }
    }

    vector best(n + 1, vector<int>(n + 1, INT_MAX));
    vector ways(n + 1, vector<mint>(n + 1, 0));

    ways[0][1] = 1, best[0][1] = 1;

    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            if (best[l][r] == INT_MAX) continue;

            ways[l][r + 1] += ways[l][r];
            best[l][r + 1] = min(best[l][r + 1], best[l][r]);

            if (x[r] == '1') {
                int jump = r + (r - l);
                if (jump <= n && lcp[l][r] < r - l && x[l + lcp[l][r]] > x[r + lcp[l][r]]) ++jump;
                if (jump <= n) {
                    ways[r][jump] += ways[l][r];
                    best[r][jump] = min(best[r][jump], best[l][r] + 1);
                }
            }
        }
    }

    mint answer_ways = 0;
    for (int i = 0; i < n; ++i) {
        answer_ways += ways[i][n];
    }

    int answer_best = INT_MAX;
    mint suffix_value = 0, power2 = 1;
    for (int i = 1; i <= n; ++i) {
        if (x[n - i] == '1') suffix_value += power2;
        power2 *= 2;

        if (best[n - i][n] < INT_MAX) {
            if (i <= 16) answer_best = min(answer_best, stoi(x.substr(n - i), nullptr, 2) + best[n - i][n]);
            else if (answer_best == INT_MAX) answer_best = (suffix_value + best[n - i][n]).n;
        }
    }

    cout << answer_ways << "\n" << answer_best << "\n";
}
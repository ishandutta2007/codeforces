#include <bits/stdc++.h>
using namespace std;

const int N = 8, K = 5, M = 998244353;

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

string dict[N];
int key[N][K];

vector<vector<mint>> mul(vector<vector<mint>> &a, vector<vector<mint>> &b) {
    int n = a.size();
    vector<vector<mint>> c(n, vector<mint>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][k] += a[j][k] * b[i][j];
            }
        }
    }
    return c;
}

vector<mint> mul(vector<vector<mint>> &a, vector<mint> &b) {
    int n = a.size();
    vector<mint> c(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i] += a[i][j] * b[j];
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> dict[i];
    }

    int s = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < (int) dict[i].size(); ++j) {
            key[i][j] = s++;
        }
    }

    vector<vector<mint>> matrix = vector<vector<mint>>(s * K, vector<mint>(s * K));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = dict[i].size(), y = dict[j].size();
            if (dict[i].substr(0, min(x, y)) == dict[j].substr(0, min(x, y))) {
                if (x < y) {
                    ++matrix[(x - 1) * s + key[j][y - x]][0];
                } else {
                    ++matrix[(y - 1) * s + key[i][x - y]][0];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < (int) dict[i].size(); ++j) {
            for (int k = 0; k < n; ++k) {
                int l = dict[k].size();
                if (dict[i].substr(dict[i].size() - j, min(j, l)) == dict[k].substr(0, min(j, l))) {
                    if (j < l) {
                        ++matrix[(j - 1) * s + key[k][l - j]][key[i][j]];
                    } else {
                        ++matrix[(l - 1) * s + key[i][j - l]][key[i][j]];
                    }
                }
            }
        }
    }

    for (int i = 0; i < K - 1; ++i) {
        for (int j = 0; j < s; ++j) {
            ++matrix[i * s + j][(i + 1) * s + j];
        }
    }

    vector<mint> ans(s * K);
    ans[0] = 1;

    for (int i = 1; i <= m; i *= 2) {
        if ((m & i) > 0) {
            ans = mul(matrix, ans);
        }
        matrix = mul(matrix, matrix);
    }

    cout << ans[0] << "\n";
}
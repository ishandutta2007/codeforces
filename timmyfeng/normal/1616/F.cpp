#include <bits/stdc++.h>
using namespace std;

const int M = 3;

struct mint {
    int x;

    mint() : x(0) {}

    template <class T> mint(T value) : x(value % M) { if (x < 0) x += M; }

    mint & operator+=(const mint &oth) { x += oth.x; if (x >= M) x -= M; return *this; }

    mint & operator-=(const mint &oth) { x -= oth.x; if (x < 0) x += M; return *this; }

    mint & operator*=(const mint &oth) { x = x * oth.x; while (x >= M) x -= M; return *this; }

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<mint>> matrix;
        vector<vector<int>> index(n, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w; --u, --v;

            if (w > -1) {
                matrix.emplace_back(m + 1);
                matrix.back()[i] = 1;
                matrix.back()[m] = w - 1;
            }

            index[u][v] = index[v][u] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (index[i][j] > -1 && index[j][k] > -1 && index[i][k] > -1) {
                        matrix.emplace_back(m + 1);
                        matrix.back()[index[i][j]] = 1;
                        matrix.back()[index[j][k]] = 1;
                        matrix.back()[index[i][k]] = 1;
                    }
                }
            }
        }

        int ptr = 0;
        for (int i = 0; i < m && ptr < ssize(matrix); ++i) {
            for (int j = ptr; j < ssize(matrix); ++j) {
                if (matrix[j][i] != 0) {
                    if (j != ptr) swap(matrix[ptr], matrix[j]);
                    break;
                }
            }

            if (matrix[ptr][i] == 0) continue;

            mint coeff = matrix[ptr][i].pow();
            for (int k = i; k < m + 1; ++k) {
                matrix[ptr][k] *= coeff;
            }

            for (int j = ptr + 1; j < ssize(matrix); ++j) {
                for (int k = m; k >= i; --k) {
                    matrix[j][k] -= matrix[j][i] * matrix[ptr][k];
                }
            }

            ++ptr;
        }

        bool exists = true;
        for (int i = ptr; i < ssize(matrix); ++i) {
            exists &= matrix[i][m] == 0;
        }
        if (!exists) {
            cout << -1 << "\n";
            continue;
        }

        vector<mint> ans(m);
        for (int i = ptr - 1; i >= 0; --i) {
            int j = ranges::find(matrix[i], 1) - matrix[i].begin();
            ans[j] = matrix[i][m];
            for (int k = j + 1; k < m; ++k) {
                ans[j] -= matrix[i][k] * ans[k];
            }
        }

        for (auto i : ans) cout << i.x + 1 << " ";
        cout << "\n";
    }
}
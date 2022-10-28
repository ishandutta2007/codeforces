#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

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

const int N = 101;

map<int, int> levels;
vector<int> adj[N];
mint ways[N][N];

void dfs(int u, int d, int p = -1) {
    ++levels[d];
    for (auto c : adj[u]) {
        if (c != p) {
            dfs(c, d + 1, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        fill(adj, adj + n, vector<int>());

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;

            --u, --v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (k <= 2) {
            cout << n * (n - 1) / 2 << "\n";
            continue;
        }


        mint ans = 0;

        for (int u = 0; u < n; ++u) {
            for (int i = 0; i <= k; ++i) {
                for (int j = 0; j < n; ++j) {
                    ways[i][j] = (i == 0);
                }
            }

            for (auto c : adj[u]) {
                levels.clear();

                dfs(c, 1, u);

                for (auto [depth, width] : levels) {
                    for (int i = k - 1; i >= 0; --i) {
                        ways[i + 1][depth] += ways[i][depth] * width;
                    }
                }
            }

            ans = accumulate(ways[k], ways[k] + n, ans);
        }

        cout << ans << "\n";
    }
}
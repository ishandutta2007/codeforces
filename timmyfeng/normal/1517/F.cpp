#include <bits/stdc++.h>
using namespace std;

const int N = 301, M = 998244353;

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

vector<mint> edge[N], center[N];
vector<int> adj[N];
int sub[N], k;

void dfs(int u, int p = 0) {
    center[u] = {1};
    edge[u] = {0};
    sub[u] = 1;

    for (auto c : adj[u]) {
        if (c != p) {
            dfs(c, u);

            vector<mint> new_edge(sub[u] + sub[c]);
            vector<mint> new_center(sub[u] + sub[c]);

            for (int i = 0; i < sub[u]; ++i) {
                for (int j = 0; j < sub[c]; ++j) {
                    new_edge[min(i, j + 1)] += edge[u][i] * edge[c][j];
                    if (i + j < k) {
                        new_edge[j + 1] += center[u][i] * edge[c][j];
                        new_edge[i] += edge[u][i] * center[c][j];
                    } else {
                        new_center[i] += center[u][i] * edge[c][j];
                        new_center[j + 1] += edge[u][i] * center[c][j];
                    }
                    new_center[max(i, j + 1)] += center[u][i] * center[c][j];
                }
            }

            sub[u] += sub[c];
            swap(edge[u], new_edge);
            swap(center[u], new_center);
        }
    }

    for (int i = 0; i < sub[u]; ++i) {
        edge[u][0] += edge[u][i];
        (i <= k ? edge[u][0] : center[u][i]) += center[u][i];

        if (i > k) {
            center[u][0] += edge[u][i];
            edge[u][i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    mint ans = -1;
    for (k = 1; k <= n; ++k) {
        dfs(1);
        ans += accumulate(center[1].begin(), center[1].end(), mint());
    }

    ans *= mint(2).pow().pow(n);

    cout << ans << "\n";
}
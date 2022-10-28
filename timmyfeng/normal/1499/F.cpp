#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
struct mint {
    int value;
    mint() : value(0) {}
    template <class T> mint(T x) : value(x % M) { if (value < 0) value += M; }
    mint & operator-=(mint oth) { value -= oth.value; if (value < 0)  value += M; return *this; }
    mint & operator+=(mint oth) { value += oth.value; if (value >= M) value -= M; return *this; }
    mint & operator*=(mint oth) { value = (long long) value * oth.value % M; return *this; }
    mint & operator--() { if (--value == -1) value = M - 1; return *this; }
    mint & operator++() { if (++value == M) value = 0; return *this; }
    mint operator--(int) { mint temp = *this; --*this; return temp; }
    mint operator++(int) { mint temp = *this; ++*this; return temp; }
    mint operator-() const { return mint() - *this; }
    mint operator+() const { return *this; }
    mint pow(long long e = M - 2) const {
        mint res = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                res *= b;
            }
            b *= b;
            e /= 2;
        }
        return res;
    }
    friend mint operator-(mint a, mint b) { return a -= b; }
    friend mint operator+(mint a, mint b) { return a += b; }
    friend mint operator*(mint a, mint b) { return a *= b; }
    friend bool operator==(mint a, mint b) { return a.value == b.value; }
    friend bool operator!=(mint a, mint b) { return a.value != b.value; }
    friend ostream & operator<<(ostream &out, mint a) { out << a.value; return out; }
};

const int N = 5000 + 1;

vector<int> adj[N];
int n, k;

vector<mint> dfs(int u, int p = 0) {
    vector<mint> ways = {1};

    for (auto c : adj[u]) {
        if (c != p) {
            auto child_ways = dfs(c, u);
            vector<mint> new_ways(ways.size() + child_ways.size() - 1);
            for (int i = 0; i < (int) child_ways.size(); ++i) {
                for (int j = 0; j < (int) ways.size(); ++j) {
                    if (i + j <= k) {
                        new_ways[max(i, j)] += child_ways[i] * ways[j];
                    }
                }
            }
            ways = new_ways;
        }
    }

    mint sum = 0;
    for (int i = 0; i < (int) ways.size() && i <= k; ++i) {
        sum += ways[i];
    }
    ways.insert(ways.begin(), sum);

    return ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(1)[0] << "\n";
}
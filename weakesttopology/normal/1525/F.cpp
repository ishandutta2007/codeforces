#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

struct Kuhn {
    int N, M;
    vector<vector<int>> E;
    vector<int> matchA, matchB;
    vector<bool> vis;
    Kuhn(int N, int M) : N(N), M(M), E(N), matchA(N, -1), matchB(M, -1), vis(N) {}
    void add_edge(int u, int v) {
        E[u].push_back(v);
    }
    bool augment(int u) {
        vis[u] = true;
        for (auto v : E[u]) {
            int w = matchB[v];
            if (w == -1 || (not vis[w] && augment(w))) {
                matchA[u] = v, matchB[v] = u;
                return true;
            }
        }
        return false;
    }
    int mx = 0;
    int maximum_matching() {
        while (true) {
            bool converged = true;
            fill(all(vis), false);
            for (int u = 0; u < N; ++u) {
                if (not vis[u] && matchA[u] == -1 && augment(u)) {
                    converged = false;
                    ++mx;
                }
            }
            if (converged) break;
        }
        return mx;
    }
    vector<int> left_cover() {
        vector<int> U;
        for (int u = 0; u < N; ++u) {
            if (not vis[u]) U.push_back(u);
        }
        return U;
    }
    vector<int> right_cover() {
        vector<int> V;
        for (int v = 0; v < M; ++v) {
            int u = matchB[v];
            if (u != -1 && vis[u]) V.push_back(v);
        }
        return V;
    }
};

template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }
template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
 
template<typename T>
struct Recovery {
    struct Node {
        T value;
        Node* prev;
        Node(T value, Node* prev) : value(value), prev(prev) { }
    };
    deque<Node> states;
    Node* create(T value, Node* prev) {
        return &states.emplace_back(value, prev);
    } 
    vector<T> recover(Node* last) {
        vector<T> res;
        while (last != nullptr) {
            res.push_back(last->value);
            last = last->prev;
        }
        reverse(all(res));
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    Kuhn kuhn(n, n);
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        kuhn.add_edge(u, v);
    }

    int C = n - kuhn.maximum_matching();
    auto left = kuhn.left_cover(), right = kuhn.right_cover();
    vector<int> V;
    for (auto u : left) V.push_back(u + 1);
    for (auto u : right) V.push_back(-(u + 1));
    debug(C);

    vector<ll> x(k), y(k);
    for (int j = 0; j < k; ++j) cin >> x[j] >> y[j];
    auto f = [&](int j, int t) { return max(0LL, x[j] - t * y[j]); };

    if (k < C) {
        debug("do nothing");
        cout << k << endl;
        for (int j = 0; j < k; ++j) cout << 0 << endl;
        exit(0);
    }

    Recovery<ll> rec;
    vector<ll> dp(n + 1, -LINF), dpnxt(n + 1, -LINF);
    vector<Recovery<ll>::Node*> last(n + 1, nullptr), lastnxt(n + 1, nullptr);
    dp[0] = 0;

    for (int j = 0; j < k; ++j) {
        for (int x = 0; x <= n; ++x) {
            for (int y = 0; x + y <= n; ++y) {
                if (x + y + C > j + 1 && chmax(dpnxt[x + y], dp[x] + f(j, y))) {
                    lastnxt[x + y] = rec.create(y, last[x]);
                }
            }
        }
        fill(all(dp), -LINF), fill(all(last), nullptr);
        swap(dp, dpnxt), swap(last, lastnxt);
    }

    auto ops = rec.recover(last[k - C + 1]);
    int a = accumulate(all(ops), 0) + k;
    cout << a << endl;

    int ptr = 0;
    ll tot = 0;
    for (int j = 0; j < k; ++j) {
        tot += f(j, ops[j]);
        for (int i = 0; i < ops[j]; ++i) {
            cout << V[ptr++] << " ";
        }
        cout << 0 << " ";
    }
    cout << endl;

    debug(tot);

    exit(0);
}
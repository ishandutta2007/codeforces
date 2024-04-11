#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10;
const int inf = 1e5 + 10;

template <typename T> class Dinic {
    private:
        int n, s, t, cnt, level[maxn];
        T w[maxn][maxn];
        bool bfs() {
            memset(level, -1, sizeof(level));
            queue<int> que; que.push(s);
            level[s] = 0;
            while (que.size()) {
                int tmp = que.front(); que.pop();
                for (int i = 0; i < n; ++i) if (w[tmp][i] > 0) {
                    if (level[i] == -1) {
                        level[i] = level[tmp] + 1;
                        que.push(i);
                    }
                }
            }
            return level[t] != -1;
        }
        T flow(int now, T low) {
            T res = 0;
            if (now == t) return low;
            for (int i = 0; i < n && res < low; ++i) if (w[now][i] > 0) {
                if (level[i] == level[now] + 1) {
                    T tmp = flow(i, min(w[now][i], low - res));
                    w[now][i] -= tmp; w[i][now] += tmp;
                    res += tmp;
                }
            }
            if (!res) level[now] = -1;
            return res;
        }
    public:
        Dinic(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
            memset(w, 0, sizeof(w));
        }
        void add_edge(int a, int b, T flow) {
            w[a][b] = flow;
        }
        T maxflow() {
            long long ans = 0;
            while (bfs()) ans += flow(s, inf);
            return ans;
        }
        vector<vector<T>> get_w() {
            vector<vector<T>> ret;
            for (int i = 0; i < n; ++i) {
                ret.push_back(vector<T>());
                for (int j = 0; j < n; ++j) ret[i].push_back(w[i][j]);
            }
            return ret;
        }
};

int a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], sum1 += a[i];
    for (int i = 0; i < n; ++i) cin >> b[i], sum2 += b[i];
    if (sum1 != sum2) return cout << "NO" << endl, 0;
    int s = 2 * n, t = 2 * n + 1;
    Dinic<int> dinic(2 * n + 2, s, t);
    for (int i = 0; i < n; ++i) dinic.add_edge(s, i, a[i]);
    for (int i = 0; i < n; ++i) dinic.add_edge(i + n, t, b[i]);
    for (int i = 0; i < n; ++i) dinic.add_edge(i, i + n, inf); // dinic.add_edge(i + n, i, inf);
    while (m--) {
        int a, b; cin >> a >> b; --a; --b;
        dinic.add_edge(a, b + n, inf); // dinic.add_edge(b + n, a, inf);
        dinic.add_edge(b, a + n, inf); // dinic.add_edge(a + n, b, inf);
    }
    int flow = dinic.maxflow();
    if (flow != sum1) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    vector<vector<int>> w = dinic.get_w();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << (w[i][j + n] == 0 ? 0 : inf - w[i][j + n]) << ' ';
        cout << endl;
    }
    return 0;
}
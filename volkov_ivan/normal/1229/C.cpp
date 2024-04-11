#include <iostream>
#include <vector>
#include <cstring>
#define int long long

using namespace std;

const int MAX_N = 1e5 + 7;
vector <pair <int, int>> edges;
vector <int> in[MAX_N];
int cnt_in[MAX_N], cnt_out[MAX_N];
int ans = 0;

void update(int v) {
    ans -= cnt_in[v] * cnt_out[v];
    for (int u : in[v]) {
        if (edges[u].second == v) {
            swap(edges[u].first, edges[u].second);
            int other = edges[u].second;
            ans -= cnt_in[other] * cnt_out[other];
            cnt_in[other]++;
            cnt_out[other]--;
            cnt_out[v]++;
            cnt_in[v]--;
            ans += cnt_in[other] * cnt_out[other];
            in[other].push_back(u);
        }
    }
    in[v].clear();
    ans += cnt_in[v] * cnt_out[v];
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    memset(cnt_in, 0, sizeof(cnt_in));
    memset(cnt_out, 0, sizeof(cnt_out));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        edges.push_back({a, b});
        in[b].push_back(i);
        cnt_out[a]++;
        cnt_in[b]++;
    }
    for (int i = 1; i <= n; i++) ans += cnt_in[i] * cnt_out[i];
    cout << ans << "\n";
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int v;
        cin >> v;
        update(v);
        cout << ans << "\n";
    }
    return 0;
}
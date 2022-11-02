#include <iostream>
#include <numeric>
#include <vector>
#include <map>

std::vector<int>
    dx{0, 0, -1, 1}, dy{-1, 1, 0, 0};
const std::string dirs = "LRUD";

std::vector<int> to, depth, ids, lens, gs;
int gid;

void dfs(int v, int d) {
    depth[v] = d;
    int u = to[v];

    if (depth[u] != -1) {
        if (ids[u] == -1) {
            ids[v] = 0;
            lens[v] = depth[v] + 1 - depth[u];
            gs[v] = gid++;

            return;
        }
    } else {
        dfs(u, d + 1);
    }

    ids[v] = ids[u] + 1;
    lens[v] = lens[u];
    gs[v] = gs[u];

    if (ids[v] == lens[v]) ids[v] = 0;
}

void solve() {
    int h, w;
    std::cin >> h >> w;

    int n = h * w;
    std::vector<int> cs(n);
    for (auto& c : cs) {
        char x;
        std::cin >> x;
        c = x - '0';
    }

    to.resize(n);
    for (int u = 0; u < n; ++u) {
        char dir;
        std::cin >> dir;

        for (int i = 0; i < 4; ++i) {
            if (dir != dirs[i]) continue;

            int v = u + dx[i] * w + dy[i];
            to[u] = v;
        }
    }

    depth.assign(n, -1);
    ids.assign(n, -1);
    lens.assign(n, -1);
    gs.assign(n, -1);
    gid = 0;

    for (int v = 0; v < n; ++v) {
        if (depth[v] == -1) dfs(v, 0);
    }

    std::map<std::pair<int, int>, int> mps;

    for (int v = 0; v < n; ++v) {
        auto p = std::make_pair(gs[v], ids[v]);
        if (!mps.count(p)) mps[p] = 0;

        if (cs[v] == 0) mps[p] = 1;
    }

    int m = mps.size();
    int b = 0;
    for (auto p : mps) b += p.second;

    std::cout << m << " " << b << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}
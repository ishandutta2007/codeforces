#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;

int par[ms], val[ms];

std::pair<int, int> getPar(int x) {
    int v = 0;
    while(par[x] >= 0) {
        v ^= val[x];
        x = par[x];
    }
    return std::pair<int, int>(x, v);
}

int getResult(int u, int v) {
    auto p0 = getPar(u), p1 = getPar(v);
    if(p0.first == p1.first) {
        return p0.second ^ p1.second;
    } else {
        return -1;
    }
}

bool makeUnion(int u, int v, int res) {
    auto p0 = getPar(u), p1 = getPar(v);
    if(p0.first == p1.first) {
        return res == (p0.second ^ p1.second);
    }
    u = p0.first, v = p1.first;
    res = res ^ p0.second ^ p1.second;
    if(par[u] > par[v]) {
        std::swap(u, v);
    }
    par[u] += par[v];
    par[v] = u;
    val[v] = res;
    return true;
}

std::vector<std::pair<int, int>> edges[ms];
int edgeVal[ms], in[ms], ori[ms][2];
std::vector<int> seq, times[ms];

void go(int on, int up) {
    in[on] = (int) seq.size();
    for(auto [to, id] : edges[on]) if(to != up) {
        times[id].push_back((int) seq.size());
        seq.push_back(id);
        go(to, on);
        times[id].push_back((int) seq.size());
        seq.push_back(id);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n, q;
        std::cin >> n >> q;
        for(int i = 0; i < n; i++) {
            edges[i].clear();
            times[i].clear();
        }
        seq.clear();
        for(int i = 0; i <= 2*n; i++) {
            par[i] = -1;
        }
        for(int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            ori[i][0] = u, ori[i][1] = v;
            u--;v--;
            edges[u].emplace_back(v, i);
            edges[v].emplace_back(u, i);
            std::cin >> edgeVal[i];
        }
        go(0, 0);
        // set up subtrees and edges
        for(int i = 1; i < n; i++) {
            int c = 0;
            int x = edgeVal[i];
            while(x > 0) {
                x -= x & -x;
                c ^= 1;
            }
            for(int j = 0; j+1 < (int) times[i].size(); j++) {
                int u = times[i][j], v = times[i][j+1];
                assert(makeUnion(u+1, v, 0) && makeUnion(u, v+1, 0));
            }
            if(x != -1) {
                assert(makeUnion(times[i][0], times[i][0]+1, c));
            }
        }
        bool good = true;
        while(q--) {
            int u, v, c;
            std::cin >> u >> v >> c;
            u--;v--;
            if(in[u] > in[v]) std::swap(u, v);
            good = good && makeUnion(in[u], in[v], c);
        }
        if(!good) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            for(int i = 1; i < n; i++) {
                int c = times[i][0];
                if(getResult(c, c+1) == -1) {
                    assert(makeUnion(c, c+1, 0));
                }
                if(edgeVal[i] == -1) {
                    edgeVal[i] = getResult(c, c+1);
                }
                std::cout << ori[i][0] << ' ' << ori[i][1] << ' ' << edgeVal[i] << '\n';
            }
        }
    }
}
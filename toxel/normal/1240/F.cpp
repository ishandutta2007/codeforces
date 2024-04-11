#include <bits/stdc++.h>

const int N = 10010;
using pii = std::pair <int, int>;

struct Edge{
    int v, color;
    bool vis;

    Edge():v(0), color(0){}
    Edge(int v, int color):v(v), color(color), vis(false){}
};

int ecnt = 0;
Edge edge[N];
std::vector <int> e[N], _e[N];

void addedge(int u, int v, int color, std::vector <int> *e){
    edge[ecnt] = Edge(v, color);
    e[u].push_back(ecnt ++);
    edge[ecnt] = Edge(u, color);
    e[v].push_back(ecnt ++);
}

pii check(int n, int k){
    for (int i = 1; i <= n; ++ i){
        std::vector <int> cnt(k);
        for (auto u : e[i]){
            ++ cnt[edge[u].color];
        }
        int min_pos = std::min_element(cnt.begin(), cnt.end()) - cnt.begin();
        int max_pos = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
        if (cnt[max_pos] - cnt[min_pos] > 2){
            return {min_pos, max_pos};
        }
    }
    return {-1, -1};
}

void check_done(int n, int k, int a, int b){
    for (int i = 1; i <= n; ++ i){
        std::vector <int> cnt(k);
        for (auto u : e[i]){
            ++ cnt[edge[u].color];
        }
        assert(std::abs(cnt[a] - cnt[b]) <= 2);
    }
}

std::vector <int> ans;

void dfs(int u){
    while (!_e[u].empty()){
        int v = _e[u].front();
        if (edge[v].vis){
            std::swap(_e[u].front(), _e[u].back());
            _e[u].pop_back();
            continue;
        }
        edge[v].vis = edge[v ^ 1].vis = true;
        dfs(edge[v].v);
        ans.push_back(v);
    }
}

int main(){
    srand((unsigned) time(NULL));
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
    }
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        addedge(u, v, rand() % k, e);
    }
    while (true){
        pii p = check(n, k);
        if (p.first == -1){
            break;
        }
        int a = p.first, b = p.second;
        for (int i = 1; i <= n + 1; ++ i){
            std::vector <int>().swap(_e[i]);
        }
        for (int i = 1; i <= n; ++ i){
            for (auto u : e[i]){
                if (edge[u].color == a || edge[u].color == b){
                    _e[i].push_back(u);
                }
            }
        }
        ecnt = m * 2;
        for (int i = 1; i <= n; ++ i){
            if (_e[i].size() % 2 == 1){
                addedge(n + 1, i, rand() % k, _e);
            }
        }
        for (int i = 1; i <= n + 1; ++ i){
            for (auto u : _e[i]){
                edge[u].vis = false;
            }
        }
        for (int i = n + 1; i >= 1; -- i){
            dfs(i);
            for (int j = 0, sz = ans.size(); j < sz; ++ j){
                edge[ans[j]].color = edge[ans[j] ^ 1].color = j % 2 == 0 ? a : b;
            }
            ans.clear();
        }
        check_done(n, k, a, b);
    }
    for (int i = 0; i < 2 * m; i += 2){
        printf("%d\n", edge[i].color + 1);
    }
    return 0;
}
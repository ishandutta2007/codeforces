#include <bits/stdc++.h>

const int N = 1000010;
const int MAXNODE = N;
using piii = std::tuple <int, int, int>;
const int DICSIZE = 26;

std::vector <int> e[MAXNODE];

struct AC_DFA{
    int go[MAXNODE][DICSIZE], fail[MAXNODE], sz, root;
    int id[MAXNODE], pos[MAXNODE];

    int newnode() {
        int ret = ++sz;
        memset(go[ret], 0, sizeof(go[ret]));
        fail[ret] = root; //f[ret] = 0;
        return ret;
    }

    void init() {
        root = sz = 0;
        root = newnode();
    }

    void insert(const char *str, int v) {
        int n = strlen(str), p = root;
        for (int i = 0; i < n; ++i) {
            int c = str[i] - 'a';
            if (!go[p][c]) go[p][c] = newnode();
            p = go[p][c];
        } //f[p] |= 1 << v;
        id[p] = v + 1;
        pos[v] = p;
    }

    void makefail() {
        std::queue<int> queue;
        queue.push(root);
        while (!queue.empty()) {
            int p = queue.front();
            if (p != root){
                e[fail[p]].emplace_back(p);
            }
            queue.pop();
            for (int i = 0; i < DICSIZE; ++i){
                if (go[p][i]) {
                    fail[go[p][i]] = fail[p] ? go[fail[p]][i] : root;
                    int q = go[p][i];
                    queue.push(q);
                }
                else{
                    go[p][i] = p == root ? root : go[fail[p]][i];
                }
            }
        }
    }
};

AC_DFA acDfa;

std::string str[N];
char input[N];
int value[N];
int sz[N], son[N], top[N], dep[N];
int max[N];
int ban[N];

void dfs(int u, int fa){
    value[u] = acDfa.id[u] ? acDfa.id[u] : value[fa];
    sz[u] = 1;
    for (auto v : e[u]){
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]){
            son[u] = v;
        }
    }
}

void gettop(int u, int tp){
    top[u] = tp;
    if (son[u]){
        gettop(son[u], tp);
    }
    for (auto v : e[u]){
        if (v == son[u]){
            continue;
        }
        gettop(v, v);
    }
}

int main() {
    acDfa.init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", input);
        str[i] = input;
    }
    for (int i = 0; i < n; ++ i){
        acDfa.insert(str[i].c_str(), i);
    }
    acDfa.makefail();
    int ans = 0;
    dep[acDfa.root] = 1;
    dfs(acDfa.root, 0);
    gettop(acDfa.root, acDfa.root);
    for (int i = 0; i < n; ++ i){
        int sz = str[i].size(), p = acDfa.root;
        std::vector <piii> vec;
        std::vector <int> vis;
        for (int j = 0; j < sz; ++ j) {
            int c = str[i][j] - 'a';
            p = acDfa.go[p][c];
            int node = j == sz - 1 ? acDfa.fail[p] : p;
            int x = value[node];
            if (x){
                vec.emplace_back(j - str[x - 1].size() + 1, j, x - 1);
                vis.emplace_back(acDfa.pos[x - 1]);
            }
        }
        for (auto u : vis){
            int x = acDfa.fail[u];
            while (x){
                max[top[x]] = std::max(max[top[x]], dep[x]);
                x = acDfa.fail[top[x]];
            }
        }
        std::sort(vec.begin(), vec.end(), [](const piii &p1, const piii &p2){
            auto [x1, y1, z1] = p1;
            auto [x2, y2, z2] = p2;
            if (x1 != x2) return x1 < x2;
            if (y1 != y2) return y1 > y2;
            return z1 < z2;
        });
        int maxi = -1;
        for (auto u : vec){
            if (maxi >= std::get <1> (u)){
                ban[std::get <2> (u)] = i + 1;
            }
            maxi = std::max(maxi, std::get <1>(u));
        }
        for (auto u : vec){
            int x = std::get <2>(u);
            if (ban[x] != i + 1){
                if (max[top[acDfa.pos[x]]] < dep[acDfa.pos[x]]){
                    ++ ans;
                    ban[x] = i + 1;
                }
            }
        }
        for (auto u : vis){
            int x = acDfa.fail[u];
            while (x){
                max[top[x]] = 0;
                x = acDfa.fail[top[x]];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
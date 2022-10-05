#include <bits/stdc++.h>

const int N = 200010;
const int BIT = 19;
using pii = std::pair <int, int>;

int dep[N], fa[N][BIT], dfn[N], dfncnt;
std::vector<int> e[N];
std::vector<pii> e1[N];
int v[N], s[N];
bool vis[N];
int col[N];

void dfs(int u, int f){
    dfn[u] = ++ dfncnt;
    fa[u][0] = f;
    for (int i = 1; i < BIT; ++ i){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto v : e[u]){
        if (v == f){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if (dep[u] < dep[v]){
        std::swap(u, v);
    }
    for (int i = 0; i < BIT; ++ i){
        if (dep[u] - dep[v] >> i & 1){
            u = fa[u][i];
        }
    }
    if (u == v) return u;
    for (int i = BIT - 1; i >= 0; -- i){
        if (fa[u][i] != fa[v][i]){
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}

void addedge(int u, int v){
    int w = std::abs(dep[u] - dep[v]);
    e1[u].emplace_back(v, w);
    e1[v].emplace_back(u, w);
}

struct Node{
    int x, y, id, u;

    int get_time()const{
        return (x + y - 1) / y;
    }

    bool operator <(const Node &n)const{
        int time1 = get_time();
        int time2 = n.get_time();
        return time1 == time2 ? id < n.id : time1 < time2;
    }

    bool operator >(const Node &n)const{
        return n < *this;
    }
};

void solve(){
    int k, m;
    scanf("%d%d", &k, &m);
    std::vector<int> virus(k), query(m);
    std::set <int> set;
    for (int i = 0; i < k; ++ i){
        scanf("%d", &virus[i]);
        set.insert(virus[i]);
        v[virus[i]] = i + 1;
        scanf("%d", &s[virus[i]]);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d", &query[i]);
        set.insert(query[i]);
    }
    std::vector<int> key;
    for (auto u : set){
        key.emplace_back(u);
    }
    std::sort(key.begin(), key.end(), [&](const int &p1, const int &p2){return dfn[p1] < dfn[p2];});
    std::vector<int> stack;
    std::vector<int> rollback = key;
    for (auto u : key){
        if (stack.empty()){
            stack = {u};
            continue;
        }
        int f = lca(stack.back(), u);
        rollback.emplace_back(f);
        while (true){
            int sz = stack.size();
            if (sz < 2){
                break;
            }
            if (dep[stack[sz - 2]] >= dep[f]){
                addedge(stack[sz - 2], stack[sz - 1]);
                stack.pop_back();
            }
            else{
                break;
            }
        }
        if (f != stack.back()){
            addedge(stack.back(), f);
            stack.pop_back();
            stack.emplace_back(f);
        }
        stack.emplace_back(u);
    }
    while (true){
        int sz = stack.size();
        if (sz < 2){
            break;
        }
        addedge(stack[sz - 2], stack[sz - 1]);
        stack.pop_back();
    }
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    for (auto u : virus){
        Node node = {0, s[u], v[u], u};
        pq.push(node);
    }
    while (!pq.empty()){
        Node node = pq.top();
        pq.pop();
        int u = node.u;
        if (vis[u]){
            continue;
        }
        col[u] = node.id;
        vis[u] = true;
        for (auto p : e1[node.u]){
            if (vis[p.first]){
                continue;
            }
            Node node1 = {node.x + p.second, node.y, node.id, p.first};
            pq.push(node1);
        }
    }
    for (int i = 0; i < m; ++ i){
        printf("%d%c", col[query[i]], " \n"[i == m - 1]);
    }
    for (auto u : rollback){
        e1[u].clear();
        vis[u] = false;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 16;

struct Graph{
    std::vector <int> e[N];
    int n;
    int dfn[N], dep[N], fa[N][MAX + 1], dfncnt;
    int cnt[N];
    int ans;
    bool iskp[N];

    void addedge(int u, int v){
        e[u].push_back(v);
        e[v].push_back(u);
    }

    void dfs(int u, int fa){
        dfn[u] = ++ dfncnt;
        dep[u] = dep[fa] + 1;
        this -> fa[u][0] = fa;
        for (int i = 1; i <= MAX; ++ i){
            this -> fa[u][i] = this -> fa[this -> fa[u][i - 1]][i - 1];
        }
        for (auto v : e[u]){
            if (v == fa){
                continue;
            }
            dfs(v, u);
        }
    }

    void init(){
        dfncnt = 0;
        dfs(1, 0);
    }
    
    int lca(int u, int v){
        if (dep[u] < dep[v]){
            std::swap(u, v);
        }
        int dif = dep[u] - dep[v];
        for (int i = MAX; i >= 0; -- i){
            if (dif & 1 << i){
                u = fa[u][i];
            }
        }
        if (u == v) return u;
        for (int i = MAX; i >= 0; -- i){
            if (fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    }

    int solve(){
        ans = 0;
        solve(1, 0);
        ans = std::max(-1, ans);
        return ans;
    }

private:
    void solve(int u, int fa){
        cnt[u] = iskp[u];
        for (auto v : e[u]){
            if (v == fa) continue;
            if (iskp[u] && iskp[v]){
                ans = INT_MIN;
                return;
            }
            solve(v, u);
            if (iskp[u] && cnt[v]){
                ++ ans;
            }
            else{
                cnt[u] += cnt[v];
            }
        }
        if (cnt[u] >= 2){
            ++ ans;
            cnt[u] = 0;
        }
    }
};

Graph graph, auxtree;
int key[N << 2], keycnt;
int rb[N << 2], rbcnt;
int kp[N];

void build(){
    key[keycnt ++] = 1;
    std::sort(key, key + keycnt, [&](int p1, int p2){return graph.dfn[p1] < graph.dfn[p2];});
    keycnt = std::unique(key, key + keycnt) - key;
    std::stack <int> stack;
    rbcnt = 0;
    stack.push(1);
    for (int i = 1; i < keycnt; ++ i){
        int u = stack.top(), v = graph.lca(u, key[i]);
        if (u == v){
            stack.push(key[i]);
            continue;
        }
        while (graph.dep[stack.top()] > graph.dep[v]){
            int w = stack.top();
            stack.pop();
            if (graph.dep[stack.top()] < graph.dep[v]){
                stack.push(v);
            }
            auxtree.addedge(stack.top(), w);
            rb[rbcnt ++] = stack.top();
            rb[rbcnt ++] = w;
        }
        stack.push(key[i]);
    }
    while (stack.size() >= 2){
        int w = stack.top();
        stack.pop();
        auxtree.addedge(stack.top(), w);
        rb[rbcnt ++] = stack.top();
        rb[rbcnt ++] = w;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    graph.n = n;
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        graph.addedge(u, v);
    }
    graph.init();
    int query;
    scanf("%d", &query);
    while (query --){
        for (int i = 0; i < rbcnt; ++ i){
            auxtree.e[rb[i]].clear();
        }
        keycnt = 0;
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; ++ i){
            scanf("%d", &kp[i]);
            key[keycnt ++] = kp[i];
            auxtree.iskp[kp[i]] = true;
            if (graph.fa[kp[i]][0]){
                key[keycnt ++] = graph.fa[kp[i]][0];
            }
        }
        build();
        printf("%d\n", auxtree.solve());
        for (int i = 0; i < k; ++ i){
            auxtree.iskp[kp[i]] = false;
        }
    }
    return 0;
}
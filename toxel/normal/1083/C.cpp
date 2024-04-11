#include<bits/stdc++.h>

const int N = 200010;
const int BIT = 18;
const int MAX = 1 << 18;

struct Seg{
    bool valid;
    int p1, p2;
};

Seg seg[MAX << 1];
int p[N], dep[N], dfn[N], deg[N], end[N], euler[N << 1];
int st[N << 2][BIT + 1], low[N << 2];
int dfn_cnt;
std::vector <int> e[N];

int getmin(int p1, int p2){
    return dep[p1] < dep[p2] ? p1 : p2;
}

void dfs(int u, int fa){
    dfn[u] = ++ dfn_cnt;
    dfn[u] = dfn_cnt;
    euler[dfn_cnt] = u;
    for (auto v : e[u]){
        dep[v] = dep[u] + 1;
        dfs(v, u);
        euler[++ dfn_cnt] = u;
    }
    end[u] = dfn_cnt;
}

int lca(int u, int v){
    int l = std::min(dfn[u], dfn[v]), r = std::max(end[u], end[v]);
    int d = low[r - l + 1];
    return getmin(st[l][d], st[r - (1 << d) + 1][d]);
}

Seg merge(Seg s1, Seg s2){
    if (!s1.valid || !s2.valid){
        return {false, 0, 0};
    }
    int a[] = {s1.p1, s1.p2, s2.p1, s2.p2};
    std::sort(a, a + 4, [&](const int &p1, const int &p2){return dfn[p1] < dfn[p2];});
    std::vector <int> stack = {a[0]};
    std::vector <int> roll_back;
    for (int i = 1; i < 4; ++ i){
        if (!a[i]) continue;
        int l = lca(stack.back(), a[i]);
        while ((int) stack.size() >= 2){
            int sz = stack.size();
            if (dep[stack[sz - 2]] >= dep[l]){
                ++ deg[stack[sz - 2]];
                ++ deg[stack.back()];
                roll_back.push_back(stack[sz - 2]);
                roll_back.push_back(stack.back());
                stack.pop_back();
            }
            else{
                break;
            }
        }
        if (stack.back() != l){
            ++ deg[l];
            ++ deg[stack.back()];
            roll_back.push_back(l);
            roll_back.push_back(stack.back());
            stack.pop_back();
            stack.push_back(l);
        }
        stack.push_back(a[i]);
    }
    while (stack.size() >= 2){
        int sz = stack.size();
        ++ deg[stack[sz - 2]];
        ++ deg[stack.back()];
        roll_back.push_back(stack[sz - 2]);
        roll_back.push_back(stack.back());
        stack.pop_back();
    }
    std::sort(roll_back.begin(), roll_back.end());
    roll_back.erase(std::unique(roll_back.begin(), roll_back.end()), roll_back.end());
    bool flag = true;
    for (auto u : roll_back){
        if (deg[u] >= 3){
            flag = false;
            break;
        }
    }
    Seg ret = {flag, 0, 0};
    for (auto u : roll_back){
        if (deg[u] < 2){
            (ret.p1 ? ret.p2 : ret.p1) = u;
        }
    }
    for (auto u : roll_back){
        deg[u] = 0;
    }
    return ret;
}

void add(int sit, int value){
    seg[sit += MAX] = {true, value, 0};
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = merge(seg[sit << 1], seg[sit << 1 | 1]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 2, x; i <= n; ++ i){
        scanf("%d", &x);
        e[x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 2; i < N << 2; ++ i){
        low[i] = low[i >> 1] + 1;
    }
    for (int i = 1; i <= dfn_cnt; ++ i){
        st[i][0] = euler[i];
    }
    dep[0] = dfn[0] = INT_MAX;
    for (int j = 1; j <= BIT; ++ j){
        for (int i = 1; i <= dfn_cnt; ++ i){
            st[i][j] = getmin(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= n; ++ i){
        add(p[i], i);
    }
    int q;
    scanf("%d", &q);
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int u, v;
            scanf("%d%d", &u, &v);
            std::swap(p[u], p[v]);
            add(p[u], u);
            add(p[v], v);
            continue;
        }
        Seg now = {true, 0, 0};
        int sit = 1;
        for (int i = 0; i < BIT; ++ i){
            Seg tmp = merge(now, seg[sit << 1]);
            if (tmp.valid){
                sit = sit << 1 | 1;
                now = tmp;
            }
            else{
                sit = sit << 1;
            }
        }
        printf("%d\n", sit - MAX);
    }
    return 0;
}
#include <bits/stdc++.h>

const int N = 1000010;
const int MAX = 1 << 19;

int n;
std::vector<int> e[N];
int dfn[N], right[N], dfncnt, dep[N];
int seg[MAX << 1], lazy[MAX << 1];
int ans[N];
std::vector<int> even_vec[N];
int last[N], father[N], max[N];

void pull(int sit){
    seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
}

void update(int sit, int value){
    seg[sit] += value, lazy[sit] += value;
}

void push(int sit){
    if (!lazy[sit]){
        return;
    }
    update(sit << 1, lazy[sit]), update(sit << 1 | 1, lazy[sit]);
    lazy[sit] = 0;
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return;
    }
    if (ql <= l && qr >= r){
        update(sit, value);
        return;
    }
    push(sit);
    int mid = (l + r) / 2;
    add(sit << 1, l, mid, ql, qr, value);
    add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

void add(int ql, int qr, int value){
    add(1, 0, MAX - 1, ql, qr, value);
}

int query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return 0;
    }
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    push(sit);
    int mid = (l + r) / 2;
    return std::max(query(sit << 1, l, mid, ql, qr),
                    query(sit << 1 | 1, mid + 1, r, ql, qr));
}

int query(int ql, int qr){
    if (ql > qr){
        return 0;
    }
    return query(1, 0, MAX - 1, ql, qr);
}

void dfs(int u, int fa){
    dfn[u] = ++ dfncnt;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
    right[u] = dfncnt;
}

void solve(int u, int fa){
    father[u] = fa;
    std::vector<int> vec;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        vec.emplace_back(query(dfn[v], right[v]));
        add(1, n, 1);
        add(dfn[v], right[v], -2);
        solve(v, u);
        add(dfn[v], right[v], 2);
        add(1, n, -1);
    }
    std::sort(vec.begin(), vec.end());
    even_vec[u] = vec;
    if (!vec.empty()){
        max[u] = *std::max_element(vec.begin(), vec.end());
    }
    if (fa){
        last[u] = std::max(query(1, dfn[u] - 1), query(right[u] + 1, n));
        vec.emplace_back(last[u]);
    }
    std::sort(vec.begin(), vec.end());
    int sz = vec.size();
    for (int i = 0; i < sz; ++ i){
        int &v = ans[2 * vec[i]];
        v = std::max(v, sz - i);
        int &w = ans[2 * vec[i] - 1];
        w = std::max(w, sz - i);
    }
    for (int i = 0; i < sz - 1; ++ i){
        if (vec[i] != vec[i + 1]){
            int &v = ans[2 * vec[i] + 1];
            v = std::max(v, sz - i);
        }
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i){
        seg[dfn[i] + MAX] = dep[i];
    }
    for (int i = MAX - 1; i; -- i){
        pull(i);
    }
    solve(1, 0);
    for (int i = 1; i <= n; ++ i){
        auto vector = even_vec[i];
        if (vector.empty()){
            continue;
        }
        if (father[i]){
            vector.emplace_back(last[i]);
        }
        std::sort(vector.begin(), vector.end());
        int pos = -1, cnt = 0;
        for (auto u : e[i]){
            if (u == father[i]){
                continue;
            }
            if (vector.back() == max[u] + 1){
                pos = u;
                ++ cnt;
            }
        }
        if (cnt > 1){
            pos = -1;
        }
        std::map <int, int> map;
        int max_possible = 0;
        for (auto u : e[i]){
            if (u == father[i] || u == pos){
                continue;
            }
            int sz = even_vec[u].size();
            for (int j = 0; j < sz; ++ j){
                int &v = map[even_vec[u][j]];
                v = std::max(v, sz - j);
            }
            max_possible = std::max(max_possible, max[u]);
        }
        int cur = 0;
        for (auto it = map.rbegin(); it != map.rend(); it = std::next(it)){
            cur = std::max(cur, it -> second);
            it -> second = cur;
        }
        int sz = vector.size();
        for (int j = 0; j < sz; ++ j){
            if (vector[j] > max_possible){
                break;
            }
            int &u = ans[2 * vector[j]];
            int value = sz - j + map.lower_bound(vector[j]) -> second - 1;
            u = std::max(u, value);
        }
        for (const auto &p : map){
            if (p.first > max_possible){
                break;
            }
            int &u = ans[2 * p.first];
            int value = vector.end() - std::lower_bound(vector.begin(), vector.end(), p.first);
            value = p.second + value - 1;
            u = std::max(u, value);
        }
        if (pos != -1){
            vector.pop_back();
            auto update1 = [&](const std::vector<int> &vec1, const std::vector<int> &vec2){
                int sz = vec1.size();
                for (int i = 0; i < sz; ++ i){
                    int sit = vec2.end() - std::lower_bound(vec2.begin(), vec2.end(), vec1[i]);
                    if (sit == 0){
                        continue;
                    }
                    int &u = ans[2 * vec1[i]];
                    u = std::max(u, sz - i + sit);
                }
            };
            update1(vector, even_vec[pos]);
            update1(even_vec[pos], vector);
        }
    }
    for (int i = n; i >= 2; -- i){
        ans[i] = std::max(ans[i], ans[i + 2]);
    }
    ans[1] = 0;
    for (int i = 1; i <= n; ++ i){
        ans[1] = std::max(ans[1], int(e[i].size()) + 1);
    }
    for (int i = 1; i <= n; ++ i){
        ans[i] = std::max(ans[i], 1);
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
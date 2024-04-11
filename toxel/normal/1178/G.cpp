#include <bits/stdc++.h>

const int N = 200010;
const int BLOCK = 150;
using ll = long long;
using pii = std::pair <int, int>;
inline int blockid(int n){ return n / BLOCK; }
inline ll divide(ll a, ll b){ return a / b - (a % b && ((a > 0) ^ (b > 0)));}
inline ll divideup(ll a, ll b){return divide(a, b) + (a % b != 0);}

struct Line{
    ll k, b, left;

    explicit Line(ll k = 0, ll b = 0, ll left = 0):k(k), b(b), left(left){}
};

std::vector <int> e[N];
int a[N], b[N], p[N], c[N];
int lblock[N], rblock[N];
int dfn[N], right[N], dfncnt;
int max[N], offset[N];
std::vector <pii> order[N];
std::vector <Line> stack[N];
int cur[N];

void dfs(int u){
    dfn[u] = ++ dfncnt;
    for (auto v : e[u]){
        dfs(v);
    }
    right[u] = dfncnt;
}

void build(int id){
    int l = lblock[id], r = rblock[id];
    max[id] = INT_MIN;
    ll ans = 0;
    for (int i = l; i <= r; ++ i){
        a[i] += offset[id];
        if (a[i] < 0){
            max[id] = std::max(max[id], a[i]);
        }
        ans = std::max(ans, 1ll * std::abs(a[i]) * b[i]);
    }
    auto &vec = order[id];
    for (int i = 0; i < (int) vec.size(); ++ i){
        if (vec[i].first < 0){
            if (a[vec[i].second] >= 0) {
                vec[i].first = -vec[i].first;
                int j = i;
                while (j < (int) vec.size() - 1 && vec[j].first > vec[j + 1].first){
                    std::swap(vec[j], vec[j + 1]);
                    ++ j;
                }
                -- i;
            }
        }
        else{
            break;
        }
    }
    cur[id] = offset[id] = 0;
    stack[id].clear();
    for (auto u : order[id]){
        int pos = u.second;
        Line nl(u.first, 1ll * std::abs(a[pos]) * b[pos]);
        while (!stack[id].empty()){
            Line l = stack[id].back();
            if (l.k == nl.k){
                if (l.b < nl.b){
                    stack[id].pop_back();
                }
                else{
                    break;
                }
            }
            else{
                ll cross = divideup(l.b - nl.b, nl.k - l.k);
                if (cross <= l.left){
                    stack[id].pop_back();
                }
                else{
                    nl.left = cross;
                    stack[id].push_back(nl);
                    break;
                }
            }
        }
        if (stack[id].empty()){
            nl.left = LLONG_MIN;
            stack[id].push_back(nl);
        }
    }
}

int main(){
    int n, test;
    scanf("%d%d", &n, &test);
    for (int i = 2; i <= n; ++ i){
        scanf("%d", &p[i]);
        e[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    for (int i = 2; i <= n; ++ i){
        a[i] += a[p[i]];
        b[i] += b[p[i]];
    }
    for (int i = 1; i <= n; ++ i){
        b[i] = std::abs(b[i]);
    }
    for (int i = 0; i < N; ++ i){
        lblock[i] = std::max(1, i * BLOCK);
        rblock[i] = std::min(n, i * BLOCK + BLOCK - 1);
    }
    dfncnt = 0;
    dfs(1);
    for (int i = 1; i <= n; ++ i){
        c[dfn[i]] = a[i];
    }
    memcpy(a, c, sizeof(a));
    for (int i = 1; i <= n; ++ i){
        c[dfn[i]] = b[i];
    }
    memcpy(b, c, sizeof(b));
    for (int i = blockid(1); i <= blockid(n); ++ i){
        for (int j = lblock[i]; j <= rblock[i]; ++ j){
            order[i].emplace_back((a[j] > 0 ? 1 : -1) * b[j], j);
        }
        std::sort(order[i].begin(), order[i].end());
        build(i);
    }
    while (test --){
        int type, v;
        scanf("%d%d", &type, &v);
        int l = dfn[v], r = right[v];
        int lb = blockid(l), rb = blockid(r);
        if (type == 1){
            int x;
            scanf("%d", &x);
            if (lb == rb){
                for (int i = l; i <= r; ++ i){
                    a[i] += x;
                }
                build(lb);
            }
            else{
                for (int i = l; i <= rblock[lb]; ++ i){
                    a[i] += x;
                }
                for (int i = lblock[rb]; i <= r; ++ i){
                    a[i] += x;
                }
                build(lb), build(rb);
                for (int i = lb + 1; i < rb; ++ i){
                    offset[i] += x;
                    if (max[i] != INT_MIN && offset[i] + max[i] >= 0){
                        build(i);
                    }
                }
            }
        }
        else{
            ll ans = 0;
            if (lb == rb){
                for (int i = l; i <= r; ++ i){
                    ans = std::max(ans, 1ll * std::abs(a[i] + offset[lb]) * b[i]);
                }
            }
            else{
                for (int i = l; i <= rblock[lb]; ++ i){
                    ans = std::max(ans, 1ll * std::abs(a[i] + offset[lb]) * b[i]);
                }
                for (int i = lblock[rb]; i <= r; ++ i){
                    ans = std::max(ans, 1ll * std::abs(a[i] + offset[rb]) * b[i]);
                }
                for (int i = lb + 1; i < rb; ++ i){
                    while (cur[i] < (int) stack[i].size() - 1 && offset[i] >= stack[i][cur[i] + 1].left){
                        ++ cur[i];
                    }
                    ans = std::max(ans, stack[i][cur[i]].k * offset[i] + stack[i][cur[i]].b);
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
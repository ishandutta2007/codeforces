#include <bits/stdc++.h>

const int N = 100010;
const int BIT = 18;
using ll = long long;
using pii = std::pair <ll, ll>;

std::vector<pii> e[N];
ll dep[N];
int dep1[N], sz[N], son[N], fa[N][BIT];
int t[N], s[N];
std::vector<int> event[N];
ll min_explode = LLONG_MAX;
std::vector<pii> inter;
int begin[N];

struct Result{
    std::set <pii> set{};
    ll offset{};
};

void dfs(int u, int fa){
    ::fa[u][0] = fa;
    for (int i = 1; i < BIT; ++ i){
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    }
    sz[u] = event[u].size();
    for (auto p : e[u]){
        int v = p.first;
        dep[v] = dep[u] + p.second;
        dep1[v] = dep1[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]){
            son[u] = v;
        }
    }
}

int getson(int u, int v){
    int diff = dep1[v] - dep1[u] - 1;
    for (int i = 0; i < BIT; ++ i){
        if (diff >> i & 1){
            v = fa[v][i];
        }
    }
    return v;
}

Result explode(int u){
    Result result;
    if (son[u]){
        result = explode(son[u]);
        for (auto p : e[u]){
            if (p.first == son[u]){
                result.offset -= p.second;
            }
        }
    }
    std::vector<pii> to_insert;
    for (auto p : e[u]){
        int v = p.first;
        if (v == son[u]){
            continue;
        }
        Result r = explode(v);
        r.offset -= p.second;
        for (auto x : r.set){
            x.first += r.offset - result.offset;
            x.second = v;
            to_insert.emplace_back(x);
        }
    }
    std::sort(to_insert.begin(), to_insert.end());
    to_insert.erase(std::unique(to_insert.begin(), to_insert.end()), to_insert.end());
    int sz = to_insert.size();
    for (int i = 0; i < sz - 1; ++ i){
        if (to_insert[i].first == to_insert[i + 1].first){
            min_explode = std::min(min_explode, to_insert[i].first);
            to_insert.erase(to_insert.begin() + i, to_insert.end());
            break;
        }
    }
    for (int i = 0, j = 0; i < sz; i = j){
        ll value = to_insert[i].first;
        auto it = result.set.lower_bound({value, LLONG_MIN});
        ll next_value = it == result.set.end() ? LLONG_MAX : it -> first;
        if (next_value == value){
            min_explode = std::min(min_explode, value);
            break;
        }
        if (it != result.set.begin()){
            inter.emplace_back(std::prev(it) -> first + 1 + result.offset, value + result.offset);
        }
        while (j < sz && to_insert[j].first < next_value){
            ++ j;
        }
        for (int k = i; k < j - 1; ++ k){
            if (getson(u, to_insert[k].second) != getson(u, to_insert[k + 1].second)){
                inter.emplace_back(to_insert[k].first + 1 + result.offset, to_insert[k + 1].first + result.offset);
            }
        }
        for (int k = i; k < j; ++ k){
            result.set.insert(to_insert[k]);
        }
        if (next_value != LLONG_MAX){
            inter.emplace_back(to_insert[j - 1].first + 1 + result.offset, next_value + result.offset);
        }
    }
    if (!result.set.empty()){
        ll value = result.set.begin() -> first;
        int pos = getson(u, result.set.begin() -> second);
        if (pos != begin[u]){
            inter.emplace_back(1, value + result.offset);
        }
    }
    for (auto x : event[u]){
        ll value = t[x] + dep[u] - result.offset;
        auto it = result.set.lower_bound({value, LLONG_MIN});
        if (it != result.set.end() && it -> first == value){
            continue;
        }
        result.set.insert({value, u});
    }
    while (!result.set.empty()){
        auto it = std::prev(result.set.end());
        if (it -> first >= min_explode){
            result.set.erase(it);
        }
        else{
            break;
        }
    }
    return result;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++ i){
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        begin[u] = v;
        e[u].emplace_back(v, d);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &s[i], &t[i]);
        event[s[i]].emplace_back(i);
    }
    dfs(1, 0);
    explode(1);
    {
        std::vector<pii> real_inter;
        for (auto u : inter){
            if (u.second < min_explode){
                real_inter.emplace_back(u);
            }
        }
        inter = real_inter;
    }
    std::sort(inter.begin(), inter.end());
    int sz = inter.size();
    std::priority_queue<ll, std::vector<ll>, std::greater<>> pq;
    for (int i = 0, j = 0; i < sz; i = j){
        while (j < sz && inter[j].first == inter[i].first){
            pq.push(inter[j].second);
            ++ j;
        }
        for (ll x = inter[i].first; x < (j == sz ? LLONG_MAX : inter[j].first); ++ x){
            if (pq.empty()){
                break;
            }
            ll u = pq.top();
            pq.pop();
            if (x > u){
                min_explode = u;
                goto end;
            }
        }
        if (!pq.empty() && pq.top() < inter[j].first){
            min_explode = pq.top();
            break;
        }
    }
    end:
    int cnt = 0;
    for (auto u : inter){
        cnt += u.second < min_explode;
    }
    if (min_explode == LLONG_MAX){
        min_explode = -1;
    }
    printf("%lld %d\n", min_explode, cnt);
    return 0;
}
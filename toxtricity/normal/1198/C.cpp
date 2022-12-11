#include <bits/stdc++.h>

const int N = 500010;
typedef std::pair <int, int> pii;

std::set<pii> e[N];
std::vector <int> e1[N];
int u[N], v[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= 3 * n; ++ i){
        e[i].clear();
        e1[i].clear();
    }
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        if (u > v){
            std::swap(u, v);
        }
        ::u[i] = u, ::v[i] = v;
        e[v].insert({u, i + 1});
        e1[u].push_back(i + 1);
        e1[v].push_back(i + 1);
    }
    std::set <int> indSet, matching;
    for (int i = 1; i <= n; ++ i){
        indSet.insert(i);
    }
    for (int i = 1; i <= n; ++ i){
        for (auto v : e[i]){
            matching.insert(v.second);
        }
    }
    if (matching.empty()){
        puts("IndSet");
        for (auto u : indSet){
            printf("%d ", u);
        }
        puts("");
        return;
    }
    std::vector <int> ans;
    for (int i = 0; i < n; ++ i){
        int x = *(matching.begin());
        ans.push_back(x);
        int u = ::u[x - 1], v = ::v[x - 1];
        for (auto w : e1[u]){
            matching.erase(w);
        }
        for (auto w : e1[v]){
            matching.erase(w);
        }
        indSet.erase(u);
        indSet.erase(v);
        indSet.insert(n + 2 * i + 1);
        indSet.insert(n + 2 * i + 2);
        for (auto w : e[n + 2 * i + 1]){
            if (indSet.count(w.first)) {
                matching.insert(w.second);
            }
        }
        for (auto w : e[n + 2 * i + 2]){
            if (indSet.count(w.first)) {
                matching.insert(w.second);
            }
        }
        if (matching.empty()){
            puts("IndSet");
            for (auto u : indSet){
                printf("%d ", u);
            }
            puts("");
            return;
        }
    }
    puts("Matching");
    for (auto u : ans){
        printf("%d ", u);
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}
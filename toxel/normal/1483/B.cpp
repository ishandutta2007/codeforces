#include <bits/stdc++.h>

const int N = 100010;

int a[N];
int fa[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    fa[u] = v;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        fa[i] = i;
    }
    std::vector <int> deleted;
    for (int i = 1; i < n; ++ i){
        if (std::gcd(a[i], a[i + 1]) > 1){
            unite(i, i + 1);
        }
    }
    if (std::gcd(a[1], a[n]) > 1){
        if (find(1) == find(n)){
            puts("0");
            return;
        }
        unite(n, 1);
    }
    std::set <int> remain;
    for (int i = 1; i <= n; ++ i){
        remain.insert(i);
    }
    int cur = 1;
    auto get_next = [&](int pos){
        auto it = remain.upper_bound(pos);
        return it == remain.end() ? *(remain.begin()) : *it;
    };
    while (!remain.empty()){
        cur = find(cur);
        int nnext = get_next(cur);
        fa[nnext] = -1;
        deleted.emplace_back(nnext);
        remain.erase(nnext);
        if (remain.empty()){
            break;
        }
        int nnnext = get_next(nnext);
        if (std::gcd(a[cur], a[nnnext]) > 1){
            if (find(cur) == find(nnnext)){
                break;
            }
            unite(cur, nnnext);
        }
        cur = nnnext;
    }
    int sz = deleted.size();
    printf("%d", sz);
    for (auto u : deleted){
        printf(" %d", u);
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

const int N = 100010;
using pii = std::pair <int, int>;

int p[N], inv[N];
int cnt[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
        inv[p[i]] = i;
    }
    std::set <pii> set;
    std::set <int> empty;
    for (int i = 1; i <= n; ++ i){
        cnt[i] = 1;
        set.emplace(1, i);
        empty.emplace(i);
    }
    for (int i = 1; i <= n; ++ i){
        if (cnt[inv[i]] != std::prev(set.end()) -> first){
            puts("No");
            return;
        }
        auto u = empty.upper_bound(inv[i]);
        set.erase({cnt[inv[i]], inv[i]});
        if (u == empty.end()){
            empty.erase(inv[i]);
        }
        else{
            empty.erase(inv[i]);
            set.erase({cnt[*u], *u});
            cnt[*u] += cnt[inv[i]];
            set.emplace(cnt[*u], *u);
        }
    }
    puts("Yes");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
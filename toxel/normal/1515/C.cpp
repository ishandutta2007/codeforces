#include <bits/stdc++.h>

const int N = 100010;
using pii = std::pair <int, int>;

int h[N], ht[N];
int ans[N];

void solve(){
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i <= m; ++ i){
        ht[i] = 0;
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &h[i]);
    }
    std::priority_queue<pii, std::vector <pii>, std::greater <pii>> pq;
    for (int i = 1; i <= m; ++ i){
        pq.emplace(ht[i], i);
    }
    for (int i = 1; i <= n; ++ i){
        pii p = pq.top();
        pq.pop();
        ans[i] = p.second;
        ht[ans[i]] += h[i];
        pq.emplace(ht[ans[i]], ans[i]);
    }
    puts("YES");
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
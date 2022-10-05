#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int a[N], b[N];
bool vis[N];

void solve(){
    memset(vis, 0, sizeof(vis));
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector <int> stack;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        stack.push_back(a[i]);
    }
    std::reverse(stack.begin(), stack.end());
    int stack_sz = n;
    ll ans = 0;
    for (int i = 0; i < m; ++ i){
        scanf("%d", &b[i]);
        ans += 1;
        if (vis[b[i]]){
            -- stack_sz;
            continue;
        }
        ans += 2 * (stack_sz - int(stack.size()));
        while (stack.back() != b[i]){
            vis[stack.back()] = true;
            ans += 2;
            stack.pop_back();
        }
        stack.pop_back();
        -- stack_sz;
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
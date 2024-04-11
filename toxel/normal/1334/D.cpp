#include <bits/stdc++.h>

using ll = long long;

std::vector <int> ans;

void dfs(int n, ll l, ll r, int offset, int type){
    if (n == 2){
        if (l <= 1 && 1 <= r){
            ans.emplace_back(2 + offset);
        }
        if (type == 0){
            if (l <= 2 && 2 <= r){
                ans.emplace_back(1 + offset);
            }
        }
        return;
    }
    int cnt = 2 * n - 2;
    ll left = std::max(1ll, l), right = std::min(ll(cnt), r);
    for (ll i = left; i <= right; ++ i){
        if (i <= cnt - 2){
            if (i % 2 == 0){
                ans.emplace_back(1 + offset);
            }
            else{
                ans.emplace_back(i / 2 + 2 + offset);
            }
        }
        else if (i == cnt - 1){
            ans.emplace_back(n + offset);
        }
        else if (i == cnt){
            ans.emplace_back(2 + offset);
        }
    }
    dfs(n - 1, l - cnt, r - cnt, offset + 1, 1);
    if (type == 0){
        ll pos = 1ll * n * (n - 1);
        if (l <= pos && pos <= r){
            ans.emplace_back(1 + offset);
        }
    }
}

void solve(){
    ans.clear();
    int n;
    ll l, r;
    scanf("%d%lld%lld", &n, &l, &r);
    if (l == 1){
        ans.emplace_back(1);
        ++ l;
    }
    -- l, -- r;
    dfs(n, l, r, 0, 0);
    int sz = ans.size();
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
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

// 1 2 1 3 1 4 2 3 2 4 3 4 1
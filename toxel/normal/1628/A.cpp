//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

const int N = 200010;

int a[N];
bool vis[N];
int mex[N];

void solve(){
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
    }
    for (int i = 0; i < n + 5; ++ i){
        vis[i] = false;
    }
    int cur = 0;
    for (int i = n - 1; i >= 0; -- i){
        vis[a[i]] = true;
        while (vis[cur]){
            ++ cur;
        }
        mex[i] = cur;
    }
    std::vector <int> ans;
    for (int i = 0; i < n + 5; ++ i){
        vis[i] = false;
    }
    int pos = 0;
    while (pos < n){
        int target = mex[pos];
        ans.emplace_back(target);
        int j = pos;
        cur = 0;
        while (j < n && cur < target){
            vis[a[j]] = true;
            while (vis[cur]){
                ++ cur;
            }
            ++ j;
        }
        for (int k = pos; k < j; ++ k){
            vis[a[k]] = false;
        }
        pos = j == pos ? j + 1 : j;
    }
    int sz = ans.size();
    std::cout << sz << '\n';
    for (int i = 0; i < sz; ++ i){
        std::cout << ans[i] << " \n"[i == sz - 1];
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}
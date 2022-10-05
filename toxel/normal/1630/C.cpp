//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

const int N = 200010;

int a[N];

void solve(){
    int n;
    std::cin >> n;
    std::vector <int> min(n + 1, INT_MAX), max(n + 1, INT_MIN), cnt(n + 1, 0);
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
        min[a[i]] = std::min(min[a[i]], i);
        max[a[i]] = std::max(max[a[i]], i);
        ++ cnt[a[i]];
    }
    int ans = 0;
    std::vector <pii> vec;
    for (int i = 1; i <= n; ++ i){
        if (cnt[i] >= 2){
            ans += cnt[i] - 2;
        }
        if (cnt[i] > 0){
            vec.emplace_back(min[i], -max[i]);
        }
    }
    std::sort(vec.begin(), vec.end());
    int cur_max = -1;
    std::vector <pii> vec1;
    for (auto [l, r]: vec){
        r = -r;
        if (r <= cur_max){
            ans += l == r ? 1 : 2;
        }
        else{
            cur_max = r;
            if (l != r){
                vec1.emplace_back(l, r);
            }
        }
    }
    int sz = vec1.size();
    for (auto [l, r]: vec1){
        ans += 2;
    }
    int pre = -1, now = -1;
    for (auto [l, r]: vec1){
        if (l > now){
            if (pre != now){
                -- ans;
            }
            pre = now = r;
            ans -= 2;
        }
        else if (l > pre){
            -- ans;
            pre = now;
            now = std::max(now, r);
        }
        else if (r > now){
            now = r;
        }
    }
    if (pre != now){
        -- ans;
    }
    std::cout << ans << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    while (test --){
        solve();
    }
    return 0;
}
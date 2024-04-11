//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

const int N = 200010;

int a[N];

int check(std::vector <int> &cnt, int n, int mid, int k){
    int cur = 0;
    for (int i = 1; i <= mid + 1; ++ i){
        cur += cnt[i];
    }
    for (int i = mid + 1; i <= n; ++ i){
        if (cur - (n - cur) >= k){
            return i - mid;
        }
        if (i < n){
            cur -= cnt[i - mid];
            cur += cnt[i + 1];
        }
    }
    return -1;
}

void solve(){
    int n, k;
    std::cin >> n >> k;
    std::vector <int> cnt(n + 1);
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
        ++ cnt[a[i]];
    }
    int l = 0, r = n - 1;
    while (l < r){
        int mid = (l + r) / 2;
        if (check(cnt, n, mid, k) == -1){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    int left = check(cnt, n, l, k);
    int right = left + l;
    std::cout << left << ' ' << right << '\n';
    int cur = 0;
    int count = 0;
    int target = 1;
    for (int i = 0; i < n; ++ i){
        count += left <= a[i] && a[i] <= right ? 1 : -1;
        if ((target < k && count == target) || i == n - 1){
            std::cout << cur + 1 << ' ' << i + 1 << '\n';
            cur = i + 1;
            ++ target;
        }
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
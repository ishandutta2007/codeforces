#include <bits/stdc++.h>

const int N = 100010;

int a[N];
std::vector<int> vec[N];

int main(){
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    int left = INT_MIN, right = a[n - 1] + n;
    for (int i = 0; i < n; ++ i){
        left = std::max(left, a[i] - i);
    }
    std::vector<int> cnt(right - left + 1);
    for (int i = left, j = 0; i <= right; ++ i){
        while (j < n && a[j] <= i){
            ++ j;
        }
        cnt[i - left] = j;
    }
    std::vector<int> ban(right - left + 1);
    for (int i = left; i <= right; ++ i){
        vec[cnt[i - left] % p].emplace_back(i);
    }
    for (int i = 0; i < p; ++ i){
        for (auto u : vec[i]){
            int down = i, up = n / p * p + i;
            if (up >= n){
                up -= p;
            }
            int l = u - up, r = u - down;
            if (l < left){
                l += (left - l) / p * p;
            }
            while (l < left){
                l += p;
            }
            if (l <= r){
                if (l <= right){
                    ++ ban[l - left];
                }
                if (r + p <= right){
                    -- ban[r + p - left];
                }
            }
        }
    }
    for (int i = p; i < right - left + 1; ++ i){
        ban[i] += ban[i - p];
    }
    std::vector<int> ans;
    for (int i = left; i < a[n - 1]; ++ i){
        if (!ban[i - left]){
            ans.emplace_back(i);
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
    return 0;
}
#include <bits/stdc++.h>

const int N = 100010;
using pii = std::pair <int, int>;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::map <int, int> cnt1;
    for (int i = 0; i < n; ++ i){
        ++ cnt1[a[i]];
    }
    int max1 = 0;
    for (auto p : cnt1){
        max1 = std::max(max1, p.second);
    }
    if (max1 > (n + 1) / 2){
        puts("-1");
        return;
    }

    int pre = -1;
    std::vector<pii> vec;
    for (int i = 0; i < n - 1; ++ i){
        if (a[i] == a[i + 1]){
            vec.emplace_back(a[pre + 1], a[i]);
            pre = i;
        }
    }
    vec.emplace_back(a[pre + 1], a[n - 1]);
    int ans = int(vec.size()) - 1;
    std::map <int, int> cnt;
    for (auto p : vec){
        ++ cnt[p.first];
        ++ cnt[p.second];
    }
    int max = 0, sum = 0;
    for (auto p : cnt){
        max = std::max(p.second, max);
        sum += p.second;
    }
    if (max * 2 <= sum){
    }
    else{
        ans += (max * 2 - sum) / 2 - 1;
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
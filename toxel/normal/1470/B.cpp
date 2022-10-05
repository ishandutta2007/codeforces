#include <bits/stdc++.h>

const int N = 1000010;

int min[N];
std::vector<int> prime;
int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::map <int, int> map;
    for (int i = 0; i < n; ++ i){
        int x = a[i], prod = 1;
        while (x > 1){
            int tmp = min[x], cnt = 0;
            while (x % tmp == 0){
                x /= tmp;
                ++ cnt;
            }
            if (cnt & 1){
                prod *= tmp;
            }
        }
        ++ map[prod];
    }
    int ans0 = 0, ans1 = 0, cnt0 = 0;
    for (const auto &p : map){
        ans0 = std::max(ans0, p.second);
        if (p.second % 2 == 0 || p.first == 1){
            cnt0 += p.second;
        }
        else{
            ans1 = std::max(ans1, p.second);
        }
    }
    ans1 = std::max(ans1, cnt0);
    int test;
    scanf("%d", &test);
    while (test --){
        long long w;
        scanf("%lld", &w);
        printf("%d\n", w ? ans1 : ans0);
    }
}

int main(){
    for (int i = 2; i < N; ++i) {
        if (!min[i]) {
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime) {
            if (i * u >= N) {
                break;
            }
            min[i * u] = u;
            if (i % u == 0) {
                break;
            }
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

const int N = 1000010;
const int moder = 998244353;

int inv[N];
std::vector <int> vec[N];
int cnt[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        int k;
        scanf("%d", &k);
        while (k --){
            int x;
            scanf("%d", &x);
            vec[i].emplace_back(x);
            ++ cnt[x];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        int tot = 0;
        for (auto u : vec[i]){
            tot += cnt[u];
        }
        sum = (sum + 1ll * tot * inv[vec[i].size()]) % moder;
    }
    sum = 1ll * sum * inv[n] % moder * inv[n] % moder;
    printf("%d\n", sum);
}

int main(){
    inv[1] = 1;
    for (int i = 2; i < N; ++ i){
        inv[i] = moder - 1ll * (moder / i) * inv[moder % i] % moder;
    }
    solve();
    return 0;
}
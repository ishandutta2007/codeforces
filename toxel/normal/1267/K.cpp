#include <bits/stdc++.h>

using ll = long long;
const int N = 22;

int cnt[N];
ll comb[N][N];

ll solve(std::vector <int> digit){
    memset(cnt, 0, sizeof(cnt));
    for (auto u : digit){
        ++ cnt[u];
    }
    int used = 0, len = digit.size();
    ll ans = 1;
    for (int i = N - 1; i >= 0; -- i){
        if (!cnt[i]){
            continue;
        }
        int can_use = (i == 0 ? len : len + 1 - i) - used;
        if (can_use < cnt[i]){
            return 0;
        }
        ans *= comb[can_use][cnt[i]];
        used += cnt[i];
    }
    return ans;
}

void solve(){
    ll x;
    scanf("%lld", &x);
    std::vector <int> digit;
    for (int i = 2; x > 0; ++ i){
        digit.push_back(x % i);
        x /= i;
    }
    ll ans = solve(digit);
    bool flag = true;
    for (int i = 0; i < (int) digit.size(); ++ i){
        if (digit[i] == 0){
            digit.erase(digit.begin() + i);
            flag = false;
            break;
        }
    }
    if (!flag){
        ans -= solve(digit);
    }
    printf("%lld\n", ans - 1);
}

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}

/*
3
1
11
123456
 */
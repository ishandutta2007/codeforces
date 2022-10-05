#include <bits/stdc++.h>

std::mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
using ll = long long;

std::vector<std::string> ans;

ll add(ll x, ll y){
    char s[100];
    sprintf(s, "%lld + %lld\n", x, y);
    ans.emplace_back(s);
    return x + y;
}

ll xor_(ll x, ll y){
    char s[100];
    sprintf(s, "%lld ^ %lld\n", x, y);
    ans.emplace_back(s);
    return x ^ y;
}

int perform(int x){
    const int BIT = 60;
    std::vector<ll> a;
    a.emplace_back(x);
    for (int i = 0; i < 40; ++ i){
        ll x = a.back();
        a.emplace_back(add(x, x));
    }
    xor_(x, x);
    for (int i = 0; i < 100; ++ i){
        ll mask = rnd() & ((1ll << 40) - 1);
        ll sum = 0;
        for (int j = 0; j < 40; ++ j){
            if (mask >> j & 1){
                sum = add(sum, a[j]);
            }
        }
        a.emplace_back(sum);
    }
    int num = 0;
    int n = a.size();
    for (int i = BIT - 1; i >= 0; -- i){
        for (int j = num; j < n; ++ j){
            if (a[j] >> i & 1){
                std::swap(a[j], a[num]);
                break;
            }
        }
        if (!(a[num] >> i & 1)){
            continue;
        }
        for (int j = 0; j < n; ++ j){
            if (j == num){
                continue;
            }
            if (a[j] >> i & 1){
                a[j] = xor_(a[j], a[num]);
            }
        }
        ++ num;
    }
    return a[num - 1];
}

int main(){
    int x;
    scanf("%d", &x);
    perform(x);
    printf("%d\n", int(ans.size()));
    for (const auto &u : ans){
        printf("%s", u.c_str());
    }
    /*for (int i = 3; i <= 999999; i += 2){
        if (i % 10000 == 1){
            printf("%d\n", i);
            fflush(stdout);
        }
        int ans = perform(i);
        if (ans != 1){
            printf("%d %d\n", i, ans);
            fflush(stdout);
        }
    }*/
    return 0;
}
#include <bits/stdc++.h>

const int N = 30;
using ll = long long;

ll power[N];

struct Ans{
    ll a, b, c;
};

ll dfs(ll n, int level, int level1){
    if (level1 == 0){
        return 2 * power[level];
    }
    ll x = power[level1 - 1];
    if (n / x == 0){
        return dfs(n % x, level, level1 - 1);
    }
    if (n / x == 1){
        return dfs(n % x, level, level1 - 1) + x * 2;
    }
    if (n / x == 2){
        return dfs(n % x, level, level1 - 1) + x * 3;
    }
    return dfs(n % x, level, level1 - 1) + x * 1;
}

Ans calc(ll n, int level){
    ll a = power[level] + n;
    ll b = dfs(n, level, level);
    ll c = a ^ b;
    return {a, b, c};
}

Ans calc(ll n){
    for (int i = 0; i < N; ++ i){
        if (n < power[i]){
            return calc(n, i);
        }
        else{
            n -= power[i];
        }
    }
    return {0, 0, 0};
}

void solve(){
    ll n;
    scanf("%lld", &n);
    -- n;
    Ans ans = calc(n / 3);
    if (n % 3 == 0){
        printf("%lld\n", ans.a);
    }
    else if (n % 3 == 1){
        printf("%lld\n", ans.b);
    }
    else{
        printf("%lld\n", ans.c);
    }
}

int main(){
    /*int next = 1;
    for (int i = 0; i < 100; ++ i){
        while (vis[next]){
            ++ next;
        }
        int a = next;
        int nnext = a + 1;
        while (vis[nnext] || vis[nnext ^ a]){
            ++ nnext;
        }
        int b = nnext;
        int c = a ^ b;
        vis[a] = vis[b] = vis[c] = true;
        printf("%d %d %d\n", a, b, c);
    }*/
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = power[i - 1] * 4;
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

const int N = 110;
using ll = long long;

ll a[N], code[N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        ll x = a[i];
        std::vector <int> vec;
        for ( ; x > 0; x /= k){
            if (x % k > 1){
                puts("NO");
                return;
            }
            vec.emplace_back(x % k);
        }
        code[i] = 0;
        for (int j = int(vec.size()) - 1; j >= 0; -- j){
            code[i] = code[i] << 1 | vec[j];
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            if (code[i] & code[j]){
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}
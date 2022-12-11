#include <bits/stdc++.h>

const int N = 200010;
const int BIT = 20;
using ll = long long;

ll a[N];
ll st[N][BIT];
int lowbit[N];

ll calc(int l, int r){
    int num = lowbit[r - l + 1];
    ll val1 = st[l][num], val2 = st[r - (1 << num) + 1][num];
    return std::gcd(val1, val2);
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; ++ i){
        st[i][0] = std::abs(a[i] - a[i + 1]);
    }
    for (int j = 1; j < BIT; ++ j){
        for (int i = 1; i < n; ++ i){
            int next = i + (1 << (j - 1));
            if (next >= n){
                break;
            }
            ll val1 = st[i][j - 1], val2 = st[next][j - 1];
            st[i][j] = val1 == 0 && val2 == 0 ? 0 : std::gcd(val1, val2);
        }
    }
    int ans = 1;
    for (int i = 1, j = 1; i <= n; ++ i, j = std::max(j, i)){
        ll cur = i == j ? 0 : calc(i, j - 1);
        while (cur != 1 && j < n){
            ll value = std::gcd(cur, std::abs(a[j + 1] - a[j]));
            if (value != 1){
                ++ j;
                cur = value;
            }
            else{
                break;
            }
        }
        if (cur != 1){
            ans = std::max(ans, j - i + 1);
        }
    }
    printf("%d\n", ans);
}

int main(){
    for (int i = 2; i < N; ++ i){
        lowbit[i] = lowbit[i >> 1] + 1;
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
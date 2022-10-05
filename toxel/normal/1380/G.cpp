#include <bits/stdc++.h>

const int N = 300010;
const int moder = 998244353;

int a[N];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n, std::greater <int>());
    for (int i = 1; i < n; ++ i){
        a[i] += a[i - 1];
        a[i] -= a[i] >= moder ? moder : 0;
    }
    for (int i = 1; i <= n; ++ i){
        int ans = 0;
        for (int j = 0; j < n; j += i){
            int r = std::min(n - 1, j + i - 1);
            int num = j / i;
            ans = (ans + 1ll * num * (a[r] - (j ? a[j - 1] : 0))) % moder;
        }
        ans += ans < 0 ? moder : 0;
        ans = 1ll * ans * powermod(n, moder - 2) % moder;
        printf("%d%c", ans, " \n"[i == n]);
    }
    return 0;
}
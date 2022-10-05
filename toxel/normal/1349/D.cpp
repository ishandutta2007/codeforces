#include <bits/stdc++.h>

const int moder = 998244353;
const int N = 300010;

int inv[N], a[N];
int f[N];

int main(){
    inv[1] = 1;
    for (int i = 2; i < N; ++ i){
        inv[i] = moder - 1ll * (moder / i) * inv[moder % i] % moder;
    }
    int n;
    scanf("%d", &n);
    int m = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        m += a[i];
    }
    f[0] = f[1] = 1;
    for (int i = 1; i < m; ++ i){
        int d = f[i] - f[i - 1] - 1;
        int coe = 1ll * i * (n - 1) % moder * inv[m - i] % moder;
        f[i + 1] = (f[i] + 1ll * coe * d) % moder;
        f[i + 1] += f[i + 1] < 0 ? moder : 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        ans += f[a[i]];
        ans -= ans >= moder ? moder : 0;
    }
    ans -= f[m];
    ans = (ans - 1ll * f[0] * (n - 1)) % moder;
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}

// #include <bits/stdc++.h>
//
// const int moder = 998244353;
// const int N = 330010;
//
// int a[N];
// int ans[N];
// int k[N], bb[N];
// int inv[N];
//
// int powermod(int a, int exp){
//     int ret = 1;
//     for ( ; exp > 0; exp >>= 1){
//         if (exp & 1){
//             ret = 1ll * ret * a % moder;
//         }
//         a = 1ll * a * a % moder;
//     }
//     return ret;
// }
//
// int main(){
//     inv[1] = 1;
//     for (int i = 2; i < N; ++ i){
//         inv[i] = moder - 1ll * (moder / i) * inv[moder % i] % moder;
//     }
//     int n;
//     scanf("%d", &n);
//     int sum = 0;
//     for (int i = 0; i < n; ++ i){
//         scanf("%d", &a[i]);
//         sum += a[i];
//     }
//     k[0] = 1;
//     for (int i = 0; i <= 0; ++ i){
//         int c = 1ll * (sum - i) * inv[sum] % moder * inv[n - 1] % moder;
//         int b = (1 - c) % moder;
//         b += b < 0 ? moder : 0;
//         k[1] = 1ll * (1 - b) * powermod(c, moder - 2) % moder;
//         k[1] += k[1] < 0 ? moder : 0;
//         bb[1] = powermod(c, moder - 2);
//         bb[1] = (moder - bb[1]) % moder;
//     }
//     for (int i = 1; i < sum; ++ i){
//         int a = 1ll * i * inv[sum] % moder;
//         int c = 1ll * (sum - i) * inv[sum] % moder * inv[n - 1] % moder;
//         int b = (1 - a - c) % moder;
//         b += b < 0 ? moder : 0;
//         k[i + 1] = (1ll * (1 - b) * k[i] - 1ll * a * k[i - 1]) % moder;
//         bb[i + 1] = (1ll * (1 - b) * bb[i] - 1ll * a * bb[i - 1] - 1) % moder;
//         k[i + 1] = 1ll * k[i + 1] * powermod(c, moder - 2) % moder;
//         bb[i + 1] = 1ll * bb[i + 1] * powermod(c, moder - 2) % moder;
//         k[i + 1] += k[i + 1] < 0 ? moder : 0;
//         bb[i + 1] += bb[i + 1] < 0 ? moder : 0;
//     }
//     int x = -1ll * bb[sum] * powermod(k[sum], moder - 2) % moder;
//     x += x < 0 ? moder : 0;
//     int ans = 0;
//     for (int i = 0; i < n; ++ i){
//         ans = (ans + 1ll * k[a[i]] * x + bb[a[i]]) % moder;
//     }
//     ans = (ans - 1ll * (n - 1) * x) % moder;
//     ans += ans < 0 ? moder : 0;
//     ans = 1ll * ans * inv[n] % moder;
//     printf("%d\n", ans);
//     return 0;
// }
#include<bits/stdc++.h>

const int N = 100010;
const int moder = 1e9 + 7;

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int n;
int a[N], e[N];

int main(){
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    e[0] = 114;
    e[1] = 514;
    for (int i = 1; i < N - 1; ++ i){
        int d = (e[i] - e[i - 1] - 1ll * (sum - 1) * powermod(sum - i, moder - 2)) % moder;
        e[i + 1] = (e[i] + d) % moder;
        e[i + 1] += e[i + 1] < 0 ? moder : 0;
    }
    int ans = 0;
    ans += ans < 0 ? moder : 0;
    for (int i = 0; i < n; ++ i){
        ans += e[a[i]];
        ans -= ans >= moder ? moder : 0;
    }
    int ans1 = (e[0] + 1ll * sum * (e[1] - e[0]) - 1ll * (sum - 1) * (sum - 1)) % moder;
    ans1 = (ans1 + 1ll * (n - 1) * e[0]) % moder;
    ans1 += ans1 < 0 ? moder : 0;
    ans -= ans1;
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}
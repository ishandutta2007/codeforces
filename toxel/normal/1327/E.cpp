#include <bits/stdc++.h>

const int N = 200010;
const int moder = 998244353;

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

int ans[N], suf[N];

void add(int &a, int b){a += b; a -= a >= moder ? moder : 0;}
void sub(int &a, int b){a -= b; a += a < 0 ? moder : 0;}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        ans[i] = 1ll * (n - i + 1) * 10 % moder * powermod(10, n - i) % moder;
    }
    int pre = 0;
    for (int i = n; i >= 1; -- i){
        sub(ans[i], pre);
        suf[i] = suf[i + 1];
        add(suf[i], ans[i]);
        add(pre, suf[i]);
        add(pre, ans[i]);
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
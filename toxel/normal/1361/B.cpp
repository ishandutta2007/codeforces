#include <bits/stdc++.h>

const int N = 1000010;
const int moder = int(1e9) + 7;
using ll = long long;
const ll INF = 1e18;

int k[N];

ll mult(ll a, ll b){
    return a <= INF / b ? a * b : INF;
}

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

ll power(ll a, int exp){
    ll ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = mult(ret, a);
        }
        a = mult(a, a);
    }
    return ret;
}

void read(int &n){
    n = 0;
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    n = ch - '0';
    while (isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
}

void solve(){
    int n, p;
    read(n), read(p);
    for (int i = 0; i < n; ++ i){
        read(k[i]);
    }
    std::sort(k, k + n, std::greater<int>());
    int ans = 0;
    ll big = 0;
    for (int i = 0, j = 0; i < n; i = j){
        while (j < n && k[i] == k[j]){
            ++ j;
        }
        int num = j - i;
        if (big >= num){
            big -= num;
            ans -= num;
            ans += ans < 0 ? moder : 0;
        }
        else{
            if ((big + num) % 2 == 0){
                big = ans = 0;
            }
            else{
                big = ans = 1;
            }
        }
        int exp = j == n ? k[i] : k[i] - k[j];
        big = mult(big, power(p, exp));
        ans = 1ll * ans * powermod(p, exp) % moder;
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    read(test);
    while (test --){
        solve();
    }
    return 0;
}
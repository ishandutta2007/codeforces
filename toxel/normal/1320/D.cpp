#include <bits/stdc++.h>

const int N = 200010;
const int BASE = 37;
std::mt19937 rnd(19971109);
const int M = 5;

char s[N];
int pre[N][2];
std::vector <int> prime, now_prime;
int ppre[N][M][2];

int calc_zero(int l, int r){
    return pre[r][0] - pre[l - 1][0];
}

int powermod(int a, int exp, int moder){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int get(int l, int r, int i){
    int trans = pre[l - 1][1] & 1;
    int moder = now_prime[i];
    int value = ppre[pre[r][0]][i][trans] - ppre[pre[l - 1][0]][i][trans];
    value += value < 0 ? moder : 0 ;
    int mult = powermod(BASE, moder - 2, moder);
    mult = powermod(mult, pre[l - 1][0], moder);
    value = 1ll * value * mult % moder;
    return value;
}

int main(){
    for (int i = int(1e9) - int(1e4); i < int(1e9); ++ i){
        bool flag = true;
        for (int j = 2; j * j <= i; ++ j){
            if (i % j == 0){
                flag = false;
                break;
            }
        }
        if (flag){
            prime.emplace_back(i);
        }
    }
    int n;
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++ i){
        pre[i][0] = pre[i - 1][0] + (s[i] == '0');
        pre[i][1] = pre[i - 1][1] + (s[i] == '1');
    }
    for (int i = 0; i < M; ++ i){
        now_prime.emplace_back(prime[rnd() % prime.size()]);
    }
    for (int i = 0; i < M; ++ i){
        int moder = now_prime[i];
        int cnt = 0, cur = 1;
        for (int j = 1; j <= n; ++ j){
            if (s[j] == '1'){
                continue;
            }
            for (int k = 0; k < 2; ++ k){
                ppre[cnt + 1][i][k] = (1ll * cur * ((pre[j - 1][1] & 1) ^ k) + ppre[cnt][i][k]) % moder;
            }
            ++ cnt;
            cur = 1ll * cur * BASE % moder;
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int l1, l2, len;
        scanf("%d%d%d", &l1, &l2, &len);
        if (calc_zero(l1, l1 + len - 1) != calc_zero(l2, l2 + len - 1)){
            puts("NO");
            continue;
        }
        bool flag = true;
        for (int i = 0; i < M; ++ i){
            if (get(l1, l1 + len - 1, i) != get(l2, l2 + len - 1, i)){
                flag = false;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
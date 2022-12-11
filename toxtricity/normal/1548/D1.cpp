#include <bits/stdc++.h>

const int N = 6010;
using ll = long long;

int x[N], y[N];
int type[4];
ll comb[N][5];

int encode(int u, int v){
    return u * 2 + v;
}

void decode(int code, int &u, int &v){
    u = code / 2, v = code % 2;
}

int check(int a, int b, int c, int d){
    a -= c, b -= d;
    a %= 2, b %= 2;
    if (a == 0 && b == 0){
        return 0;
    }
    return 1;
}

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j < 5 && j <= i; ++ j){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
        ++ type[encode(x[i] / 2 % 2, y[i] / 2 % 2)];
    }
    ll ans = 0;
    for (int i = 0; i < 4; ++ i){
        for (int j = i; j < 4; ++ j){
            for (int k = j; k < 4; ++ k){
                int u1, v1;
                int u2, v2;
                int u3, v3;
                decode(i, u1, v1);
                decode(j, u2, v2);
                decode(k, u3, v3);
                int a = check(u1, v1, u2, v2);
                int b = check(u2, v2, u3, v3);
                int c = check(u3, v3, u1, v1);
                if ((a + b + c) % 2 == 0){
                    if (i == k){
                        ans += comb[type[i]][3];
                    }
                    else if (i == j){
                        ans += comb[type[i]][2] * type[k];
                    }
                    else if (j == k){
                        ans += comb[type[k]][2] * type[i];
                    }
                    else{
                        ans += 1ll * type[i] * type[j] * type[k];
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
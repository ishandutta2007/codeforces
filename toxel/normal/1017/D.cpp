#include<bits/stdc++.h>

const int N = 500010;
const int M = 1 << 13;
const int K = 120;

int n, q, m;
char s[N];
int w[N], cnt[N];
int pre[M][K];

void read(int &x){
    scanf("%s", s);
    x = 0;
    for (int i = 0; i < n; ++ i){
        x |= s[i] - '0' << i;
    }
}

int value(int x, int y){
    int ret = 0;
    for (int i = 0; i < n; ++ i){
        if ((x >> i & 1) == (y >> i & 1)){
            ret += w[i];
        }
    }
    return ret;
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &w[i]);
    }
    for (int i = 0, x; i < m; ++ i){
        read(x);
        ++ cnt[x];
    }
    for (int i = 0; i < 1 << n; ++ i){
        for (int j = 0; j < 1 << n; ++ j){
            int x = value(i, j);
            if (x < K){
                pre[i][x] += cnt[j];
            }
        }
    }
    for (int i = 0; i < 1 << n; ++ i){
        for (int j = 1; j < K; ++ j){
            pre[i][j] += pre[i][j - 1];
        }
    }
    while (q --){
        int x, k;
        read(x);
        scanf("%d", &k);
        printf("%d\n", pre[x][k]);
    }
    return 0;
}
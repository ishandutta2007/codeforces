#include<bits/stdc++.h>

const int N = 100100;
const int M = 13;

struct creature{
    static const int N = 1 << 12;
    std::bitset <N> set;

    creature(){}
    creature(std::bitset <N> set):set(set){}

    creature min(const creature &c)const{
        return creature(set & c.set);
    }

    creature max(const creature &c)const{
        return creature(set | c.set);
    }
};

creature c[N];
int a[N][M], _a[N][M], sit[N];
int init[M][N * M], code[N * M];

int main(){
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0; i < k; ++ i){
        for (int j = 0; j < n; ++ j){
            scanf("%d", &a[j][i]);
            _a[j][i] = a[j][i];
        }
    }
    for (int i = 0; i < n; ++ i){
        std::sort(a[i], a[i] + k);
        int sz = std::unique(a[i], a[i] + k) - a[i];
        sit[i + 1] = sit[i] + sz;
        for (int j = sit[i]; j < sit[i + 1]; ++ j){
            for (int kk = 0; kk < k; ++ kk){
                init[kk][j] = _a[i][kk] >= a[i][j - sit[i]];
            }
        }
    }
    for (int i = 0; i < sit[n]; ++ i){
        for (int j = 0; j < k; ++ j){
            code[i] |= init[j][i] << j;
        }
    }
    for (int i = 0; i < 1 << k; ++ i){
        for (int j = 0; j < k; ++ j){
            c[j].set[i] = i >> j & 1;
        }
    }
    int cnt = k;
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int x, y;
            scanf("%d%d", &x, &y);
            -- x, -- y;
            c[cnt ++] = c[x].max(c[y]);
        }
        else if (type == 2){
            int x, y;
            scanf("%d%d", &x, &y);
            -- x, -- y;
            c[cnt ++] = c[x].min(c[y]);
        }
        else if (type == 3){
            int x, y;
            scanf("%d%d", &x, &y);
            -- x, -- y;
            for (int i = sit[y]; i < sit[y + 1]; ++ i){
                if (i == sit[y + 1] - 1 || c[x].set[code[i]] && !c[x].set[code[i + 1]]){
                    printf("%d\n", a[y][i - sit[y]]);
                    break;
                }
            }
        }
    }
    return 0;
}
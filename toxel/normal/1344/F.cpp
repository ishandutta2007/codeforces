#include <bits/stdc++.h>

const int N = 2010;
const int M = 4;

struct Matrix{
    static const int N = 2;

    int a[N][N]{};

    int *operator [](const int &n){return a[n];}

    Matrix operator *(const Matrix &m)const{
        Matrix ret;
        for (int k = 0; k < 2; ++ k){
            for (int i = 0; i < 2; ++ i){
                for (int j = 0; j < 2; ++ j){
                    ret[i][j] ^= a[i][k] * m.a[k][j];
                }
            }
        }
        return ret;
    }
};

int map[M] = {'.', 'R', 'Y', 'B'};
int inv_map[N];
Matrix m[N];
char op[N];
int y[N];
std::bitset <N> set[N];
int base[N];
int ans[N];

int main(){
    for (int i = 0; i < M; ++ i){
        inv_map[map[i]] = i;
    }
    inv_map['W'] = inv_map['.'];
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        m[i][0][0] = m[i][1][1] = 1;
    }
    int cnt = 0;
    while (k --){
        int num;
        scanf("%s%d", op, &num);
        std::vector<int> vec(num);
        for (int i = 0; i < num; ++ i){
            scanf("%d", &vec[i]);
            -- vec[i];
        }
        if (isupper(op[0])){
            Matrix trans;
            if (!strcmp("YB", op)){
                trans[0][0] = trans[0][1] = trans[1][1] = 1;
            }
            else if (!strcmp("RY", op)){
                trans[0][1] = trans[1][0] = 1;
            }
            else if (!strcmp("RB", op)){
                trans[0][0] = trans[1][0] = trans[1][1] = 1;
            }
            for (auto pos : vec){
                m[pos] = trans * m[pos];
            }
        }
        else{
            scanf("%s", op);
            int result = inv_map[op[0]];
            for (int bit = 0; bit < 2; ++ bit){
                for (auto pos : vec){
                    set[cnt][2 * pos + 0] = m[pos][bit][0];
                    set[cnt][2 * pos + 1] = m[pos][bit][1];
                }
                y[cnt] = result >> bit & 1;
                ++ cnt;
            }
        }
    }
    int now = 0;
    for (int i = 0; i < 2 * n; ++ i){
        for (int j = now; j < cnt; ++ j){
            if (set[j][i]){
                std::swap(set[j], set[now]);
                std::swap(y[j], y[now]);
            }
        }
        if (!set[now][i]){
            continue;
        }
        base[now] = i;
        for (int j = 0; j < cnt; ++ j){
            if (j == now){
                continue;
            }
            if (set[j][i]){
                set[j] ^= set[now];
                y[j] ^= y[now];
            }
        }
        ++ now;
    }
    for (int i = now; i < cnt; ++ i){
        if (y[i]){
            puts("NO");
            return 0;
        }
    }
    for (int i = 0; i < now; ++ i){
        ans[base[i]] = y[i];
    }
    puts("YES");
    for (int i = 0; i < n; ++ i){
        int result = ans[2 * i + 1] << 1 | ans[2 * i];
        putchar(char(map[result]));
    }
    puts("");
    return 0;
}
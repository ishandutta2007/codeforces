#include <bits/stdc++.h>

const int N = 4010;
const int moder = 998244353;

std::vector <int> e[N];
int fa[N];
char s[N];
int power[N];
int real[N], comp[N];

int find(int u){
    return u == fa[u] ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return;
    }
    fa[u] = v;
}

int main(){
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = power[i - 1] * 2 % moder;
    }
    scanf("%s", s);
    int m = strlen(s);
    int ans = 0;
    for (int len = 1; len < m; ++ len){
        for (int i = 0; i < N; ++ i){
            e[i].clear();
            fa[i] = i;
        }
        bool flag = true;
        for (int i = 0; i < m; ++ i){
            if (find(i) == find(m - 1 - i + m)){
                flag = false;
                break;
            }
            unite(i, m - 1 - i);
            unite(i + m, m - 1 - i + m);
        }
        for (int i = m - len; i < m; ++ i){
            if (find(i + 2 * m) == find(m - len + m - 1 - i + 3 * m)){
                flag = false;
                break;
            }
            unite(i + 2 * m, m - len + m - 1 - i + 2 * m);
            unite(i + 3 * m, m - len + m - 1 - i + 3 * m);
        }
        for (int i = 0; i < m; ++ i){
            if (s[i] == '0'){
                if (find(i) == find(i + 3 * m)){
                    flag = false;
                    break;
                }
                unite(i, i + 2 * m);
                unite(i + m, i + 3 * m);
            }
            else if (s[i] == '1'){
                if (find(i) == find(i + 2 * m)){
                    flag = false;
                    break;
                }
                unite(i, i + 3 * m);
                unite(i + m, i + 2 * m);
            }
        }
        if (!flag){
            continue;
        }
        memset(real, -1, sizeof(real));
        memset(comp, -1, sizeof(comp));
        real[0] = 0, real[0 + m] = 1;
        for (int i = 0; i < m - len; ++ i){
            real[i + 2 * m] = 1, real[i + 3 * m] = 0;
        }
        real[m - len + 2 * m] = 0, real[m - len + 3 * m] = 1;
        for (int i = 0; i < 4 * m; ++ i){
            if (real[i] == -1){
                continue;
            }
            if (comp[find(i)] != -1 && comp[find(i)] != real[i]){
                flag = false;
                break;
            }
            comp[find(i)] = real[i];
        }
        if (flag){
            int cnt = 0;
            for (int i = 0; i < 4 * m; ++ i){
                if (find(i) == i){
                    if (comp[i] == -1){
                        ++ cnt;
                    }
                }
            }
            ans += power[cnt / 2];
            ans -= ans >= moder ? moder : 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
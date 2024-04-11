#include <bits/stdc++.h>

const int N = 70;
const int M = 256;

struct Line{
    std::bitset <M> a[3];
};

int u[N], v[N];
int mat[N][N];
int col[M + 10];

void solve(){
    memset(mat, -1, sizeof(mat));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf("%d%d%d", &u[i], &v[i], &col[i]);
        if (col[i] == 3){
            col[i] = 0;
        }
        mat[u[i]][v[i]] = mat[v[i]][u[i]] = i;
    }
    std::vector <Line> equation;
    std::vector <int> num;
    std::vector <int> vis(M, -1);
    for (int i = 1; i <= n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            for (int k = j + 1; k <= n; ++ k){
                if (mat[i][j] != -1 && mat[j][k] != -1 && mat[k][i] != -1){
                    int todo[3] = {mat[i][j], mat[j][k], mat[k][i]};
                    Line l;
                    int sum = 0;
                    for (int u = 0; u < m; ++ u){
                        l.a[0].set(u);
                    }
                    for (int u = 0; u < 3; ++ u){
                        if (col[todo[u]] == -1){
                            l.a[1].set(todo[u]);
                            l.a[0].reset(todo[u]);
                        }
                        else{
                            sum += col[todo[u]];
                        }
                    }
                    sum = (3 - sum % 3) % 3;
                    equation.emplace_back(l);
                    num.emplace_back(sum);
                }
            }
        }
    }
    int sz = equation.size();
    int cur = 0;
    for (int i = 0; i < m; ++ i){
        bool found = false;
        for (int j = cur; j < sz; ++ j){
            if (equation[j].a[1].test(i) || equation[j].a[2].test(i)){
                std::swap(equation[cur], equation[j]);
                std::swap(num[cur], num[j]);
                found = true;
                break;
            }
        }
        if (!found){
            continue;
        }
        vis[i] = cur;
        if (equation[cur].a[2].test(i)){
            std::swap(equation[cur].a[1], equation[cur].a[2]);
            num[cur] = 2 * num[cur] % 3;
        }
        for (int j = 0; j < sz; ++ j){
            if (j == cur){
                continue;
            }
            Line tmp = equation[j];
            if (equation[j].a[1].test(i)){
                equation[j].a[0] = (tmp.a[0] & equation[cur].a[0]) | (tmp.a[1] & equation[cur].a[1]) | (tmp.a[2] & equation[cur].a[2]);
                equation[j].a[1] = (tmp.a[1] & equation[cur].a[0]) | (tmp.a[2] & equation[cur].a[1]) | (tmp.a[0] & equation[cur].a[2]);
                equation[j].a[2] = (tmp.a[2] & equation[cur].a[0]) | (tmp.a[0] & equation[cur].a[1]) | (tmp.a[1] & equation[cur].a[2]);
                num[j] = (3 + num[j] - num[cur]) % 3;
            }
            else if (equation[j].a[2].test(i)){
                equation[j].a[0] = (tmp.a[0] & equation[cur].a[0]) | (tmp.a[1] & equation[cur].a[2]) | (tmp.a[2] & equation[cur].a[1]);
                equation[j].a[1] = (tmp.a[1] & equation[cur].a[0]) | (tmp.a[2] & equation[cur].a[2]) | (tmp.a[0] & equation[cur].a[1]);
                equation[j].a[2] = (tmp.a[2] & equation[cur].a[0]) | (tmp.a[0] & equation[cur].a[2]) | (tmp.a[1] & equation[cur].a[1]);
                num[j] = (3 + num[j] - 2 * num[cur] % 3) % 3;
            }
        }
        ++ cur;
    }
    for (int i = cur; i < sz; ++ i){
        if (num[i]){
            puts("-1");
            return;
        }
    }
    for (int i = 0; i < m; ++ i){
        if (vis[i] == -1 && col[i] == -1){
            col[i] = 0;
        }
    }
    for (int i = 0; i < m; ++ i){
        if (vis[i] != -1){
            int pos = vis[i];
            int x = num[pos];
            for (int j = i + 1; j < m; ++ j){
                int coe = 0;
                if (equation[pos].a[1].test(j)){
                    coe = 1;
                }
                else if (equation[pos].a[2].test(j)){
                    coe = 2;
                }
                x = ((x - coe * col[j]) % 3 + 3) % 3;
            }
            col[i] = x;
        }
    }
    for (int i = 0; i < m; ++ i){
        if (col[i] == 0){
            col[i] = 3;
        }
        printf("%d%c", col[i], " \n"[i == m - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>

const int N = 500010;
const int M = 10;
const int K = 30;
typedef std::pair <int, int> pii;

struct output{
    int a, b, c, d;

    void print(){
        printf("4 %d %d %d %d\n", a + 1, b + 1, c + 1, d + 1);
    }
};

int pre[N], option[N];
bool vis[N];
std::vector <std::vector <int>> trans = {
    {1, 4, 2, 0, 3, 5, 6, 7, 8},
    {0, 2, 5, 3, 1, 4, 6, 7, 8},
    {0, 1, 2, 4, 7, 5, 3, 6, 8},
    {0, 1, 2, 3, 5, 8, 6, 4, 7}
};
int fac[M];
std::vector <output> ans;
int a[K][K];
int n, m;

void op(int x, int y){
    ans.push_back({a[x][y], a[x][y + 1], a[x + 1][y + 1], a[x + 1][y]});
    int tmp = a[x][y];
    a[x][y] = a[x + 1][y];
    a[x + 1][y] = a[x + 1][y + 1];
    a[x + 1][y + 1] = a[x][y + 1];
    a[x][y + 1] = tmp;
}

void move(int x1, int y1, int x2, int y2){
    if (x1 == n - 1 && y1 == m - 1){
        for (int i = 0; i < 2; ++ i){
            op(x1 - 1, y1 - 1);
        }
        -- x1, -- y1;
    }
    else if (x1 == n - 1){
        op(x1 - 1, y1);
        -- x1;
    }
    else if (y1 == m - 1){
        for (int i = 0; i < 3; ++ i){
            op(x1, y1 - 1);
        }
        -- y1;
    }
    if (y1 > y2){
        while (y1 > y2){
            for (int i = 0; i < 3; ++ i){
                op(x1, y1 - 1);
            }
            -- y1;
        }
    }
    else if (y1 < y2){
        while (y1 < y2){
            op(x1, y1);
            ++ y1;
        }
    }
    if (y1 == m - 1){
        while (x1 > x2){
            for (int i = 0; i < 3; ++ i){
                op(x1 - 1, y1 - 1);
            }
            -- x1;
        }
        return;
    }
    while (x1 > x2){
        op(x1 - 1, y1);
        -- x1;
    }
}

int encode(std::vector <int> vec){
    int ret = 0;
    for (int i = 0; i < 9; ++ i){
        int x = vec[i];
        for (int j = 0; j < i; ++ j){
            if (vec[j] < vec[i]){
                -- x;
            }
        }
        ret += x * fac[8 - i];
    }
    return ret;
}

std::vector <int> decode(int code){
    std::vector <int> ret(9);
    std::vector <bool> vis(9);
    for (int i = 0; i < 9; ++ i){
        int x = code / fac[8 - i];
        for (int j = 0; j < 9; ++ j){
            if (vis[j]) continue;
            if (!x){
                ret[i] = j;
                vis[j] = true;
                break;
            }
            -- x;
        }
        code %= fac[8 - i];
    }
    return ret;
}

int main(){
    fac[0] = 1;
    for (int i = 1; i < M; ++ i){
        fac[i] = fac[i - 1] * i;
    }
    std::queue <int> queue;
    queue.push(0);
    vis[0] = true;
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        std::vector <int> vec = decode(u);
        for (int i = 0; i < 4; ++ i){
            auto v = trans[i];
            std::vector <int> tmp(9);
            for (int j = 0; j < 9; ++ j){
                tmp[j] = vec[v[j]];
            }
            int x = encode(tmp);
            if (!vis[x]){
                pre[x] = u;
                option[x] = i;
                vis[x] = true;
                queue.push(x);
            }
        }
    }
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
            -- a[i][j];
        }
    }
    for (int i = 0; i < n - 2; ++ i){
        bool flag = true;
        for (int j = 0; j < m - 2; ++ j){
            int x = i * m + j;
            flag = true;
            for (int u = 0; u < n; ++ u){
                for (int v = 0; v < m; ++ v){
                    if (a[u][v] == x){
                        move(u, v, i, j);
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
        }
        flag = true;
        int x = i * m + m - 2;
        for (int u = 0; u < n; ++ u){
            for (int v = 0; v < m; ++ v){
                if (a[u][v] == x){
                    move(u, v, i, m - 1);
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        flag = true;
        x = i * m + m - 1;
        for (int u = 0; u < n; ++ u){
            for (int v = 0; v < m; ++ v){
                if (a[u][v] == x){
                    if (u == i && v == m - 2){
                        op(i, m - 2);
                        op(i + 1, m - 2);
                        op(i, m - 2);
                        for (int j = 0; j < 3; ++ j){
                            op(i + 1, m - 2);
                        }
                        op(i, m - 2);
                        op(i, m - 2);
                    }
                    else{
                        move(u, v, i + 1, m - 1);
                        for (int j = 0; j < 3; ++ j){
                            op(i, m - 2);
                        }
                    }
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
    }
    for (int i = 0; i < m - 2; ++ i){
        bool flag = true;
        int x = (n - 1) * m + i;
        for (int u = 0; u < n; ++ u){
            for (int v = 0; v < m; ++ v){
                if (a[u][v] == x){
                    move(u, v, n - 2, i);
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        flag = true;
        x = (n - 2) * m + i;
        for (int u = 0; u < n; ++ u){
            for (int v = 0; v < m; ++ v){
                if (a[u][v] == x){
                    if (u == n - 1 && v == i){
                        for (int j = 0; j < 3; ++ j){
                            op(n - 2, i);
                        }
                        for (int j = 0; j < 3; ++ j){
                            op(n - 2, i + 1);
                        }
                        for (int j = 0; j < 3; ++ j){
                            op(n - 2, i);
                        }
                        op(n - 2, i + 1);
                        op(n - 2, i);
                        op(n - 2, i);
                    }
                    else{
                        move(u, v, n - 2, i + 1);
                        for (int j = 0; j < 3; ++ j){
                            op(n - 2, i);
                        }
                    }
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
    }
    std::vector <pii> vec;
    for (int i = n - 3; i < n; ++ i){
        for (int j = m - 3; j < m; ++ j){
            vec.push_back({a[i][j], 3 * (i - n + 3) + j - m + 3});
        }
    }
    std::sort(vec.begin(), vec.end());
    std::vector <int> vvec(9);
    for (int i = 0; i < 9; ++ i){
        vvec[vec[i].second] = i;
    }
    int code = encode(vvec);
    std::vector <int> ops;
    while (code){
        ops.push_back(option[code]);
        code = pre[code];
    }
    for (auto u : ops){
        op(n - 3 + (u >> 1), m - 3 + (u & 1));
    }
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        u.print();
    }
    return 0;
}
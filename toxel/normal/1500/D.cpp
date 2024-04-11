#include <bits/stdc++.h>

const int N = 1510;
const int M = 10;
const int K = N * N;
using pii = std::pair <int, int>;

int a[N][N];
unsigned x[N][N][M + 2], y[N][N][M + 2];
int cntx[N][N], cnty[N][N];
std::deque <pii> queue[M + 2], tmp_queue[M + 2];
int pre[N];
int vis[K];

int main(){
    memset(vis, -1, sizeof(vis));
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        for (int j = 0; j < n; ++ j){
            x[i][j][cntx[i][j] ++] = 1u * i * K + a[i][j];
            for (int k = 0; k < cntx[i + 1][j] && cntx[i][j] <= q; ++ k){
                int col = x[i + 1][j][k] % K;
                if (col == a[i][j]){
                    continue;
                }
                x[i][j][cntx[i][j] ++] = x[i + 1][j][k];
            }
        }
    }
    for (int j = 0; j < n; ++ j){
        for (int i = 0; i < n; ++ i){
            y[i][j][cnty[i][j] ++] = 1u * j * K + a[i][j];
            if (j == 0){
                continue;
            }
            for (int k = 0; k < cnty[i][j - 1] && cnty[i][j] <= q; ++ k){
                int col = y[i][j - 1][k] % K;
                if (col == a[i][j]){
                    continue;
                }
                y[i][j][cnty[i][j] ++] = y[i][j - 1][k];
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        int ans = 0;
        std::vector <int> colors;
        for (int j = 0; j < n; ++ j){
            while (i + ans < n && j + ans < n){
                int i1 = i, j1 = j + ans;
                int i2 = i + ans, j2 = j + ans - 1;
                int ncnt = colors.size();
                std::vector <int> rollback;
                for (int k = 0; k < cntx[i1][j1] && ncnt <= q; ++ k){
                    unsigned u = x[i1][j1][k];
                    int pos = u / K;
                    int col = u % K;
                    if (pos > i2){
                        break;
                    }
                    if (vis[col] == -1){
                        rollback.emplace_back(col);
                        vis[col] = ncnt;
                        ++ ncnt;
                    }
                }
                if (j2 >= 0){
                    for (int k = 0; k < cnty[i2][j2] && ncnt <= q; ++ k){
                        unsigned u = y[i2][j2][k];
                        int pos = u / K;
                        int col = u % K;
                        if (pos < j){
                            break;
                        }
                        if (vis[col] == -1){
                            rollback.emplace_back(col);
                            vis[col] = ncnt;
                            ++ ncnt;
                        }
                    }
                }
                if (ncnt > q){
                    for (auto u : rollback){
                        vis[u] = -1;
                    }
                    break;
                }
                for (auto u : rollback){
                    colors.emplace_back(u);
                }
                for (int k = 0; k < cntx[i1][j1]; ++ k){
                    unsigned u = x[i1][j1][k];
                    int yy = u / K;
                    int col = u % K;
                    int xx = j1;
                    if (yy > i2){
                        break;
                    }
                    auto &que = queue[vis[col]];
                    while (!que.empty() && que.back().second >= yy){
                        que.pop_back();
                    }
                    que.emplace_back(xx, yy);
                }
                if (j2 >= 0){
                    for (int k = 0; k < cnty[i2][j2]; ++ k){
                        unsigned u = y[i2][j2][k];
                        int xx = u / K;
                        int col = u % K;
                        int yy = i2;
                        if (xx < j){
                            break;
                        }
                        auto &que = queue[vis[col]];
                        if (que.empty() || (que.back().first < xx && que.back().second < yy)){
                            que.emplace_back(xx, yy);
                        }
                    }
                }
                ++ ans;
            }
            ++ pre[ans];
            std::vector <int> ncolors;
            for (auto u : colors){
                auto &que = queue[vis[u]];
                if (!que.empty() && que[0].first == j){
                    que.pop_front();
                }
                if (!que.empty() && que.back().second == i + ans - 1){
                    que.pop_back();
                }
                if (que.empty()){
                    vis[u] = -1;
                }
                else{
                    int sz = ncolors.size();
                    vis[u] = sz;
                    tmp_queue[sz].swap(que);
                    ncolors.emplace_back(u);
                }
            }
            -- ans;
            int sz = ncolors.size();
            for (int k = 0; k < sz; ++ k){
                queue[k].swap(tmp_queue[k]);
            }
            colors.swap(ncolors);
        }
        for (auto u : colors){
            queue[vis[u]].clear();
            vis[u] = -1;
        }
    }
    for (int i = N - 2; i >= 0; -- i){
        pre[i] += pre[i + 1];
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d\n", pre[i]);
    }
    return 0;
}
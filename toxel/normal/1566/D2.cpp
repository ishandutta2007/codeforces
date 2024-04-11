#include <bits/stdc++.h>

const int N = 310;
const int M = N * N;

int a[N][N];
std::vector <int> vec[M];
int c[M];
int c1[M];

void add(int sit, int value){
    for (sit += 1; sit < M; sit += sit & -sit){
        c1[sit] += value;
    }
}

int query(int sit){
    int ret = 0;
    for (sit += 1; sit; sit -= sit & -sit){
        ret += c1[sit];
    }
    return ret;
}

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
            c[cnt ++] = a[i][j];
        }
    }
    std::sort(c, c + cnt);
    cnt = std::unique(c, c + cnt) - c;
    for (int i = 0; i <= cnt; ++ i){
        vec[i].clear();
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            a[i][j] = std::lower_bound(c, c + cnt, a[i][j]) - c;
            vec[a[i][j]].emplace_back(i * m + j);
        }
    }
    std::vector <int> queue;
    int ans = 0;
    for (int i = 0; i < cnt; ++ i){
        for (auto u : vec[i]){
            queue.emplace_back(u);
            if (int(queue.size()) == m){
                for (int j = 0, k = 0; j < m; j = k){
                    while (k < m){
                        int x = queue[j];
                        int v1 = a[x / m][x % m];
                        x = queue[k];
                        int v2 = a[x / m][x % m];
                        if (v1 != v2){
                            break;
                        }
                        ++ k;
                    }
                    std::reverse(queue.begin() + j, queue.begin() + k);
                }
                for (auto v : queue){
                    ans += query(v);
                    add(v, 1);
                }
                for (auto v : queue){
                    add(v, -1);
                }
                queue.clear();
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
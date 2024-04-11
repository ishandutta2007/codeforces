#include <bits/stdc++.h>

const int N = 5010;
const int moder = int(1e9) + 7;
using pii = std::pair <int, int>;

short pre[N][N], pre1[N][N], boom[N][N];
int s[N], f[N], h[N];
int left[N], right[N];
std::vector <int> vec[N];

void update(pii &a, pii b){
    if (a.first != b.first){
        a = std::max(a, b);
        return;
    }
    a.second += b.second;
    a.second -= a.second >= moder ? moder : 0;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= m; ++ i){
        scanf("%d%d", &f[i], &h[i]);
        int cnt = 0;
        for (int j = 1; j <= n; ++ j){
            if (s[j] == f[i]){
                ++ cnt;
                if (cnt == h[i]){
                    left[i] = j;
                    break;
                }
            }
        }
        cnt = 0;
        for (int j = n; j >= 1; -- j){
            if (s[j] == f[i]){
                ++ cnt;
                if (cnt == h[i]){
                    right[i] = j;
                    break;
                }
            }
        }
        if (left[i] > 0 && right[i] > 0 && left[i] < right[i]){
            ++ boom[f[i]][left[i]];
            -- boom[f[i]][right[i]];
        }
        if (left[i] > 0){
            vec[left[i]].emplace_back(i);
            ++ pre[f[i]][left[i]];
        }
        if (right[i] > 0){
            ++ pre1[f[i]][right[i]];
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            boom[i][j] += boom[i][j - 1];
            pre[i][j] += pre[i][j - 1];
        }
        for (int j = n; j >= 1; -- j){
            pre1[i][j] += pre1[i][j + 1];
        }
    }
    pii p = {0, 1};
    for (int i = 1; i <= n; ++ i){
        if (vec[i].size() == 0){
            continue;
        }
        int sum = 0, prod = 1;
        for (int j = 1; j <= n; ++ j){
            if (j == s[i]){
                int r = pre1[j][i + 1];
                int l = vec[i].size();
                if (r == 0){
                    ++ sum;
                    prod = 1ll * prod * l % moder;
                    continue;
                }
                int bboom = 0;
                for (auto u : vec[i]){
                    if (right[u] > left[u]){
                        ++ bboom;
                    }
                }
                if (l * r == bboom){
                    ++ sum;
                    continue;
                }
                sum += 2;
                prod = 1ll * prod * (l * (r - bboom)) % moder;
                continue;
            }
            int l = pre[j][i], r = pre1[j][i + 1];
            if (l == 0 && r == 0){
                continue;
            }
            if (l == 0 || r == 0){
                ++ sum;
                prod = 1ll * prod * (l + r) % moder;
                continue;
            }
            if (l * r == boom[j][i]){
                ++ sum;
                prod = 2ll * prod % moder;
                continue;
            }
            sum += 2;
            prod = 1ll * prod * (l * r - boom[j][i]) % moder;
        }
        update(p, {sum, prod});
    }
    int sum = 0, prod = 1;
    for (int i = 1; i <= n; ++ i){
        if (pre1[i][1]){
            ++ sum;
            prod = 1ll * prod * pre1[i][1] % moder;
        }
    }
    update(p, {sum, prod});
    if (p.first == 0){
        p.second = 1;
    }
    printf("%d %d\n", p.first, p.second);
    return 0;
}
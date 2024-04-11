//
// Created by  on 2022/3/25.
//

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_TEMPLATE_H
#define WORKSPACE_TEMPLATE_H

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;
using piiii = std::tuple <int, int, int, int>;
using pll = std::pair <ll, ll>;
using plll = std::tuple <ll, ll, ll>;
using pllll = std::tuple <ll, ll, ll, ll>;

//
// Created by  on 2022/1/23.
//

#ifndef WORKSPACE_DISJOINTSET_H
#define WORKSPACE_DISJOINTSET_H

#include <bits/stdc++.h>

class DisjointSet{
public:
    std::vector <int> fa, sz;

    explicit DisjointSet(int n){
        n += 10;
        fa.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++ i){
            fa[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u){
        return fa[u] == u ? u : (fa[u] = find(fa[u]));
    }

    void unite(int u, int v){
        u = find(u), v = find(v);
        fa[u] = v;
        sz[v] += sz[u];
    }
};

#endif //WORKSPACE_DISJOINTSET_H

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n + 1), cnt(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
            ++ cnt[a[i]];
        }
        int odd = 0;
        for (int i = 1; i <= n; ++ i){
            odd += cnt[i] % 2;
        }
        if (odd >= 2){
            std::cout << "NO\n";
            return;
        }
        if (odd == 1){
            odd = 0;
            for (int i = 1; i <= n; ++ i){
                if (cnt[i] % 2 == 1){
                    odd = i;
                    break;
                }
            }
            if (cnt[odd] == 1){
                for (int i = 1; i <= n; ++ i){
                    if (a[i] == odd && i == (n + 1) / 2){
                        std::cout << "NO\n";
                        return;
                    }
                }
            }
        }
        std::cout << "YES\n";
        std::vector <int> id(n + 1);
        for (int i = 1; i <= n; ++ i){
            id[i] = i;
        }
        std::sort(id.begin() + 1, id.end(), [&](const int &id1, const int &id2){
            int x = a[id1] == odd, y = a[id2] == odd;
            if (x != y) return x < y;
            return a[id1] < a[id2];
        });
        std::vector <int> tmp = {0};
        for (int i = 1; i <= n; i += 2){
            tmp.emplace_back(id[i]);
        }
        for (int i = n - (n % 2); i > 0; i -= 2){
            tmp.emplace_back(id[i]);
        }
        id.swap(tmp);
        if (n % 2 == 1 && id[(n + 1) / 2] == (n + 1) / 2){
            for (int i = 1; i <= n; ++ i){
                if (i == (n + 1) / 2){
                    continue;
                }
                if (a[id[i]] == a[id[(n + 1) / 2]]){
                    std::swap(id[i], id[(n + 1) / 2]);
                }
            }
        }
        DisjointSet set(n);
        for (int i = 1; i <= n; ++ i){
            set.unite(i, id[i]);
        }
        for (int i = 1; i <= n / 2; ++ i){
            if (set.find(i) != set.find(n + 1 - i)){
                std::swap(id[i], id[n + 1 - i]);
                set.unite(i, n + 1 - i);
            }
        }
        std::vector <int> pos;
        for (int i = 1; i <= n; ++ i){
            if (i == (n + 1) / 2){
                continue;
            }
            if (set.find(i) != i){
                continue;
            }
            int x = i;
            if (x > (n + 1) / 2){
                x = n + 1 - x;
            }
            pos.emplace_back(x);
        }
        int sz = pos.size();
        for (int i = 1; i < sz; ++ i){
            int arr[] = {pos[0], n + 1 - pos[0], pos[i], n + 1 - pos[i]};
            int arr1[] = {id[arr[0]], id[arr[1]], id[arr[2]], id[arr[3]]};
            id[arr[0]] = arr1[2];
            id[arr[1]] = arr1[3];
            id[arr[2]] = arr1[1];
            id[arr[3]] = arr1[0];
        }
        for (int i = 1; i <= n; ++ i){
            std::cout << id[i] << " \n"[i == n];
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H
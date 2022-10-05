//
// Created by  on 2022/2/26.
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

using db = double;
const db eps = 1e-9;
const db PI = acos(-1.0);
const db INF = 1e100;

db norm(db p){
    while (p < 0){
        p += 2 * PI;
    }
    while (p >= 2 * PI){
        p -= 2 * PI;
    }
    return p;
}

class Solver{
public:
    db r;
    std::map <pii, std::vector <int>> map;
    std::vector <pii> ps;
    std::vector <pii> id;
    int n, l, k;

    void rebuild(){
        map.clear();
        for (int i = 0; i < n; ++ i){
            int x = std::floor(ps[i].first / (2 * r));
            int y = std::floor(ps[i].second / (2 * r));
            id[i] = {x, y};
            map[id[i]].emplace_back(i);
        }
    }

    bool check(int i, db mid){
        std::vector <db> c = {0, 2 * PI};
        using pidd = std::tuple <int, db, db>;
        std::vector <pidd> vec;
        for (int j = -1; j <= 1; ++ j){
            for (int k = -1; k <= 1; ++ k){
                int x = id[i].first + j;
                int y = id[i].second + k;
                auto u = map.find({x, y});
                if (u == map.end()){
                    continue;
                }
                auto it = std::lower_bound(u -> second.begin(), u -> second.end(), i - l + 1);
                while (it != u -> second.end() && *it <= i + l - 1){
                    if (*it == i){
                        ++ it;
                        continue;
                    }
                    pii p1 = ps[i], p2 = ps[*it];
                    int dx = p2.first - p1.first, dy = p2.second - p1.second;
                    ll dis = 1ll * dx * dx + 1ll * dy * dy;
                    if (dis > 4 * mid * mid){
                        ++ it;
                        continue;
                    }
                    db base = std::atan2(dy, dx);
                    db dis1 = std::sqrt(dis) / 2;
                    db diff = std::acos(std::min(1., dis1 / mid));
                    db angle1 = norm(base - diff);
                    db angle2 = norm(base + diff);
                    c.emplace_back(angle1);
                    c.emplace_back(angle2);
                    vec.emplace_back(*it, angle1, angle2);
                    ++ it;
                }
            }
        }
        std::sort(c.begin(), c.end());
        std::sort(vec.begin(), vec.end());
        int sz = vec.size();
        int sz1 = c.size();
        std::vector <piii> vec1;
        for (int j = 0; j < sz; ++ j){
            auto [x, y, z] = vec[j];
            int y1 = std::lower_bound(c.begin(), c.end(), y) - c.begin();
            int z1 = std::lower_bound(c.begin(), c.end(), z) - c.begin();
            vec1.emplace_back(x, y1, z1);
        }
        // std::cout << mid << '\n';
        // std::cout.flush();
        std::vector <int> cnt(sz1 - 1);
        for (int u = 0, v = 0; u < sz; ++ u){
            auto [x1, y1, z1] = vec1[u];
            while (v < sz && std::get <0>(vec1[v]) - x1 <= l - 1){
                auto [x2, y2, z2] = vec1[v];
                if (y2 <= z2){
                    for (int j = y2; j < z2; ++ j){
                        ++ cnt[j];
                    }
                }
                else{
                    for (int j = y2; j < sz1 - 1; ++ j){
                        ++ cnt[j];
                    }
                    for (int j = 0; j < z2; ++ j){
                        ++ cnt[j];
                    }
                }
                ++ v;
            }
            for (int j = 0; j < sz1 - 1; ++ j){
                if (cnt[j] >= k - 1){
                    return true;
                }
            }
            if (y1 <= z1){
                for (int j = y1; j < z1; ++ j){
                    -- cnt[j];
                }
            }
            else{
                for (int j = y1; j < sz1 - 1; ++ j){
                    -- cnt[j];
                }
                for (int j = 0; j < z1; ++ j){
                    -- cnt[j];
                }
            }
        }
        return false;
    }

    void solve(){
        std::cin >> n >> l >> k;
        ps.resize(n);
        id.resize(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> ps[i].first >> ps[i].second;
        }
        r = std::sqrt(2) * 1e8 / std::sqrt((l - 1) / (k - 1));
        rebuild();
        for (int i = 0; i < n; ++ i){
            if (!check(i, r)){
                continue;
            }
            db left = 0.1, right = r;
            for (int _ = 0; _ < 100; ++ _){
                db mid = (left + right) * 0.5;
                if (check(i, mid)){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
            r = left;
            rebuild();
        }
        std::cout << std::fixed << std::setprecision(18) << r << '\n';
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
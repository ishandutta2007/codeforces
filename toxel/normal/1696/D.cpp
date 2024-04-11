//
// Created by  on 2022/6/25.
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

using ll = long long;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;
using piiii = std::tuple <int, int, int, int>;
using pll = std::pair <ll, ll>;
using plll = std::tuple <ll, ll, ll>;
using pllll = std::tuple <ll, ll, ll, ll>;
// using Mint = Mod<int, UNDEFINED>;

//
// Created by  on 2022/2/6.
//

#ifndef WORKSPACE_SEGMENTZKW_H
#define WORKSPACE_SEGMENTZKW_H

#include <bits/stdc++.h>

namespace Seg{
    using T = pii;

    class Seg{
#define ls(u) ((u) << 1)
#define rs(u) (((u) << 1) | 1)
    public:
        int maximum;
        std::vector <T> seg;

        explicit Seg(int range):seg(){
            maximum = 1;
            while (maximum <= range + 10){
                maximum <<= 1;
            }
            seg.resize(maximum << 1);
            init();
        }

        void init(){
            for (int i = maximum - 1; i; -- i){
                pull(i);
            }
        }

        T merge(const T &t1, const T &t2){
            return std::min(t1, t2);
        }

        void pull(int sit){
            seg[sit] = merge(seg[ls(sit)], seg[rs(sit)]);
        }

        T query(int l, int r){
            T ret = {INT_MAX, INT_MAX};
            for (l += maximum, r += maximum + 1; l < r; l >>= 1, r >>= 1){
                if (l & 1) ret = merge(ret, seg[l ++]);
                if (r & 1) ret = merge(ret, seg[-- r]);
            }
            return ret;
        }
    };
}

#endif //WORKSPACE_SEGMENTZKW_H

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
        }
        Seg::Seg seg1(n), seg2(n);
        for (int i = 1; i <= n; ++ i){
            seg1.seg[seg1.maximum + i] = {a[i], i};
            seg2.seg[seg2.maximum + i] = {-a[i], i};
        }
        seg1.init();
        seg2.init();
        std::function <int(int, int)> dfs = [&](int l, int r)-> int{
            if (l == r){
                return 0;
            }
            pii max = seg1.query(l, r);
            pii min = seg2.query(l, r);
            int l1 = max.second, r1 = min.second;
            if (l1 > r1){
                std::swap(l1, r1);
            }
            return dfs(l, l1) + 1 + dfs(r1, r);
        };
        std::cout << dfs(1, n) << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    std::cin >> test;
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18);
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H
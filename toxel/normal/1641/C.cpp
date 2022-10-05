//
// Created by  on 2022/2/23.
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
// Created by  on 2022/2/6.
//

#ifndef WORKSPACE_SEGMENTZKW_H
#define WORKSPACE_SEGMENTZKW_H

#include <bits/stdc++.h>

const int INF = 1e9;

namespace Seg{
    using T = int;

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
            for (int i = maximum; i < maximum + maximum; ++ i){
                seg[i] = T{INF};
            }
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

        void add(int sit, T value){
            sit += maximum;
            seg[sit] = merge(seg[sit], value);
            for (sit >>= 1; sit; sit >>= 1){
                pull(sit);
            }
        }

        T query(int l, int r){
            T ret = INF;
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
        int n, q;
        std::cin >> n >> q;
        std::set <int> unknown;
        for (int i = 1; i <= n; ++ i){
            unknown.emplace(i);
        }
        Seg::Seg seg(n);
        while (q --){
            int type;
            std::cin >> type;
            if (type == 0){
                int l, r, x;
                std::cin >> l >> r >> x;
                if (x == 0){
                    auto u = unknown.lower_bound(l);
                    while (u != unknown.end() && *u <= r){
                        u = unknown.erase(u);
                    }
                }
                else{
                    seg.add(l, r);
                }
            }
            else{
                int id;
                std::cin >> id;
                if (!unknown.count(id)){
                    std::cout << "NO\n";
                    continue;
                }
                auto u = unknown.find(id);
                int l, r;
                if (u == unknown.begin()){
                    l = 1;
                }
                else{
                    l = *std::prev(u) + 1;
                }
                if (std::next(u) == unknown.end()){
                    r = n;
                }
                else{
                    r = *std::next(u) - 1;
                }
                if (seg.query(l, id) <= r){
                    std::cout << "YES\n";
                }
                else{
                    std::cout << "N/A\n";
                }
            }
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H
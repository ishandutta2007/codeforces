//
// Created by  on 2022/5/20.
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
// using Mint = Mod<int, UNDEFINED>;

//
// Created by  on 2022/2/6.
//

#ifndef WORKSPACE_SEGMENTZKW_H
#define WORKSPACE_SEGMENTZKW_H

#include <bits/stdc++.h>

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
                seg[i] = T{1'000'000'000};
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
            seg[sit] = value;
            for (sit >>= 1; sit; sit >>= 1){
                pull(sit);
            }
        }

        T query(int l, int r){
            T ret = INT_MAX;
            for (l += maximum, r += maximum + 1; l < r; l >>= 1, r >>= 1){
                if (l & 1) ret = merge(ret, seg[l ++]);
                if (r & 1) ret = merge(ret, seg[-- r]);
            }
            return ret;
        }
    };
}

#endif //WORKSPACE_SEGMENTZKW_H

const int N = 200010;

std::vector <int> vec[N];
std::vector <pii> vec1[N];

class Solver{
public:
    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <int> a(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
        }
        std::vector <int> left(n + 1), right(n + 1);
        std::map <int, int> map;
        std::map <int, std::vector <int>> map1;
        for (int i = 1; i <= n; ++ i){
            if (map.count(a[i])){
                left[i] = map[a[i]];
                right[map[a[i]]] = i;
            }
            map1[a[i]].emplace_back(i);
            map[a[i]] = i;
        }
        std::vector <pii> query(m);
        for (int i = 0; i < m; ++ i){
            std::cin >> query[i].first >> query[i].second;
        }
        for (int i = 0; i <= n; ++ i){
            vec[i].clear();
        }
        for (int i = 0; i < m; ++ i){
            auto [l, r] = query[i];
            vec[l].emplace_back(i);
        }
        Seg::Seg seg(n);
        int leftmost = INT_MAX;
        for (int i = n; i >= 1; -- i){
            if (right[i]){
                seg.add(right[i], right[i]);
            }
            for (auto id: vec[i]){
                auto [l, r] = query[id];
                int x = seg.query(l, r);
                if (x != 1'000'000'000){
                    leftmost = std::min(leftmost, x);
                }
            }
        }
        if (leftmost == INT_MAX){
            std::cout << "0\n";
            return;
        }
        for (int i = 0; i <= n; ++ i){
            vec[i].clear();
        }
        for (int i = 0; i < m; ++ i){
            auto [l, r] = query[i];
            vec[r].emplace_back(i);
        }
        seg = Seg::Seg(n);
        int rightmost = 0;
        for (int i = 1; i <= n; ++ i){
            if (left[i]){
                seg.add(left[i], n + 1 - left[i]);
            }
            for (auto id: vec[i]){
                auto [l, r] = query[id];
                int x = seg.query(l, r);
                if (x != 1'000'000'000){
                    rightmost = std::max(rightmost, n + 1 - x);
                }
            }
        }
        for (int i = 0; i <= n; ++ i){
            vec1[i].clear();
        }
        for (int i = 0; i < m; ++ i){
            auto [l, r] = query[i];
            vec1[l].emplace_back(i, 1);
            vec1[r + 1].emplace_back(i, -1);
        }
        std::multiset <int> set;
        std::vector <int> least(n + 1);
        for (int i = 1; i <= n; ++ i){
            for (auto [id, type]: vec1[i]){
                int r = query[id].second;
                if (type == 1){
                    set.emplace(r);
                }
                else{
                    set.erase(set.find(r));
                }
            }
            if (!set.empty()){
                int last = *std::prev(set.end());
                auto &vec2 = map1[a[i]];
                if (vec2.empty()){
                    continue;
                }
                auto u = std::upper_bound(vec2.begin(), vec2.end(), last);
                if (u == vec2.begin()){
                    continue;
                }
                int bad = *std::prev(u);
                if (bad <= i){
                    continue;
                }
                least[i] = bad;
            }
        }
        int ans = INT_MAX;
        int cur_least = 0;
        for (int i = 1; i <= n; ++ i){
            if (i > leftmost){
                break;
            }
            int pos = std::max(cur_least, rightmost);
            pos = std::max(pos, i);
            if (pos < n + 1){
                ans = std::min(ans, pos - i + 1);
            }
            cur_least = std::max(cur_least, least[i]);
        }
        std::cout << ans << '\n';
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
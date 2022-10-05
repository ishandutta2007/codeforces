//
// Created by  on 2022/3/7.
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
// Created by  on 2022/1/31.
//

#ifndef WORKSPACE_SEGMENTRANGE_H
#define WORKSPACE_SEGMENTRANGE_H

#include <bits/stdc++.h>

namespace Seg{
    using T = ll;

    class Node{
    public:
        T value;
        T lazy;

        Node():value(), lazy(){}
        Node(T value, T lazy):value(value), lazy(lazy){}
    };

    class Seg{
#define ls(u) ((u) << 1)
#define rs(u) (((u) << 1) | 1)
// #define OPERATE +
    public:
        int maximum;
        std::vector <Node> seg;

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

        void update(int sit, T value){
            seg[sit].value += value;
            seg[sit].lazy += value;
        }

        void push(int sit){
            if (seg[sit].lazy == 0){
                return;
            }
            update(ls(sit), seg[sit].lazy);
            update(rs(sit), seg[sit].lazy);
            seg[sit].lazy = 0;
        }

        void pull(int sit){
            seg[sit].value = std::max(seg[ls(sit)].value, seg[rs(sit)].value);
        }

        void add(int sit, int l, int r, int ql, int qr, T value){
            if (ql > r || qr < l){
                return;
            }
            if (ql <= l && qr >= r){
                update(sit, value);
                return;
            }
            push(sit);
            int mid = (l + r) / 2;
            add(ls(sit), l, mid, ql, qr, value);
            add(rs(sit), mid + 1, r, ql, qr, value);
            pull(sit);
        }

        void add(int l, int r, T value){
            add(1, 0, maximum - 1, l, r, value);
        }

        T query(int sit, int l, int r, int ql, int qr){
            if (ql > r || qr < l){
                return LLONG_MIN;
            }
            if (ql <= l && qr >= r){
                return seg[sit].value;
            }
            push(sit);
            int mid = (l + r) / 2;
            return std::max(query(ls(sit), l, mid, ql, qr),
                    query(rs(sit), mid + 1, r, ql, qr));
        }

        T query(int l, int r){
            return query(1, 0, maximum - 1, l, r);
        }
    };
}

#endif //WORKSPACE_SEGMENTRANGE_H

const int N = 500010;

std::vector <pii> vec[N], event[N];

class Solver{
public:
    void solve(){
        int n, q;
        std::cin >> n >> q;
        std::vector <ll> a[3];
        for (int i = 0; i < 3; ++ i){
            a[i].resize(n + 1);
            for (int j = 1; j <= n; ++ j){
                std::cin >> a[i][j];
                a[i][j] += a[i][j - 1];
            }
        }
        std::vector <ll> value(n + 1), dp(n + 1);
        for (int i = 1; i <= n; ++ i){
            value[i] = a[1][i] + a[2][n] - a[2][i - 1];
        }
        std::vector <int> l(q), r(q), w(q);
        for (int i = 0; i < q; ++ i){
            std::cin >> l[i] >> r[i] >> w[i];
            vec[l[i]].emplace_back(r[i], w[i]);
            event[r[i]].emplace_back(i, 1);
            event[l[i]].emplace_back(i, -1);
        }
        Seg::Seg seg(n);
        for (int i = 1; i <= n; ++ i){
            seg.seg[i + seg.maximum] = {value[i], 0};
        }
        seg.init();
        const ll INF = 1e18;
        seg.add(1, n, -INF);
        std::set <plll> set;
        set.emplace(INF, 1, n);
        for (int i = 1; i <= n; ++ i){
            for (auto [r, w]: vec[i]){
                auto it = set.lower_bound({w, INF, INF});
                if (it == set.end()){
                    continue;
                }
                int first_l = std::get <1>(*it);
                if (r < first_l){
                    continue;
                }
                std::vector <plll> to_push;
                to_push.emplace_back(w, first_l, r);
                while (it != set.end() && r >= std::get <1>(*it)){
                    auto [w1, l1, r1] = *it;
                    if (r < r1){
                        to_push.emplace_back(w1, r + 1, r1);
                        int r2 = std::min(r, int(r1));
                        seg.add(l1, r2, w1 - w);
                        set.erase(it);
                        break;
                    }
                    seg.add(l1, r1, w1 - w);
                    it = set.erase(it);
                }
                for (auto u : to_push){
                    set.emplace(u);
                }
            }
            dp[i] = seg.query(i, n);
        }
        std::multiset <ll> values;
        for (int i = n; i >= 1; -- i){
            for (auto [id, type]: event[i]){
                if (type == 1){
                    if (r[id] < n){
                        values.emplace(dp[r[id] + 1] - w[id]);
                    }
                }
            }
            if (!values.empty()){
                dp[i] = std::max(dp[i], *std::prev(values.end()));
            }
            for (auto [id, type]: event[i]){
                if (type == -1){
                    if (r[id] < n){
                        auto u = values.find(dp[r[id] + 1] - w[id]);
                        values.erase(u);
                    }
                }
            }
        }
        ll ans = -INF;
        for (int i = 1; i <= n; ++ i){
            ans = std::max(ans, dp[i] - a[1][i - 1] + a[0][i]);
        }
        std::cout << ans << '\n';
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
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H
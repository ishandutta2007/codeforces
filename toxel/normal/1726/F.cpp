//
// Created by  on 2022/9/6.
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
// Created by  on 2022/1/31.
//

#ifndef WORKSPACE_SEGMENTRANGE_H
#define WORKSPACE_SEGMENTRANGE_H

#include <bits/stdc++.h>

namespace Seg{
    using T = int;

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
            for (int i = maximum; i < maximum + maximum; ++ i){
                seg[i] = Node();
            }
            for (int i = maximum - 1; i; -- i){
                pull(i);
            }
        }

        void update(int sit, T value){
            seg[sit].value = std::max(seg[sit].value, value);
            seg[sit].lazy = std::max(seg[sit].lazy, value);
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
                return 0;
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



#include <bits/stdc++.h>

template <typename T>
class Discretization{
public:
    std::vector <T> c;

    void add(T x){
        c.emplace_back(x);
    }

    void add(T l, T r){
        c.emplace_back(l);
        c.emplace_back(r + 1);
    }

    void process(){
        std::sort(c.begin(), c.end());
        c.erase(std::unique(c.begin(), c.end()), c.end());
    }

    int get(T x){
        return std::lower_bound(c.begin(), c.end(), x) - c.begin();
    }

    T get_v(int pos){
        return c[pos];
    }
};


class Solver{
public:
    void solve(){
        int n, t;
        std::cin >> n >> t;
        std::vector <ll> g(n), c(n), d(n), cur(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> g[i] >> c[i];
        }
        for (int i = 1; i < n; ++ i){
            std::cin >> d[i];
            d[i] += d[i - 1];
        }
        std::vector <std::pair <pii, pii>> events(n);
        Discretization <ll> dis;
        for (int i = 0; i < n; ++ i){
            cur[i] = (c[i] + d[i]) % t;
            if (cur[i] < g[i]){
                events[i].first = {g[i] - cur[i], g[i] - cur[i] + t - g[i]};
                dis.add(events[i].first.first);
                dis.add(events[i].first.second);
            }
            else{
                events[i].first = {0, t - cur[i]};
                events[i].second = {t - (cur[i] - g[i]), t};
                dis.add(events[i].first.first);
                dis.add(events[i].first.second);
                dis.add(events[i].second.first);
                dis.add(events[i].second.second);
            }
        }
        dis.add(0);
        dis.add(t);
        dis.process();
        Seg::Seg seg(dis.c.size());
        std::vector <ll> next(n), dis_next(n), dis_all(n);
        for (int i = n - 1; i >= 0; -- i){
            int now = (t - cur[i]) % t;
            int pos = dis.get(now);
            next[i] = n - seg.query(pos, pos);
            if (next[i] == n){
                dis_next[i] = dis_all[i] = d[n - 1] - d[i];
            }
            else{
                dis_next[i] = d[next[i]] - d[i] + (t + (t - cur[next[i]]) - now) % t;
                dis_all[i] = dis_all[next[i]] + dis_next[i];
            }
            auto add = [&](ll l, ll r){
                l = dis.get(l);
                r = dis.get(r);
                if (l >= r){
                    return;
                }
                seg.add(l, r - 1, n - i);
            };
            if (cur[i] < g[i]){
                add(events[i].first.first, events[i].first.second);
            }
            else{
                add(events[i].first.first, events[i].first.second);
                add(events[i].second.first, events[i].second.second);
            }
        }
        ll ans = LLONG_MAX;
        for (int i = 0; i < int(dis.c.size()) - 1; ++ i){
            int nxt = n - seg.query(i, i);
            if (nxt == 0){
                continue;
            }
            if (nxt == n){
                ans = std::min(ans, d[n - 1]);
            }
            else{
                int wait = (t + (t - cur[nxt]) - (dis.get_v(i + 1) - 1)) % t;
                ans = std::min(ans, d[nxt] + dis_all[nxt] + wait);
            }
        }
        std::cout << ans << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18);
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H
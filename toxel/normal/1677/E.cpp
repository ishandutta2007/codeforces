//
// Created by  on 2022/5/8.
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


#include <bits/stdc++.h>

template <typename T, bool MAX>
class Stack{
private:
    std::vector <T> a;

    void calculate_min(){
        int n = a.size();
        std::vector <int> stack;
        for (int i = 0; i < n; ++ i){
            while (!stack.empty() && a[stack.back()] > a[i]){
                r[stack.back()] = i;
                stack.pop_back();
            }
            if (!stack.empty()){
                l[i] = stack.back();
            }
            stack.emplace_back(i);
        }
    }

    void calculate_max(){
        int n = a.size();
        std::vector <int> stack;
        for (int i = 0; i < n; ++ i){
            while (!stack.empty() && a[stack.back()] < a[i]){
                r[stack.back()] = i;
                stack.pop_back();
            }
            if (!stack.empty()){
                l[i] = stack.back();
            }
            stack.emplace_back(i);
        }
    }

public:
    std::vector <int> l, r;

    explicit Stack(const std::vector <T> &el):a(), l(), r(){
        int n = el.size();
        a = el;
        l.resize(n, -1);
        r.resize(n, n);
        for (int i = 0; i < n; ++ i){
            a[i] = el[i];
        }
        if constexpr (MAX){
            calculate_max();
        }
        else{
            calculate_min();
        }
    }
};



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


const int N = 200010;

std::vector <int> fact[N];
std::vector <piii> event[N];
std::vector <piiii> query[N];

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
            for (int i = maximum; i < maximum + maximum; ++ i){
                seg[i] = Node();
            }
            for (int i = maximum - 1; i; -- i){
                pull(i);
            }
        }

        void update(int sit, T value, int l, int r){
            seg[sit].value += value * (r - l + 1);
            seg[sit].lazy += value;
        }

        void push(int sit, int l, int r){
            if (seg[sit].lazy == 0){
                return;
            }
            int mid = (l + r) / 2;
            update(ls(sit), seg[sit].lazy, l, mid);
            update(rs(sit), seg[sit].lazy, l, mid);
            seg[sit].lazy = 0;
        }

        void pull(int sit){
            seg[sit].value = seg[ls(sit)].value + seg[rs(sit)].value;
        }

        void add(int sit, int l, int r, int ql, int qr, T value){
            if (ql > r || qr < l){
                return;
            }
            if (ql <= l && qr >= r){
                update(sit, value, l, r);
                return;
            }
            push(sit, l, r);
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
            push(sit, l, r);
            int mid = (l + r) / 2;
            return query(ls(sit), l, mid, ql, qr) +
                    query(rs(sit), mid + 1, r, ql, qr);
        }

        T query(int l, int r){
            return query(1, 0, maximum - 1, l, r);
        }
    };
}

#endif //WORKSPACE_SEGMENTRANGE_H

const int M = 170;

int vis[M][M];

class Solver{
public:
    void solve(){
        int n, q;
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++ i){
            for (int j = i; j <= n; j += i){
                fact[j].emplace_back(i);
            }
        }
        std::vector <int> p(n + 1), inv(n + 1);
        p[0] = INT_MAX;
        for (int i = 1; i <= n; ++ i){
            std::cin >> p[i];
            inv[p[i]] = i;
        }
        Stack <int, true> stack(p);
        for (int i = 1; i <= n; ++ i){
            int l = stack.l[i] + 1, r = stack.r[i] - 1;
            std::vector <piiii> rect;
            for (auto u: fact[p[i]]){
                if (1ll * u * u >= p[i]){
                    break;
                }
                int pos1 = inv[u], pos2 = inv[p[i] / u];
                if (pos1 < l || pos1 > r){
                    continue;
                }
                if (pos2 < l || pos2 > r){
                    continue;
                }
                if (pos1 > pos2){
                    std::swap(pos1, pos2);
                }
                if (pos1 <= i && pos2 >= i){
                    rect.emplace_back(l, pos1, pos2, r);
                }
                else if (pos2 <= i){
                    rect.emplace_back(l, pos1, i, r);
                }
                else{
                    rect.emplace_back(l, i, pos2, r);
                }
            }
            Discretization <int> d1, d2;
            for (auto [l1, l2, r1, r2]: rect){
                d1.add(l1, l2);
                d2.add(r1, r2);
            }
            d1.process(), d2.process();
            int sz1 = d1.c.size(), sz2 = d2.c.size();
            for (int j = 0; j < sz1; ++ j){
                for (int k = 0; k < sz2; ++ k){
                    vis[j][k] = 0;
                }
            }
            for (auto [l1, l2, r1, r2]: rect){
                l1 = d1.get(l1);
                l2 = d1.get(l2 + 1);
                r1 = d2.get(r1);
                r2 = d2.get(r2 + 1);
                ++ vis[l1][r1];
                -- vis[l1][r2];
                -- vis[l2][r1];
                ++ vis[l2][r2];
            }
            for (int j = 1; j < sz1; ++ j){
                for (int k = 0; k < sz2; ++ k){
                    vis[j][k] += vis[j - 1][k];
                }
            }
            for (int j = 0; j < sz1; ++ j){
                for (int k = 1; k < sz2; ++ k){
                    vis[j][k] += vis[j][k - 1];
                }
            }
            for (int j = 0; j < sz1 - 1; ++ j){
                for (int k = 0; k < sz2 - 1; ++ k){
                    if (vis[j][k]){
                        int l1 = d1.get_v(j);
                        int l2 = d1.get_v(j + 1);
                        int r1 = d2.get_v(k);
                        int r2 = d2.get_v(k + 1);
                        event[l1].emplace_back(r1, r2 - 1, 1);
                        event[l2].emplace_back(r1, r2 - 1, -1);
                    }
                }
            }
        }
        std::vector <ll> ans(q);
        for (int i = 0; i < q; ++ i){
            int l, r;
            std::cin >> l >> r;
            query[l - 1].emplace_back(l, r, -1, i);
            query[r].emplace_back(l, r, 1, i);
        }
        Seg::Seg seg(n), seg1(n);
        for (int i = 0; i <= n; ++ i){
            for (auto [l, r, dir]: event[i]){
                seg.add(l, r, dir);
                seg1.add(l, r, -dir * (i - 1));
                // std::cout << l << " " << r << " " << seg.query(l, r) << " " << seg1.query(l, r) << '\n';
            }
            for (auto [l, r, dir, id]: query[i]){
                ll val = i * seg.query(l, r) + seg1.query(l, r);
                // std::cout << id << " " << l << " " << r << " " << seg.query(l, r) << " " << seg1.query(l, r) << '\n';
                ans[id] += dir * val;
            }
        }
        for (int i = 0; i < q; ++ i){
            std::cout << ans[i] << "\n";
        }
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
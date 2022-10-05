//
// Created by  on 2022/5/31.
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


//
// Created by  on 2022/2/6.
//

#ifndef WORKSPACE_SEGMENTZKW_H
#define WORKSPACE_SEGMENTZKW_H

#include <bits/stdc++.h>

namespace Seg{
    using T = ll;

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
                seg[i] = T{};
            }
            for (int i = maximum - 1; i; -- i){
                pull(i);
            }
        }

        T merge(const T &t1, const T &t2){
            return std::max(t1, t2);
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
            T ret = LLONG_MIN;
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
        std::vector <ll> a(n), pre(n + 1);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
            pre[i + 1] = pre[i] + a[i];
        }
        Stack <ll, true> stack(a);
        Seg::Seg seg(n), seg1(n);
        for (int i = 0; i <= n; ++ i){
            seg.add(i, pre[i]);
            seg1.add(i, -pre[i]);
        }
        for (int i = 0; i < n; ++ i){
            int l = stack.l[i] + 1, r = stack.r[i] - 1;
            if (seg.query(i + 1, r + 1) + seg1.query(l, i) > a[i]){
                std::cout << "NO\n";
                return;
            }
        }
        std::cout << "YES\n";
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
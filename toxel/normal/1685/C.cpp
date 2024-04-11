//
// Created by  on 2022/5/26.
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

        T query(int l, int r){
            T ret = INT_MIN;
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
        std::string s;
        std::cin >> n >> s;
        std::vector <int> pre(2 * n + 1);
        for (int i = 0; i < 2 * n; ++ i){
            pre[i + 1] = pre[i] + (s[i] == '(' ? 1 : -1);
        }
        if (*std::min_element(pre.begin(), pre.end()) >= 0){
            std::cout << "0\n";
            return;
        }
        int first = INT_MAX, last = -1;
        for (int i = 0; i <= 2 * n; ++ i){
            if (pre[i] < 0){
                first = std::min(first, i);
                last = std::max(last, i);
            }
        }
        Stack <int, true> stack(pre);
        Seg::Seg seg(2 * n + 1);
        for (int i = 0; i <= 2 * n; ++ i){
            seg.seg[i + seg.maximum] = pre[i];
        }
        seg.init();
        for (int i = 0; i <= 2 * n; ++ i){
            int l = stack.l[i] + 1, r = stack.r[i] - 1;
            if (l > first){
                continue;
            }
            if (r < last){
                continue;
            }
            int v1 = seg.query(l - 1, first - 1);
            int v2 = seg.query(last, r);
            if (v1 + v2 >= pre[i]){
                std::cout << "1\n";
                int l1 = -1, r1 = -1;
                for (int j = l - 1; j <= first - 1; ++ j){
                    if (v1 == pre[j]){
                        l1 = j;
                        break;
                    }
                }
                for (int j = last; j <= r; ++ j){
                    if (v2 == pre[j]){
                        r1 = j;
                        break;
                    }
                }
                std::cout << l1 + 1 << " " << r1 << "\n";
                return;
            }
        }
        std::reverse(s.begin(), s.end());
        for (int i = 0; i < 2 * n; ++ i){
            pre[i + 1] = pre[i] + (s[i] == '(' ? 1 : -1);
        }
        int pos = std::min_element(pre.begin(), pre.end()) - pre.begin();
        std::cout << "2\n";
        int right = pos, left = 2 * n - pos;
        std::cout << 1 << " " << left << "\n";
        std::cout << left + 1 << " " << 2 * n << "\n";
        /*for (int _ = 0; _ < 2; ++ _){
            int pos = -1;
            for (int i = 0; i < 2 * n; ++ i){
                pre[i + 1] = pre[i] + (s[i] == '(' ? 1 : -1);
                if (pos == -1 && pre[i] < 0){
                    pos = i - 1;
                }
                std::cout << pre[i] << " \n"[i == 2 * n - 1];
            }
            if (pos == -1){
                break;
            }
            int last = *std::max_element(pre.begin(), pre.end());
            for (int i = 2 * n; i >= 0; -- i){
                if (pre[i] == last){
                    last = i - 1;
                    break;
                }
            }
            ans.emplace_back(pos + 1, last);
            std::reverse(s.begin() + pos, s.begin() + last);
        }
        for (int i = 0; i < 2 * n; ++ i){
            pre[i + 1] = pre[i] + (s[i] == '(' ? 1 : -1);
            // assert(pre[i] >= 0);
        }
        std::cout << ans.size() << "\n";
        for (auto [l, r]: ans){
            std::cout << l << " " << r << "\n";
        }*/
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
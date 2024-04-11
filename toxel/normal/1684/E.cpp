//
// Created by  on 2022/5/19.
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

template <typename T>
class BIT{
public:
    int sz;
    std::vector <T> vec;
    T sum;

    BIT(int size):sz(size + 10), vec(sz + 10), sum(0){}

    void add(int sit, T value){
        sum += value;
        for (sit += 1; sit < sz; sit += sit & -sit){
            vec[sit] += value;
        }
    }

    T query(int sit){
        T ret = 0;
        for (sit += 1; sit; sit -= sit & -sit){
            ret += vec[sit];
        }
        return ret;
    }

    T query_up(int sit){
        return sum - query(sit - 1);
    }

    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};


class Solver{
public:
    void solve(){
        int n, k;
        std::cin >> n >> k;
        std::vector <int> a(n);
        std::map <int, int> map;
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
            ++ map[a[i]];
        }
        int ans = INT_MAX;
        int zero = 0, sum = 0;
        BIT <ll> bit1(n), bit2(n);
        for (auto [u, v]: map){
            bit1.add(v, 1);
            bit2.add(v, v);
        }
        int base = 0;
        for (int i = 0; i <= n; ++ i){
            int num = map.count(i) ? map[i] : 0;
            if (num != 0){
                bit1.add(num, -1);
                bit2.add(num, -num);
            }
            if (num <= k && zero <= k && n - sum + base >= zero){
                int k_left = k - num;
                int l = 1, r = n;
                while (l < r){
                    int mid = (l + r) / 2;
                    if (bit2.query(mid) <= k_left){
                        l = mid + 1;
                    }
                    else{
                        r = mid;
                    }
                }
                int left = bit1.query_up(l);
                k_left -= bit2.query(l - 1);
                left -= std::min(ll(k_left) / l, bit1.query(l) - bit1.query(l - 1));
                ans = std::min(ans, left);
            }
            if (num == 0){
                ++ zero;
            }
            else{
                base += num - 1;
            }
            sum += num;
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
//
// Created by  on 2022/3/4.
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

class Solver{
public:
    std::vector <int> ans;
    std::vector <int> a;

    void op(int pos){
        a[pos] = a[pos + 1] = a[pos + 2] = (a[pos] ^ a[pos + 1] ^ a[pos + 2]);
        ans.emplace_back(pos);
    }

    void solve(){
        int n;
        std::cin >> n;
        a.resize(n);
        int sum = 0;
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
            sum += a[i];
        }
        if (sum % 2 == 1){
            std::cout << "NO\n";
            return;
        }
        if (sum == n){
            std::cout << "NO\n";
            return;
        }
        if (a.front() == 1 && a.back() == 1){
            std::vector <int> seg;
            int cur = -1;
            for (int i = 0; i < n; ++ i){
                if (i == n - 1 || a[i] != a[i + 1]){
                    seg.emplace_back(i - cur);
                    cur = i;
                }
            }
            if (seg.front() % 2 == 1 && seg.back() % 2 == 1){
                int first_odd = -1;
                for (int i = 1; i < int(seg.size()) - 1; ++ i){
                    if (seg[i] % 2 == 1){
                        first_odd = i;
                        break;
                    }
                }
                if (first_odd == -1){
                    std::cout << "NO\n";
                    return;
                }
                int tot = 0;
                for (int i = 0; i <= first_odd; ++ i){
                    if (i % 2 == 1){
                        for (int j = 0; j < seg[i]; j += 2){
                            op(tot + j - 1);
                        }
                    }
                    tot += seg[i];
                }
                int first_zero = -1;
                for (int i = 0; i < n; ++ i){
                    if (a[i] == 0){
                        first_zero = i;
                        break;
                    }
                }
                assert(first_zero % 2 == 0);
                for (int i = first_zero - 2; i >= 0; i -= 2){
                    op(i);
                }
            }
            else if (seg.back() % 2 == 0){
                for (int i = n - 1 - seg.back(); i <= n - 3; i += 2){
                    op(i);
                }
            }
            else{
                for (int i = seg.front() - 2; i >= 0; i -= 2){
                    op(i);
                }
            }
        }
        if (a[0] == 0){
            for (int i = 0; i < n - 1; ++ i){
                if (a[i + 1] == 1){
                    if (a[i + 2] == 1){
                        op(i);
                    }
                    else if (a[i + 3] == 1){
                        op(i + 1);
                    }
                    else{
                        op(i + 1);
                        op(i);
                    }
                }
            }
        }
        else{
            // a[n - 1] == 1
            for (int i = n - 1; i > 0; -- i){
                if (a[i - 1] == 1){
                    if (a[i - 2] == 1){
                        op(i - 2);
                    }
                    else if (a[i - 3] == 1){
                        op(i - 3);
                    }
                    else{
                        op(i - 3);
                        op(i - 2);
                    }
                }
            }
        }
        for (int i = 0; i < n; ++ i){
            assert(a[i] == 0);
        }
        int sz = ans.size();
        std::cout << "YES\n" << sz << "\n";
        for (int i = 0; i < sz; ++ i){
            std::cout << ans[i] + 1 << " \n"[i == sz - 1];
        }
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
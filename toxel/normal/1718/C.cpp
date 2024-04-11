//
// Created by  on 2022/8/16.
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

const int N = 200010;
const int BOUND = 0;

std::vector <ll> vec[N];
std::multiset <ll> set[N];

class Solver{
public:
    int n, q;
    std::vector <int> factor;

    ll query(){
        ll ans = 0;
        for (auto u : factor){
            if (n / u > BOUND){
                ans = std::max(ans, n / u * *std::prev(set[u].end()));
            }
            else{
                ll max = *std::max_element(vec[u].begin(), vec[u].end());
                ans = std::max(ans, n / u * max);
            }
        }
        return ans;
    }

    void solve(){
        std::cin >> n >> q;
        for (int i = 0; i <= n + 1; ++ i){
            std::vector <ll>().swap(vec[i]);
            std::multiset <ll>().swap(set[i]);
        }
        std::vector <int> a(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
        }
        int x = n;
        for (int i = 2; i <= x; ++ i){
            if (x % i == 0){
                factor.emplace_back(i);
                while (x % i == 0){
                    x /= i;
                }
            }
        }
        for (auto u : factor){
            for (int i = 0; i < n / u; ++ i){
                ll sum = 0;
                for (int j = i; j < n; j += n / u){
                    sum += a[j];
                }
                vec[u].emplace_back(sum);
                if (n / u > BOUND){
                    set[u].emplace(sum);
                }
            }
        }
        std::cout << query() << '\n';
        while (q --){
            int p, x;
            std::cin >> p >> x;
            -- p;
            int diff = x - a[p];
            a[p] = x;
            for (auto u : factor){
                int pos = p % (n / u);
                if (n / u > BOUND){
                    ll prev = vec[u][pos];
                    vec[u][pos] += diff;
                    set[u].erase(set[u].find(prev));
                    set[u].emplace(vec[u][pos]);
                }
                else{
                    vec[u][pos] += diff;
                }
            }
            std::cout << query() << '\n';
        }
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
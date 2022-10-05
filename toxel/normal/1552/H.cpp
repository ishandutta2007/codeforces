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

const int DIM = 200;

std::map <int, int> cache;

int ask(int x){
    if (cache.count(x)){
        return cache[x];
    }
    std::vector <int> vec;
    for (int i = 1; i <= DIM; ++ i){
        if (i % x){
            continue;
        }
        for (int j = 1; j <= DIM; ++ j){
            vec.emplace_back(i);
            vec.emplace_back(j);
        }
    }
    int sz = vec.size();
    std::cout << "? " << sz / 2 << '\n';
    for (int i = 0; i < sz; ++ i){
        std::cout << vec[i] << " \n"[i == sz - 1];
    }
    std::cout.flush();
    int ans;
    std::cin >> ans;
    return cache[x] = ans;
}

void solve(){
    int area = ask(1);
    int cur = 0;
    for (int i = 2; i >= 0; -- i){
        int temp = cur | (1 << i);
        if (ask(1 << temp) << temp == area){
            cur = temp;
        }
    }
    if (cur == 7){ // must be 128
        std::cout << "! " << ((1 << 7) - 1 + (area >> 7) - 1) * 2 << '\n';
    }
    else{
        int temp = ask(1 << (cur + 1));
        temp = std::abs(2 * temp - (area >> cur));
        std::cout << "! " << (temp - 1 + area / temp - 1) * 2 << '\n';
    }
}

/*const int N = 210;
const int M = N * N;

template <typename T>
constexpr bool is_prime(T n){
    if (n <= 1){
        return false;
    }
    for (T i = 2; i * i <= n; ++ i){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

std::vector <int> vec[M];
bool prime[M];

void solve(){
    for (int i = 2; i <= 200; ++ i){
        for (int j = 2; j <= 200; ++ j){
            vec[i * j].emplace_back(i);
        }
    }
    int max = 0, id = -1;
    for (int i = 0; i < M; ++ i){
        if (vec[i].size() > max){
            max = vec[i].size();
            id = i;
        }
    }
    std::cout << max << ' ' << id << '\n';
    for (int i = 2; i < M; ++ i){
        prime[i] = is_prime(i);
    }
    std::map <int, std::vector <int>> map;
    int MOD = 11;
    for (auto u : vec[2520]){
        int j = 2520 / u;
        map[u / MOD * j].emplace_back(u);
        if (u % MOD){
            map[(u / MOD + 1) * j].emplace_back(u);
        }
    }
    for (const auto &[k, v]: map){
        std::cout << k;
        for (auto w: v){
            std::cout << ' ' << w;
        }
        std::cout << '\n';
    }
    std::vector <int> vec1 = map[240];
    map.clear();
    MOD = 13;
    for (auto u : vec1){
        int j = 2520 / u;
        map[j / MOD * u].emplace_back(u);
        if (j % MOD){
            map[(j / MOD + 1) * u].emplace_back(u);
        }
    }
    std::cout << "--------------------------\n";
    for (const auto &[k, v]: map){
        std::cout << k;
        for (auto w: v){
            std::cout << ' ' << w;
        }
        std::cout << '\n';
    }
}*/

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H
//
// Created by  on 2022/3/26.
//

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_TEMPLATE_H
#define WORKSPACE_TEMPLATE_H

#include <bits/stdc++.h>
#define mp std::make_pair
// #define scanf dont_use_scanf
// #define printf dont_use_printf
// #define puts dont_use_puts
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
// Created by  on 2022/1/9.
//

#ifndef WORKSPACE_PRIME_H
#define WORKSPACE_PRIME_H

namespace Prime {
    std::vector<int> min, prime;

    std::vector <int> mu, phi, cnt, power, sigma;

    void init(int n) {
        int N = n + 10;
        min.resize(N);
        mu.resize(N);
        phi.resize(N);
        cnt.resize(N);
        power.resize(N);
        sigma.resize(N);
        mu[1] = phi[1] = sigma[1] = 1;

        for (int i = 2; i < N; ++i) {
            if (!min[i]) {
                min[i] = i;
                prime.push_back(i);

                mu[i] = -1;
                phi[i] = i - 1;
                cnt[i] = 1;
                power[i] = i;
                sigma[i] = i + 1;
            }
            for (auto u : prime) {
                if (i * u >= N) {
                    break;
                }
                min[i * u] = u;
                if (i % u == 0) {
                    mu[i * u] = 0;
                    phi[i * u] = phi[i] * u;
                    cnt[i * u] = cnt[i] + 1;
                    power[i * u] = power[i] * u;
                    sigma[i * u] = sigma[i / power[i]] * power[i * u] + sigma[i];

                    break;
                }

                mu[i * u] = -mu[i];
                phi[i * u] = phi[i] * (u - 1);
                cnt[i * u] = 1;
                power[i * u] = u;
                sigma[i * u] = sigma[i] * (u + 1);
            }
        }
    }
}

#endif //WORKSPACE_PRIME_H

template <typename T>
void read(T &n){
    char ch;
    while (!std::isdigit(ch = getchar()))
        ;
    n = ch - '0';
    while (std::isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
}

template <typename T>
void write(T n){
    if (n < 10){
        putchar('0' + n);
        return;
    }
    write(n / 10);
    putchar(n % 10 + '0');
}

template <typename T>
T GCD(T a, T b){
    if (b == 0) return a;
    return GCD(b, a % b);
}

class Solver{
public:
    using vvi128i = std::vector <std::vector <std::pair <i128, int>>>;

    bool process(vvi128i &vec1, vvi128i &vec2){
        std::map <i128, int> map1, map2;
        for (auto &u : vec1){
            int sz = u.size();
            for (int i = 0; i < sz - 1; ++ i){
                auto [prime, cnt] = u[i];
                map1[prime] = std::max(map1[prime], cnt);
            }
        }
        for (auto &u : vec2){
            int sz = u.size();
            for (int i = 0; i < sz - 1; ++ i){
                auto [prime, cnt] = u[i];
                map2[prime] = std::max(map2[prime], cnt);
            }
        }
        std::pair <i128, int> found;
        for (const auto &[prime, cnt] : map1){
            auto u = map2.find(prime);
            if (u == map2.end() || u -> second < cnt){
                found = {prime, cnt};
                break;
            }
        }
        if (found.first == 0){
            return false;
        }

        vvi128i vec3;
        for (auto &u : vec1){
            int sz = u.size();
            bool illegal = false;
            for (int i = 0; i < sz - 1; ++ i){
                if (u[i] == found){
                    illegal = true;
                    break;
                }
            }
            if (!illegal){
                vec3.emplace_back(u);
            }
        }
        vec1.swap(vec3);
        return true;
    }

    void solve(){
        int n, m;
        read(n), read(m);
        std::vector <i128> a(n), b(m);
        for (int i = 0; i < n; ++ i){
            read(a[i]);
        }
        for (int i = 0; i < m; ++ i){
            read(b[i]);
        }
        std::vector <i128> prime;
        // for (auto u : Prime::prime){
        //     prime.emplace_back(u);
        // }
        std::deque <i128> deque;
        for (auto u : a){
            for (auto v : prime){
                while (u % v == 0){
                    u /= v;
                }
            }
            if (u > 1){
                deque.emplace_back(u);
            }
        }
        for (auto u : b){
            for (auto v : prime){
                while (u % v == 0){
                    u /= v;
                }
            }
            if (u > 1){
                deque.emplace_back(u);
            }
        }
        while (!deque.empty()){
            int sz = deque.size(), pos = 0;
            for (int i = 1; i < sz; ++ i){
                if (GCD(deque[0], deque[i]) > 1){
                    pos = i;
                    break;
                }
            }
            if (pos == 0){
                prime.emplace_back(deque.front());
                deque.pop_front();
                continue;
            }
            std::swap(deque[1], deque[pos]);
            i128 x = deque[0], y = deque[1], gcd = GCD(x, y);
            deque.pop_front(), deque.pop_front();
            while (true){
                i128 xx = x, yy = y;
                while (xx % gcd == 0){
                    xx /= gcd;
                }
                while (yy % gcd == 0){
                    yy /= gcd;
                }
                i128 gcd1 = GCD(xx, gcd);
                if (gcd1 > 1){
                    gcd = gcd1;
                    continue;
                }
                gcd1 = GCD(yy, gcd);
                if (gcd1 > 1){
                    gcd = gcd1;
                    continue;
                }
                if (xx > 1){
                    deque.emplace_back(xx);
                }
                if (yy > 1){
                    deque.emplace_back(yy);
                }
                deque.emplace_back(gcd);
                break;
            }
        }
        vvi128i a1(n), b1(m);
        for (int i = 0; i < n; ++ i){
            i128 x = a[i];
            for (auto u : prime){
                if (x % u == 0){
                    int cnt = 0;
                    while (x % u == 0){
                        x /= u;
                        ++ cnt;
                    }
                    a1[i].emplace_back(u, cnt);
                }
            }
            a1[i].emplace_back(0, i);
        }
        for (int i = 0; i < m; ++ i){
            i128 x = b[i];
            for (auto u : prime){
                if (x % u == 0){
                    int cnt = 0;
                    while (x % u == 0){
                        x /= u;
                        ++ cnt;
                    }
                    b1[i].emplace_back(u, cnt);
                }
            }
            b1[i].emplace_back(0, i);
        }
        while (process(a1, b1) || process(b1, a1))
            ;
        if (a1.empty() || b1.empty()){
            puts("NO");
            return;
        }
        puts("YES");
        int sz1 = a1.size(), sz2 = b1.size();
        printf("%d %d\n", sz1, sz2);
        for (int i = 0; i < sz1; ++ i){
            write(a[a1[i].back().second]);
            printf("%c", " \n"[i == sz1 - 1]);
        }
        for (int i = 0; i < sz2; ++ i){
            write(b[b1[i].back().second]);
            printf("%c", " \n"[i == sz2 - 1]);
        }
    }
};

int main(){
    const int MAX = 1e5;
    Prime::init(MAX);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    int test;
    read(test);
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
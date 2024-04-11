//
// Created by  on 2022/1/9.
//

#include <bits/stdc++.h>

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

//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

// #define DEBUG

using ll = int64_t;
using pii = std::pair <int, int>;

const int N = 1000010;
const int BIT = 20;

int ans[N], value[N], has[N];
std::vector <int> component[N];
bool oracle[N];
int oracle_n;

void ask(const std::vector <int> &vec){
    int sz = vec.size();
#ifdef DEBUG
    for (int i = 0; i < sz; ++ i){
        int x = 0;
        for (int j = 1; j <= oracle_n; ++ j){
            if (oracle[j] && std::gcd(vec[i], j) == 1){
                x ^= j;
            }
        }
        ans[vec[i]] = x;
    }
#else
    std::cout << sz;
    for (auto u : vec){
        std::cout << ' ' << u;
    }
    std::cout << '\n';
    std::cout.flush();
    for (int i = 0; i < sz; ++ i){
        int x;
        std::cin >> x;
        ans[vec[i]] = x;
    }
#endif
}

void gauss(std::vector <int> &equation, std::vector <int> &result, int bit, int &rank,
           std::vector <int> &base, std::vector <int> &mapping, std::vector <int> &representation){
    int n = equation.size();
    rank = 0;
    base = std::vector <int>(bit, -1);
    mapping = std::vector <int>(n);
    for (int i = 0; i < n; ++ i){
        mapping[i] = i;
    }
    representation = std::vector <int>(n);
    for (int i = 0; i < bit; ++ i){
        bool has = false;
        for (int j = rank; j < n; ++ j){
            if (equation[j] >> i & 1){
                std::swap(equation[rank], equation[j]);
                std::swap(result[rank], result[j]);
                std::swap(mapping[rank], mapping[j]);
                std::swap(representation[rank], representation[j]);
                has = true;
                break;
            }
        }
        if (!has){
            continue;
        }
        base[i] = rank;
        representation[rank] |= 1 << rank;
        for (int j = 0; j < n; ++ j){
            if (j == rank){
                continue;
            }
            if (equation[j] >> i & 1){
                equation[j] ^= equation[rank];
                result[j] ^= result[rank];
                representation[j] ^= representation[rank];
            }
        }
        ++ rank;
    }
}

void solve(){
    int c, n;
#ifdef DEBUG
    oracle_n = c = 2'000;
    n = 21;
    std::vector <int> tmp(c);
    for (int i = 0; i < c; ++ i){
        tmp[i] = i + 1;
    }
    std::mt19937 rnd(19971109);
    std::shuffle(tmp.begin(), tmp.end(), rnd);
    for (int i = 1; i <= n; ++ i){
        oracle[tmp[i - 1]] = true;
    }
#else
    std::cin >> c >> n;
#endif
    std::vector <int> vec;
    for (int i = c; i >= 1; -- i){
        if (Prime::mu[i] != 0){
            vec.emplace_back(i);
        }
    }
    ask(vec);
    for (int i = 1; i <= c; ++ i){
        if (Prime::mu[i] == 0){
            continue;
        }
        for (int j = i; j <= c; j += i){
            if (Prime::mu[i] != 0){
                value[j] ^= ans[i];
            }
        }
    }
    for (int i = c; i >= 1; -- i){
        if (Prime::mu[i] == 0){
            continue;
        }
        for (int j = i + i; j <= c; j += i){
            if (Prime::mu[j] == 0){
                continue;
            }
            value[i] ^= value[j];
        }
    }
    for (int i = 1; i <= c; ++ i){
        int mult = 1, x = i;
        while (x > 1){
            int tmp = Prime::min[x];
            while (x % tmp == 0){
                x /= tmp;
            }
            mult *= tmp;
        }
        component[mult].emplace_back(i);
    }
    std::vector <std::pair <int, std::vector <int>>> flippable;
    for (int i = 1; i <= c; ++ i){
        int sz = component[i].size();
        if (sz == 0){
            continue;
        }
        int rank = 0;
        std::vector <int> base, mapping, representation, result(sz);
        std::vector <int> equation = component[i];
        gauss(equation, result, BIT, rank, base, mapping, representation);
        int cur = value[i];
        int repr = 0;
        for (int j = 0; j < BIT; ++ j){
            if (cur >> j & 1){
                int id = base[j];
                assert(id != -1);;
                repr ^= representation[id];
                cur ^= equation[id];
            }
        }
        for (int j = 0; j < rank; ++ j){
            if (repr >> j & 1){
                has[component[i][mapping[j]]] = true;
            }
        }
        for (int j = rank; j < sz; ++ j){
            int id = component[i][mapping[j]];
            std::vector <int> related = {id};
            for (int k = 0; k < rank; ++ k){
                if (representation[j] >> k & 1){
                    related.emplace_back(component[i][mapping[k]]);
                }
            }
            flippable.emplace_back(id, related);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= c; ++ i){
        cnt += has[i];
    }
    std::mt19937 rnd1(19971109);
    while (cnt != n){
        int id = rnd1() % flippable.size();
        for (auto u : flippable[id].second){
            cnt += has[u] ? -1 : 1;
            has[u] = !has[u];
        }
        for (auto &[id, flip]: flippable){
            int diff = 0;
            for (auto u : flip){
                diff += has[u] ? -1 : 1;
            }
            if (std::abs(cnt + diff - n) < std::abs(cnt - n)){
                for (auto u : flip){
                    cnt += has[u] ? -1 : 1;
                    has[u] = !has[u];
                }
            }
        }
    }
    std::vector <int> output;
    for (int i = 1; i <= c; ++ i){
        if (has[i]){
            output.emplace_back(i);
        }
    }
    int sz = output.size();
    assert(sz == n);
    for (int i = 0; i < sz; ++ i){
        std::cout << output[i] << " \n"[i == sz - 1];
    }
#ifdef DEBUG
    for (int i = 0; i < sz; ++ i){
        int x = 0;
        for (int j = 1; j <= oracle_n; ++ j){
            if (oracle[j] && std::gcd(vec[i], j) == 1){
                x ^= j;
            }
            if (has[j] && std::gcd(vec[i], j) == 1){
                x ^= j;
            }
        }
        assert(x == 0);
    }
#endif
}

int main(){
    Prime::init(N);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}
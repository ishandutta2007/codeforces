//
// Created by  on 2022/2/16.
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

const int mod1 = 1001452789;
const int base1 = 53;
const int mod2 = 1001452871;
const int base2 = 47;
const int moder = int(1e9) + 7;

constexpr int N = 2000010;
constexpr int M = 100010;
constexpr int K = 30;

int power1[N], power2[N], power[N];
int hash1[N], hash2[N];
int hash3[N], hash4[N];

std::string s, t;
int pref[M][K];
bool prefix[N], suffix[N];

bool equal(int l1, int r1, int l2, int r2){
    int x1 = (hash1[r1 + 1] - 1ll * power1[r1 - l1 + 1] * hash1[l1]) % mod1;
    x1 += x1 < 0 ? mod1 : 0;
    int x3 = (hash3[r2 + 1] - 1ll * power1[r2 - l2 + 1] * hash3[l2]) % mod1;
    x3 += x3 < 0 ? mod1 : 0;
    if (x1 != x3){
        return false;
    }

    int x2 = (hash2[r1 + 1] - 1ll * power2[r1 - l1 + 1] * hash2[l1]) % mod2;
    x2 += x2 < 0 ? mod2 : 0;
    int x4 = (hash4[r2 + 1] - 1ll * power2[r2 - l2 + 1] * hash4[l2]) % mod2;
    x4 += x4 < 0 ? mod2 : 0;
    if (x2 != x4){
        return false;
    }
    return true;
}

class Solver{
public:
    int build(const std::string &s1, const std::string &query){
        int len = s1.size();
        hash1[0] = hash2[0] = 0;
        for (int i = 1; i <= len; ++ i){
            hash1[i] = (1ll * base1 * hash1[i - 1] + s1[i - 1]) % mod1;
            hash2[i] = (1ll * base2 * hash2[i - 1] + s1[i - 1]) % mod2;
        }

        len = query.size();
        hash3[0] = hash4[0] = 0;
        for (int i = 1; i <= len; ++ i){
            hash3[i] = (1ll * base1 * hash3[i - 1] + query[i - 1]) % mod1;
            hash4[i] = (1ll * base2 * hash4[i - 1] + query[i - 1]) % mod2;
        }
        int cnt = 0;
        int n = s1.size();
        int m = query.size();
        for (int i = 0; i < n; ++ i){
            int r = i + m - 1;
            if (r >= n){
                break;
            }
            cnt += equal(i, r, 0, m - 1);
        }
        prefix[0] = suffix[0] = true;
        for (int i = 1; i <= m; ++ i){
            int l1 = 0, r1 = i - 1;
            int l2 = m - i, r2 = m - 1;
            suffix[i] = equal(l1, r1, l2, r2);
            l1 = n - i, r1 = n - 1;
            l2 = 0, r2 = i - 1;
            prefix[i] = equal(l1, r1, l2, r2);
        }
        return cnt;
    }

    void solve(){
        power[0] = power1[0] = power2[0] = 1;
        for (int i = 1; i < N; ++ i){
            power[i] = 2 * power[i - 1] % moder;
            power1[i] = 1ll * base1 * power1[i - 1] % mod1;
            power2[i] = 1ll * base2 * power2[i - 1] % mod2;
        }

        int n, q;
        std::cin >> n >> q;
        std::cin >> s >> t;
        int lent = t.size();
        for (int i = 0; i < lent; ++ i){
            for (int j = 0; j < K; ++ j){
                pref[i + 1][j] = 2 * pref[i][j] % moder;
            }
            int &u = pref[i + 1][t[i] - 'a'];
            u += 1;
            u -= u >= moder ? moder : 0;
        }
        while (q --){
            int end;
            std::string query;
            std::cin >> end >> query;
            int m = query.size();
            int cur = 0;
            std::string s1 = s;
            while (cur < end && s1.size() < m){
                s1 += t[cur] + s1;
                ++ cur;
            }
            if (s1.size() < m){
                std::cout << "0\n";
                continue;
            }
            int cnt = build(s1, query);
            int ans = 1ll * power[end - cur] * cnt % moder;
            for (int i = 0; i < m; ++ i){
                if (prefix[i] && suffix[m - 1 - i]){
                    int value = (pref[end][query[i] - 'a'] - 1ll * power[end - cur] * pref[cur][query[i] - 'a']) % moder;
                    value += value < 0 ? moder : 0;
                    ans += value;
                    ans -= ans >= moder ? moder : 0;
                }
            }
            std::cout << ans << "\n";
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H
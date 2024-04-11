#include <bits/stdc++.h>

const int N = 10000001;
const int M = 500010;

std::vector<int> min, prime;

void init() {
    min.resize(N);
    for (int i = 2; i < N; ++i) {
        if (!min[i]) {
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime) {
            if (i * u >= N) {
                break;
            }
            min[i * u] = u;
            if (i % u == 0) {
                break;
            }
        }
    }
}

int ans1[N], ans2[N];
int out1[M], out2[M];
int ps[M];

void solve(int i){
    int n;
    scanf("%d", &n);
    out1[i] = ans1[n], out2[i] = ans2[n];
}

int main(){
    init();
    // int cnt = 0;
    for (int i = 2; i < N; ++ i){
        auto calc = [&](int m){
            for (int j = 0; j < m; ++ j){
                for (int k = j + 1; k < m; ++ k){
                    if (std::__gcd(ps[j] + ps[k], i) == 1){
                        ans1[i] = ps[j];
                        ans2[i] = ps[k];
                        return true;
                    }
                }
            }
            return false;
        };
        int x = i;
        int m = 0;
        while (x > 1){
            int tmp = min[x];
            ps[m ++] = tmp;
            while (x % tmp == 0){
                x /= tmp;
            }
        }
        if (m == 1){
            ans1[i] = ans2[i] = -1;
            continue;
        }
        if (calc(m)){
            continue;
        }
        x = i;
        m = 0;
        while (x > 1){
            int tmp = min[x];
            int prod = 1;
            while (x % tmp == 0){
                x /= tmp;
                prod *= tmp;
                ps[m ++] = prod;
            }
        }
        if (calc(m)){
            continue;
        }
        m = 0;
        for (int j = 2; j * j <= i; ++ j){
            if (i % j == 0){
                ps[m ++] = j;
                if (j * j != i){
                    ps[m ++] = i / j;
                }
            }
        }
        if (calc(m)){
            continue;
        }
        ans1[i] = ans2[i] = -1;
    }
    // printf("%d\n", cnt);
    int test;
    scanf("%d", &test);
    for (int i = 1; i <= test; ++ i){
        solve(i);
    }
    for (int i = 1; i <= test; ++ i){
        printf("%d%c", out1[i], " \n"[i == test]);
    }
    for (int i = 1; i <= test; ++ i){
        printf("%d%c", out2[i], " \n"[i == test]);
    }
    return 0;
}
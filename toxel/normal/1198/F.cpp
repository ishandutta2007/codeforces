#include <bits/stdc++.h>

const int N = 100010;
const int K = 9;

int a[N];
short dp[2 * K * K + 2][1 << K][1 << K];
int ans[N];

void factorize(int x, std::vector <int> &prime){
    for (int i = 2; i * i <= x; ++ i){
        if (x % i == 0){
            prime.emplace_back(i);
            while (x % i == 0){
                x /= i;
            }
        }
    }
    if (x > 1){
        prime.emplace_back(x);
    }
}

bool solve(int x, int y, int n){
    std::vector<int> prime1, prime2;
    factorize(a[x], prime1);
    factorize(a[y], prime2);
    std::vector<int> mask1(n), mask2(n);
    int sz1 = prime1.size(), sz2 = prime2.size();
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < sz1; ++ j){
            if (a[i] % prime1[j] == 0){
                mask1[i] |= 1 << j;
            }
        }
        for (int j = 0; j < sz2; ++ j){
            if (a[i] % prime2[j] == 0){
                mask2[i] |= 1 << j;
            }
        }
    }
    std::vector<int> todo1[K], todo2[K];
    std::set<int> set;
    auto push = [&](std::vector<int> &vec, int x){
        if (int(vec.size()) >= 2 * K){
            return;
        }
        vec.emplace_back(x);
        set.insert(x);
    };
    for (int i = 0; i < n; ++ i){
        if (i == x || i == y){
            continue;
        }
        for (int j = 0; j < sz1; ++ j){
            if (!(mask1[i] >> j & 1)){
                push(todo1[j], i);
            }
        }
        for (int j = 0; j < sz2; ++ j){
            if (!(mask2[i] >> j & 1)){
                push(todo2[j], i);
            }
        }
    }
    std::vector <int> todo;
    for (auto u : set){
        todo.emplace_back(u);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][(1 << sz1) - 1][(1 << sz2) - 1] = 0;
    int sz = todo.size();
    for (int i = 0; i < sz; ++ i){
        for (int j = 0; j < 1 << sz1; ++ j){
            for (int k = 0; k < 1 << sz2; ++ k){
                if (dp[i][j][k] == -1){
                    continue;
                }
                dp[i + 1][j][k] = 0;
                int nj = j & mask1[todo[i]];
                int nk = k & mask2[todo[i]];
                dp[i + 1][nj][k] = j | 1 << K;
                dp[i + 1][j][nk] = k | 2 << K;
            }
        }
    }
    if (dp[sz][0][0] == -1){
        return false;
    }
    for (int i = 0; i < n; ++ i){
        ans[i] = 1;
    }
    int state1 = 0, state2 = 0;
    for (int i = sz; i >= 1; -- i){
        int state = dp[i][state1][state2];
        int nstate = state & ((1 << K) - 1);
        int type = state >> K;
        if (type == 0){
            continue;
        }
        ans[todo[i - 1]] = type;
        (type == 1 ? state1 : state2) = nstate;
    }
    ans[x] = 1;
    ans[y] = 2;
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    if (n <= 2 * K){
        for (int i = 1; i < (1 << n) - 1; ++ i){
            int gcd1 = 0, gcd2 = 0;
            for (int j = 0; j < n; ++ j){
                if (i >> j & 1){
                    gcd1 = std::__gcd(gcd1, a[j]);
                }
                else{
                    gcd2 = std::__gcd(gcd2, a[j]);
                }
            }
            if (gcd1 == 1 && gcd2 == 1){
                puts("YES");
                for (int j = 0; j < n; ++ j){
                    printf("%d%c", i >> j & 1 ? 1 : 2, " \n"[j == n - 1]);
                }
                return 0;
            }
        }
        puts("NO");
        return 0;
    }
    std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());
    for (int i = 0; i < 10; ++ i){
        int x = rnd() % n, y = rnd() % n;
        if (x == y){
            continue;
        }
        if (x > y){
            std::swap(x, y);
        }
        if (solve(x, y, n)){
            puts("YES");
            for (int j = 0; j < n; ++ j){
                printf("%d%c", ans[j], " \n"[j == n - 1]);
            }
            return 0;
        }
    }
    puts("NO");
    return 0;
}
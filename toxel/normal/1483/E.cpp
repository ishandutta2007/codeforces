#include <bits/stdc++.h>

using ll = long long;
const int N = 55;

ll dp[N][N];
char s[N];
ll oracle = 5;

bool ask(ll x){
    printf("? %lld\n", x);
    fflush(stdout);
    scanf("%s", s);
    if (!strcmp(s, "Lucky!")){
        return true;
    }
    else if (!strcmp(s, "Fraudster!")){
        return false;
    }
    else{
        exit(0);
    }
}

void solve(){
    ll l = -1, r = -1;
    ll amount = 0;
    for (int i = 0; i <= 46; ++ i){
        if (!ask(1ll << i)){
            l = i == 0 ? 0 : 1ll << (i - 1);
            r = (1ll << i) - 1;
            amount = 0;
            break;
        }
        amount += 1ll << i;
    }
    if (l == -1){
        l = 1ll << 46;
        r = 1e14;
    }
    int cur = N - 1;
    int state = 0;
    while (cur > 0 && dp[cur - 1][0] >= r - l){
        -- cur;
    }
    while (l < r){
        if (state == 0){
            ask(l);
            amount += l;
            -- cur;
            ++ state;
            continue;
        }
        ll can = dp[cur - 1][state - 1];
        ll target = l + can + 1;
        target = std::min(r, target);
        target = std::max(l + 1, target);
        while (amount < target){
            assert(ask(l));
            amount += l;
        }
        if (ask(target)){
            amount += target;
            l = target;
            ++ state;
        }
        else{
            amount -= target;
            r = target - 1;
            -- state;
        }
        cur = std::max(1, cur - 1);
    }
    printf("! %lld\n", l);
    fflush(stdout);
}

int main(){
    for (int i = 1; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            dp[i][j] = 1;
            if (j > 0){
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j < N - 1){
                dp[i][j] += dp[i - 1][j + 1];
            }
        }
    }
    // for (int i = 0; i < N; ++ i){
    //     for (int j = 0; j < N; ++ j){
    //         printf("%lld%c", dp[i][j], " \n"[j == N - 1]);
    //     }
    // }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}

// #include <bits/stdc++.h>
//
// using ll = long long;
// using db = double;
// const db RATIO_DOWN = 0.2;
// const db RATIO_UP = 0.25;
//
// std::mt19937 rnd(19971109);
//
// int calc(ll value, bool print = false){
//     ll init = 1;
//     int cnt = 0;
//     ll l = 0, r = 1;
//     while (true){
//         ++ cnt;
//         if (r > value){
//             init = 0;
//             l = r / 2;
//             r = r - 1;
//             break;
//         }
//         init += r;
//         r = init;
//     }
//     while (l < r){
//         if (print){
//             printf("%lld %lld %lld %d\n", l, r, init, cnt);
//         }
//         ll mid = (l + r + 1) / 2;
//         if (mid == l){
//             ++ mid;
//         }
//         if (init < mid){
//             double ratio = RATIO_DOWN + (RATIO_UP - RATIO_DOWN) * (rnd() & 0xffffu) / 0x10000u;
//             mid = l + (r - l) * ratio;
//             if (mid == l){
//                 ++ mid;
//             }
//             while (init < mid){
//                 init += l;
//                 ++ cnt;
//                 if (print){
//                     printf("%lld %lld %lld %d\n", l, r, init, cnt);
//                 }
//             }
//         }
//         if (mid <= value){
//             init += mid;
//             l = mid;
//         }
//         else{
//             init -= mid;
//             r = mid - 1;
//         }
//         ++ cnt;
//     }
//     if (print){
//         puts("-----------------------------------");
//     }
//     return cnt;
// }
//
// int main(){
//     const int MAX = 100000000;
//     int cur_max = 0;
//     for (int i = 0; i <= MAX; ++ i){
//         int value = calc(i);
//         if (value > cur_max){
//             printf("%d %d\n", i, value);
//             cur_max = value;
//             calc(i, true);
//         }
//     }
// }

// const int N = 1010;
// const int M = 200;
// using piii = std::tuple <int, int, int>;
//
// int dp[M][M][N];
// int decision[M][M][N];
//
// int main(){
//     memset(dp, 0x3f, sizeof(dp));
//     int init, max;
//     scanf("%d%d", &init, &max);
//     for (int len = 1; len <= max + 1; ++ len){
//         for (int i = 0; i + len - 1 <= max; ++ i){
//             int j = i + len - 1;
//             if (len == 1){
//                 for (int k = 0; k < N; ++ k){
//                     dp[i][j][k] = 0;
//                 }
//                 continue;
//             }
//             for (int k = i + 1; k < N; ++ k){
//                 for (int u = i + 1; u <= j && u <= k; ++ u){
//                     if (k + u >= N) break;
//                     int value = std::max(dp[i][u - 1][k - u], dp[u][j][k + u]) + 1;
//                     if (value < dp[i][j][k]){
//                         dp[i][j][k] = value;
//                         decision[i][j][k] = u;
//                     }
//                 }
//             }
//         }
//     }
//     printf("%d\n", dp[0][max][init]);
//     for (int i = 0; i <= max; ++ i){
//         puts("-----------------------------------------");
//         int l = 0, r = max, tot = 1;
//         while (l <= r){
//             int choose = decision[l][r][tot];
//             printf("%d %d %d %d\n", l, r, tot, choose);
//             if (l == r){
//                 break;
//             }
//             if (i >= choose){
//                 l = choose;
//                 tot += choose;
//             }
//             else{
//                 r = choose - 1;
//                 tot -= choose;
//             }
//         }
//     }
//     return 0;
// }
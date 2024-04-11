#include<bits/stdc++.h>

typedef long long ll;

const int N = 10001;
const int M = 5;
const ll MAX = 10004205361450474ll;

ll dp[N][M];

void init(){
    for (int i = 1; i < N; ++ i){
        dp[i][0] = 2 * i - 1;
    }
    for (int j = 1; j < M; ++ j){
        for (int i = 1; i < N; ++ i){
            ll max = dp[N - 1][j - 1] - (N - 1) + 2, now = i;
            for (int k = 0; k <= i; ++ k){
                now = now >= N ? now + max : now < 0 ? 0 : dp[now][j - 1] + 2;
            }
            dp[i][j] = now - 2;
        }
    }
}

ll left;

void ask(std::vector <ll> &vec){
    printf("%d", (int) vec.size());
    for (auto u : vec){
        printf(" %lld", u);
    }
    puts("");
    fflush(stdout);
    int t;
    scanf("%d", &t);
    if (t < 0) exit(0);
    if (t > 0){
        left = vec[t - 1] + 1;
    }
}

int main(){
    init();
    left = 1;
    for (int i = M - 1; i > 0; -- i){
        ll max = dp[N - 1][i - 1] - (N - 1) + 1, now = left;
        std::vector <ll> vec;
        for (int j = 0; j < std::min(left, (ll) N - 1); ++ j){
            now = now >= N ? now + max : dp[now][i - 1] + 1;
            vec.push_back(now);
            ++ now;
        }
        ask(vec);
    }
    std::vector <ll> vec;
    for (int i = 0; i < std::min(left, (ll) N - 1); ++ i){
        vec.push_back(left + i);
    }
    ask(vec);
    return 0;
}
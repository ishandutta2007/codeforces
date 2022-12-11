#include <bits/stdc++.h>

const int N = 510;

int ans = 0;
int asked[N];
int n, k;

void ask(const std::vector <int> &vec, bool reverse = false){
    putchar('?');
    if (reverse){
        std::vector <bool> vis(n + 1);
        for (auto u : vec){
            vis[u] = true;
        }
        for (int i = 1; i <= n; ++ i){
            if (!vis[i]){
                printf(" %d", i);
                asked[i] ^= 1;
            }
        }
        puts("");
    }
    else{
        for (auto u : vec){
            printf(" %d", u);
            asked[u] ^= 1;
        }
    }
    puts("");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    ans ^= x;
}

int main(){
    scanf("%d%d", &n, &k);
    if (n % 2 == 1 && k % 2 == 0){
        puts("-1");
        return 0;
    }
    bool reverse = false;
    if (k % 2 == 1 && n % 2 == 0 && n < 2 * k){
        reverse = true;
        k = n - k;
    }
    if (n % k == 0){
        for (int i = 1; i <= n; i += k){
            std::vector <int> vec;
            for (int j = i; j < i + k; ++ j){
                vec.emplace_back(j);
            }
            ask(vec, reverse);
        }
    }
    else{
        int num = (n + k - 1) / k;
        num = std::max(3, num);
        if (num * k % 2 != n % 2){
            ++ num;
        }
        for (int i = 0; i < num - 2; ++ i){
            std::vector <int> vec;
            for (int j = i * k + 1; j <= i * k + k; ++ j){
                vec.emplace_back(j);
            }
            ask(vec, reverse);
        }
        int to_ask = n - (num - 2) * k;
        assert(to_ask % 2 == 0);
        for (int i = 0; i < 2; ++ i){
            std::vector <int> vec;
            for (int j = 0; j < to_ask / 2; ++ j){
                vec.emplace_back(n - j - (to_ask / 2) * i);
            }
            for (int j = 1; j <= k - to_ask / 2; ++ j){
                vec.emplace_back(j);
            }
            ask(vec, reverse);
        }
    }
    printf("! %d\n", ans);
    for (int i = 1; i <= n; ++ i){
        assert(asked[i] == 1);
    }
    return 0;
}
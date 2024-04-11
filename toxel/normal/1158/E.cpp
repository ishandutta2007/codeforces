#include <bits/stdc++.h>

const int N = (int) 1e3 + 30;
const int BIT = 10;

char s[N];
int n;
int dis[N], fa[N];
std::vector <int> vec[N];
bool done[N];

std::bitset <N> ask(std::vector <int> vec){
    putchar('?');
    for (auto u : vec){
        printf(" %d", std::min(n - 1, u));
    }
    puts("");
    fflush(stdout);
    scanf("%s", s);
    std::bitset <N> ret;
    for (int i = 1; i <= n; ++ i){
        ret[i] = s[i - 1] - '0';
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    vec[0] = {1};
    done[1] = true;
    for (int bit = BIT - 1; bit >= 0; -- bit){
        std::vector <int> ask1(n), ask2(n);
        for (int i = 0; i < 1 << BIT; i += 1 << (bit + 2)){
            for (auto u : vec[i]){
                ask1[u - 1] = (1 << bit) - 1;
                ask2[u - 1] = (1 << bit);
            }
        }
        std::bitset <N> set1 = ask(ask1);
        std::bitset <N> set2 = ask(ask2);
        for (int i = 1; i <= n; ++ i){
            if (done[i]){
                continue;
            }
            if (!(dis[i] >> (bit + 1) & 1)){
                if (!set1[i]){
                    dis[i] += 1 << bit;
                    if (set2[i]){
                        vec[dis[i]].push_back(i);
                        done[i] = true;
                    }
                }
            }
        }
        std::fill(ask1.begin(), ask1.end(), 0);
        std::fill(ask2.begin(), ask2.end(), 0);
        for (int i = 1 << (bit + 1); i < 1 << BIT; i += 1 << (bit + 2)){
            for (auto u : vec[i]){
                ask1[u - 1] = (1 << bit) - 1;
                ask2[u - 1] = (1 << bit);
            }
        }
        set1 = ask(ask1);
        set2 = ask(ask2);
        for (int i = 1; i <= n; ++ i){
            if (done[i]){
                continue;
            }
            if (dis[i] >> (bit + 1) & 1){
                if (!set1[i]){
                    dis[i] += 1 << bit;
                    if (set2[i]){
                        vec[dis[i]].push_back(i);
                        done[i] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < BIT; ++ i){
        for (int j = 0; j < 3; ++ j){
            std::vector <int> toask(n);
            for (int k = 1; k <= n; ++ k){
                if (dis[k] % 3 == j && (k >> i & 1)){
                    toask[k - 1] = 1;
                }
            }
            std::bitset <N> set = ask(toask);
            for (int k = 1; k <= n; ++ k){
                if (dis[k] % 3 == (j + 1) % 3 && set[k]){
                    fa[k] |= 1 << i;
                }
            }
        }
    }
    puts("!");
    for (int i = 2; i <= n; ++ i){
        printf("%d %d\n", i, fa[i]);
    }
    return 0;
}
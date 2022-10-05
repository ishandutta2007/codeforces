#include <bits/stdc++.h>
#include <chrono>

const int BIT = 11;
const int N = 1 << BIT;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

int bitcnt[N];

int ask(int i, int j){
    printf("? %d %d\n", i + 1, j + 1);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

void solve(int x, int y, int n){
    int zero = -1;
    while (true){
        int z = rnd() % n;
        if (z == x || z == y){
            continue;
        }
        int vx = ask(x, z), vy = ask(y, z);
        if (vx < vy){
            zero = x;
            break;
        }
        if (vy < vx){
            zero = y;
            break;
        }
    }
    std::vector<int> result;
    for (int i = 0; i < n; ++ i){
        if (i == zero){
            result.push_back(0);
        }
        else{
            result.push_back(ask(zero, i));
        }
    }
    printf("!");
    for (auto u : result){
        printf(" %d", u);
    }
    puts("");
}

int main(){
    for (int i = 1; i < N; ++ i){
        bitcnt[i] = bitcnt[i ^ (i & -i)] + 1;
    }
    /*int cnt = 0;
    for (int i = 0; i < N; ++ i){
        for (int j = i + 1; j < N; ++ j){
            if (bitcnt[i | j] <= 5){
                ++ cnt;
            }
        }
    }
    printf("%.15f\n", N * (N - 1) / 2.0 / cnt);*/
    int n;
    scanf("%d", &n);
    int x, y;
    while (true){
        x = rnd() % n, y = rnd() % n;
        if (x == y){
            continue;
        }
        if (bitcnt[ask(x, y)] <= 5){
            break;
        }
    }
    int x_value = INT_MAX;
    std::vector<int> result;
    for (int i = 0; i < n; ++ i){
        if (i == x){
            result.emplace_back(-1);
            continue;
        }
        result.emplace_back(ask(x, i));
        x_value = std::min(x_value, result.back());
    }
    std::vector<int> npos;
    for (int i = 0; i < n; ++ i){
        if (result[i] == -1 || result[i] == x_value){
            npos.emplace_back(i);
        }
    }
    if (int(npos.size()) > 2){
        while (true){
            x = rnd() % npos.size(), y = rnd() % npos.size();
            if (x == y){
                continue;
            }
            if (bitcnt[ask(npos[x], npos[y])] <= 2){
                break;
            }
        }
        x_value = INT_MAX;
        result.clear();
        for (int i = 0; i < npos.size(); ++ i){
            if (i == x){
                result.emplace_back(-1);
                continue;
            }
            result.emplace_back(ask(npos[x], npos[i]));
            x_value = std::min(x_value, result.back());
        }
        std::vector<int> nnpos;
        for (int i = 0; i < npos.size(); ++ i){
            if (result[i] == -1 || result[i] == x_value){
                nnpos.emplace_back(npos[i]);
            }
        }
        npos = nnpos;
        if (npos.size() > 2){
            for (int i = 0; i < npos.size(); ++ i){
                for (int j = i + 1; j < npos.size(); ++ j){
                    if (bitcnt[ask(npos[i], npos[j])] == 1){
                        x = npos[i], y = npos[j];
                        break;
                    }
                }
            }
            npos = {x, y};
        }
    }
    solve(npos[0], npos[1], n);
    return 0;
}
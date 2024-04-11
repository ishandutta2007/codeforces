#include <bits/stdc++.h>

const int N = 810;
const int M = 10;

int mod[N][M];
int ans[N], inv[N], a[N];
int n;

/*int answer(std::vector <int> vec){
    int sum = 0;
    for (auto u : vec){
        sum += a[u];
    }
    int ret = sum % vec.size() == 0;
    printf("%d\n", ret);
    return ret;
}*/

void print(){
    if (ans[1] > n / 2){
        for (int i = 1; i <= n; ++ i){
            ans[i] = n + 1 - ans[i];
        }
    }
    printf("!");
    for (int i = 1; i <= n; ++ i){
        printf(" %d", ans[i]);
    }
    puts("");
}

int ask(std::vector <int> vec, int calcmod){
    int n = vec.size();
    printf("? %d", n);
    for (auto u : vec){
        printf(" %d", u);
    }
    puts("");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    //ret = answer(vec);
    if (calcmod > 0){
        if (ret){
            int sum = 0;
            for (auto u : vec){
                if (u != calcmod){
                    sum = (sum + ans[u]) % n;
                }
            }
            mod[calcmod][n] = (n - sum) % n;
        }
    }
    return ret;
}


int main(){
    scanf("%d", &n);
    /*for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }*/
    memset(mod, -1, sizeof(mod));
    mod[1][2] = 1;
    for (int i = 1; i < n; ++ i){
        mod[i + 1][2] = mod[i][2] ^ (1 - ask({i, i + 1}, 0));
    }
    for (int i = 1; i <= 4 && i <= n / 2; ++ i){
        std::vector <int> todo;
        for (int j = 1; j <= n; ++ j){
            if (!ans[j]){
                todo.emplace_back(j);
            }
        }
        for (auto j : todo){
            std::vector <int> vec;
            for (auto k : todo){
                if (j != k){
                    vec.emplace_back(k);
                }
            }
            if (ask(vec, 0)){
                ans[j] = mod[j][2] == i % 2 ? i : n + 1 - i;
                inv[ans[j]] = j;
            }
        }
    }
    if (n <= 8){
        print();
        return 0;
    }
    for (int i = 3; i <= 7; i += 2){
        using pii = std::pair <int, int>;
        std::vector <pii> to_check;
        std::vector <int> known;
        for (int j = 0; j <= i / 2; ++ j){
            to_check.emplace_back(1, n - 3 + j);
        }
        for (int j = 1; j <= i / 2; ++ j){
            to_check.emplace_back(i / 2 + 1, n - 3 + j);
        }
        for (int j = 0; j <= i / 2; ++ j){
            known.emplace_back(j + 1);
            known.emplace_back(j + n - 3);
        }
        for (auto p : to_check){
            for (int j = 1; j <= n; ++ j){
                if (ans[j] || mod[j][i] != -1){
                    continue;
                }
                std::vector <int> vec = {j};
                for (auto u : known){
                    if (u == p.first || u == p.second){
                        continue;
                    }
                    vec.emplace_back(inv[u]);
                }
                ask(vec, j);
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (ans[i]){
            continue;
        }
        ask({inv[1], inv[2], inv[3], i}, i);
        if (mod[i][4] != -1){
            continue;
        }
        ask({inv[1], inv[2], inv[4], i}, i);
        if (mod[i][4] != -1){
            continue;
        }
        mod[i][4] = mod[i][2] == 1 ? 3 : 0;
    }
    std::vector <bool> calced(8);
    int sum = 0;
    for (int i = 1; i <= 4; ++ i){
        sum += n - 4 + i;
        sum += i;
    }
    for (int i = 1; i <= 4; ++ i){
        calced[(8 - (sum - i) % 8) % 8] = true;
    }
    for (int i = 1; i <= n; ++ i){
        if (ans[i]){
            continue;
        }
        int pos = 0;
        for (int j = 1; j <= 4; ++ j){
            if ((sum - j) % 4 == (4 - mod[i][4]) % 4){
                pos = j;
                break;
            }
        }
        std::vector <int> vec = {i};
        for (int j = 1; j <= 4; ++ j){
            vec.emplace_back(inv[n - 4 + j]);
            if (j != pos){
                vec.emplace_back(inv[j]);
            }
        }
        ask(vec, i);
        if (mod[i][8] == -1){
            mod[i][8] = (calced[mod[i][4]] ? 4 : 0) ^ mod[i][4];
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (ans[i]){
            continue;
        }
        for (int j = 1; j <= n; ++ j){
            bool flag = true;
            for (auto u : {3, 5, 7, 8}){
                if (j % u != mod[i][u]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                ans[i] = j;
                break;
            }
        }
    }
    print();
}
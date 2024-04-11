#include <bits/stdc++.h>

typedef std::pair <int, int> pii;

const int N = 100010;

char s[N];
int color[N];

void ask(std::vector <pii> vec){
    if (vec.empty()){
        return;
    }
    putchar('Q');
    printf(" %d", (int) vec.size());
    for (auto u : vec){
        printf(" %d %d", u.first, u.second);
    }
    puts("");
    fflush(stdout);
    scanf("%s", s);
}

bool equal[N];

void solve(){
    int n;
    scanf("%d", &n);
    std::vector <pii> vec;
    for (int i = 1; i < n; i += 2){
        vec.push_back({i, i + 1});
    }
    ask(vec);
    for (int i = 1; i < n; i += 2){
        equal[i] = s[i >> 1] == '1';
    }
    vec.clear();
    for (int i = 2; i < n; i += 2){
        vec.push_back({i, i + 1});
    }
    ask(vec);
    for (int i = 2; i < n; i += 2){
        equal[i] = s[(i >> 1) - 1] == '1';
    }
    std::vector <int> toask;
    for (int i = 1; i <= n; ++ i){
        if (i == 1 || !equal[i - 1]){
            toask.push_back(i);
        }
    }
    std::vector <bool> equal2(toask.size());
    vec.clear();
    for (int i = 2; i < toask.size(); ++ i){
        if (i % 4 <= 1){
            continue;
        }
        vec.push_back({toask[i], toask[i - 2]});
    }
    ask(vec);
    int cnt = 0;
    for (int i = 2; i < toask.size(); ++ i){
        if (i % 4 <= 1){
            continue;
        }
        equal2[i] = s[cnt ++] == '1';
    }
    vec.clear();
    for (int i = 2; i < toask.size(); ++ i){
        if (i % 4 >= 2){
            continue;
        }
        vec.push_back({toask[i], toask[i - 2]});
    }
    ask(vec);
    cnt = 0;
    for (int i = 2; i < toask.size(); ++ i){
        if (i % 4 >= 2){
            continue;
        }
        equal2[i] = s[cnt ++] == '1';
    }
    for (int i = 0; i < toask.size(); ++ i){
        if (i <= 1){
            color[toask[i]] = i;
        }
        else{
            if (equal2[i]){
                color[toask[i]] = color[toask[i - 2]];
            }
            else{
                color[toask[i]] = 3 - color[toask[i - 1]] - color[toask[i - 2]];
            }
        }
    }
    for (int i = 2; i <= n; ++ i){
        if (equal[i - 1]){
            color[i] = color[i - 1];
        }
    }
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++ i){
        cnt0 += color[i] == 0;
        cnt1 += color[i] == 1;
        cnt2 += color[i] == 2;
    }
    printf("A %d %d %d\n", cnt0, cnt1, cnt2);
    for (int i = 1; i <= n; ++ i){
        if (color[i] == 0){
            printf("%d ", i);
        }
    }
    puts("");
    for (int i = 1; i <= n; ++ i){
        if (color[i] == 1){
            printf("%d ", i);
        }
    }
    puts("");
    for (int i = 1; i <= n; ++ i){
        if (color[i] == 2){
            printf("%d ", i);
        }
    }
    puts("");
    fflush(stdout);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
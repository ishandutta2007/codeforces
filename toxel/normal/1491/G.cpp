#include <bits/stdc++.h>

const int N = 200010;
using pii = std::pair <int, int>;

std::vector <std::vector <int>> vec;
std::vector <pii> op;
int a[N], begin[N];
bool vis[N];

void operate(int x, int y){
    op.emplace_back(x, y);
    std::swap(a[x], a[y]);
    a[x] = -a[x];
    a[y] = -a[y];
}

void solve(int n){
    vec.clear();
    op.clear();
    memset(vis, 0, sizeof(vis[0]) * (n + 1));
    memcpy(begin, a, sizeof(a[0]) * (n + 1));
    for (int i = 1; i <= n; ++ i){
        if (vis[i]){
            continue;
        }
        std::vector <int> tmp;
        int x = i;
        while (!vis[x]){
            tmp.emplace_back(x);
            vis[x] = true;
            x = a[x];
        }
        if (int(tmp.size()) >= 2){
            vec.emplace_back(tmp);
        }
    }
    while (int(vec.size()) >= 2){
        std::vector <int> vec1 = vec.back();
        vec.pop_back();
        std::vector <int> vec2 = vec.back();
        vec.pop_back();
        operate(vec1.back(), vec2.back());
        int sz1 = vec1.size(), sz2 = vec2.size();
        for (int i = 0; i < sz2 - 1; ++ i){
            operate(vec1.back(), vec2[i]);
        }
        for (int i = 0; i < sz1 - 1; ++ i){
            operate(vec2.back(), vec1[i]);
        }
        operate(vec1.back(), vec2.back());
    }
    if (!vec.empty()){
        std::vector <int> vec1 = vec[0];
        int sz = vec1.size();
        if (sz == 2){
            int tmp = 0;
            for (int i = 1; i <= n; ++ i){
                if (i != vec1[0] && i != vec1[1]){
                    tmp = i;
                    break;
                }
            }
            operate(vec1[0], tmp);
            operate(vec1[1], tmp);
            operate(vec1[0], tmp);
        }
        else{
            for (int i = 1; i < sz - 1; ++ i){
                operate(vec1[0], vec1[i]);
            }
            operate(vec1[1], vec1.back());
            operate(vec1[0], vec1.back());
            operate(vec1[0], vec1[1]);
        }
    }
    auto print = [&](){
        for (int i = 1; i <= n; ++ i){
            printf("%d%c", begin[i], " \n"[i == n]);
        }
        for (int i = 1; i <= n; ++ i){
            printf("%d%c", a[i], " \n"[i == n]);
        }
    };
    int sz = op.size();
    // puts("--------------");
    printf("%d\n", sz);
    for (auto u : op){
        printf("%d %d\n", u.first, u.second);
    }
    for (int i = 1; i <= n; ++ i){
        if (a[i] != i){
            print();
            exit(0);
        }
    }
    if (sz > n + 1){
        print();
        exit(0);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve(n);
    /*std::mt19937 rnd(19971109);
    for (int i = 0; i < 10000; ++ i){
        int n = 10;
        for (int i = 1; i <= n; ++ i){
            a[i] = i;
        }
        std::shuffle(a + 1, a + n + 1, rnd);
        solve(n);
    }*/
    return 0;
}
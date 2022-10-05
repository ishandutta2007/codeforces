#include <bits/stdc++.h>

const int N = 100010;

int ask(int n){
    printf("? %d\n", n);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == 0){
        exit(0);
    }
    return x;
}

int p[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        p[i] = 0;
    }
    while (true){
        int start = 0;
        for (int i = 1; i <= n; ++ i){
            if (p[i] == 0){
                start = i;
                break;
            }
        }
        if (start == 0){
            break;
        }
        std::vector <int> vec;
        while (true){
            vec.emplace_back(ask(start));
            if (int(vec.size()) > 1 && vec.front() == vec.back()){
                break;
            }
        }
        int sz = vec.size();
        for (int i = 0; i < sz - 1; ++ i){
            p[vec[i]] = vec[i + 1];
        }
    }
    putchar('!');
    for (int i = 1; i <= n; ++ i){
        printf(" %d", p[i]);
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
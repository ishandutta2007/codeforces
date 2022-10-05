#include<bits/stdc++.h>

int asked;

int ask(int type, int x){
    if (type == 0){
        printf("? %d\n", x);
    }
    else{
        printf("> %d\n", x);
    }
    ++ asked;
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    if (ret == -1) exit(0);
    return ret;
}

int randint(int n){
    return (1ll * rand() << 30 | rand()) % n;
}

int main(){
    srand((unsigned) time(NULL));
    int n;
    scanf("%d", &n);
    int left = 0, right = 1e9;
    while (left < right){
        int mid = (left + right) >> 1;
        if (ask(1, mid) == 1){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    std::map <int, int> set;
    while (asked < 60){
        if ((int) set.size() == n){
            break;
        }
        int x;
        while (true){
            x = randint(n) + 1;
            if (!set.count(x)){
                set[x] = 0;
                break;
            }
        }
        set[x] = ask(0, x);
    }
    int ans = 0;
    for (auto u : set){
        for (auto v : set){
            if (u == v) continue;
            ans = std::__gcd(ans, std::abs(u.second - v.second));
        }
    }
    printf("! %d %d\n", left - (n - 1) * ans, ans);
    return 0;
}
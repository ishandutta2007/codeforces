#include <bits/stdc++.h>

const int N = 100010;

int cnt[N];
char s[N];
int cnt2, cnt4, cnt6, cnt8;

void add(int x){
    ++ cnt[x];
    if (cnt[x] == 2){
        ++ cnt2;
    }
    if (cnt[x] == 4){
        ++ cnt4;
    }
    if (cnt[x] == 6){
        ++ cnt6;
    }
    if (cnt[x] == 8){
        ++ cnt8;
    }
}

void sub(int x){
    -- cnt[x];
    if (cnt[x] == 1){
        -- cnt2;
    }
    if (cnt[x] == 3){
        -- cnt4;
    }
    if (cnt[x] == 5){
        -- cnt6;
    }
    if (cnt[x] == 7){
        -- cnt8;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        add(x);
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int x;
        scanf("%s%d", s, &x);
        if (s[0] == '+'){
            add(x);
        }
        else{
            sub(x);
        }
        if (cnt8 > 0){
            puts("YES");
            continue;
        }
        if (cnt4 >= 2){
            puts("YES");
            continue;
        }
        if (cnt6 == 1 && cnt2 >= 2){
            puts("YES");
            continue;
        }
        if (cnt4 == 0){
            puts("NO");
            continue;
        }
        puts(cnt2 >= 3 ? "YES" : "NO");
    }
    return 0;
}
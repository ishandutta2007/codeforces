#include<bits/stdc++.h>

int get(int x){
    if (!x) return 0;
    x <<= 1;
    int y = std::sqrt(x);
    return y * (y + 1) == x ? y : -1;
}

const int N = 100010;

int cnt[N];

int main(){
    int a00, a01, a10, a11;
    scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
    if (!a00 && !a11){
        if (a01 == 1){
            if (a10 == 0){
                puts("01");
                return 0;
            }
            puts("Impossible");
            return 0;
        }
        if (a10 == 1){
            if (a01 == 0){
                puts("10");
                return 0;
            }
            puts("Impossible");
            return 0;
        }
        if (a01 || a10){
            puts("Impossible");
            return 0;
        }
        puts("1");
        return 0;
    }
    int cnt0 = get(a00);
    int cnt1 = get(a11);
    if (cnt0 == -1 || cnt1 == -1){
        puts("Impossible");
        return 0;
    }
    if (!cnt0){
        if (!a01 && !a10){
            for (int i = 0; i <= cnt1; ++ i){
                putchar('1');
            }
            puts("");
            return 0;
        }
        if (a01 + a10 != cnt1 + 1){
            puts("Impossible");
            return 0;
        }
        for (int i = 0; i < a10; ++ i){
            putchar('1');
        }
        putchar('0');
        for (int i = 0; i < a01; ++ i){
            putchar('1');
        }
        puts("");
        return 0;
    }
    if (!cnt1){
        if (!a01 && !a10){
            for (int i = 0; i <= cnt0; ++ i){
                putchar('0');
            }
            puts("");
            return 0;
        }
        if (a01 + a10 != cnt0 + 1){
            puts("Impossible");
            return 0;
        }
        for (int i = 0; i < a01; ++ i){
            putchar('0');
        }
        putchar('1');
        for (int i = 0; i < a10; ++ i){
            putchar('0');
        }
        puts("");
        return 0;
    }
    ++ cnt0, ++ cnt1;
    if (a01 + a10 != cnt0 * cnt1){
        puts("Impossible");
        return 0;
    }
    cnt[cnt1] = cnt0;
    while (a01 >= cnt1){
        a01 -= cnt1;
        -- cnt[cnt1];
        ++ cnt[0];
    }
    if (a01){
        -- cnt[cnt1];
        ++ cnt[cnt1 - a01];
    }
    for (int i = 0; i < cnt1; ++ i){
        for (int j = 0; j < cnt[i]; ++ j){
            putchar('0');
        }
        putchar('1');
    }
    for (int j = 0; j < cnt[cnt1]; ++ j){
        putchar('0');
    }
    puts("");
    return 0;
}
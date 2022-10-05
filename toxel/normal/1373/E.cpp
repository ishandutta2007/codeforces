#include <bits/stdc++.h>

const int N = 160;
const int M = 1'000'100;
const int K = 10;

int calc(int x){
    int ret = 0;
    for ( ; x; x /= 10){
        ret += x % 10;
    }
    return ret;
}

int cnt[M];
int ans[N][K];

void solve(int n, int k){
    if (ans[n][k] != -1){
        printf("%d\n", ans[n][k]);
        return;
    }
    if (k == 2 && n % 3 != 0){
        puts("-1");
        return;
    }
    if (k == 5 && n % 3 != 0){
        puts("-1");
        return;
    }
    if (k == 8 && n % 9 != 0){
        puts("-1");
        return;
    }
    if (k == 0){
        int up = n % 9, down = n / 9;
        if (up != 0){
            putchar(up + '0');
        }
        for (int i = 0; i < down; ++ i){
            putchar('9');
        }
        puts("");
        return;
    }
    if (n <= 44 && ans[n][k] == -1){
        puts("-1");
        return;
    }
    if (n % 2 == 1){
        int x = n / 2 + 1;
        int up = x % 9, down = x / 9;
        if (up != 0){
            putchar(up + '0');
        }
        for (int i = 0; i < down - 1; ++ i){
            putchar('9');
        }
        putchar('8');
        puts("");
        return;
    }
    int x = n / 2 + 4 + 1;
    int up = x % 9, down = x / 9;
    if (up != 0){
        putchar(up + '0');
    }
    for (int i = 0; i < down - 2; ++ i){
        putchar('9');
    }
    puts("89");
    /*if (ans[n][k] == -1){
        static int cnt = 0;
        ++ cnt;
        printf("wa %d: %d %d\n", cnt, n, k);
        return;
    }*/
    // printf("%d\n", ans[n][k]);
}

int main(){
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < M; ++ i){
        cnt[i] = calc(i);
    }
    for (int i = 0; i < 1'000'000; ++ i){
        int sum = 0;
        for (int j = 0; j < K; ++ j){
            sum += cnt[i + j];
            if (sum < N && ans[sum][j] == -1){
                ans[sum][j] = i;
            }
        }
    }
    /*for (int i = 1; i < N; ++ i){
        for (int j = 0; j < K; ++ j){
            solve(i, j);
        }
    }*/
    int test;
    scanf("%d", &test);
    while (test --){
        int n, k;
        scanf("%d%d", &n, &k);
        solve(n, k);
    }
    return 0;
}
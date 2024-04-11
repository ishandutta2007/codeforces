#include <bits/stdc++.h>

const int N = 3000010;

int a[N];
int cnt[N];

void dfs(int x, int y){
    if (cnt[x ^ y] >= 2){
        return;
    }
    ++ cnt[x ^ y];
    while (x){
        int lb = x & -x;
        x ^= lb;
        dfs(x, y);
        y |= lb;
    }
}

/*int bf(int n){
    int max = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            for (int k = j + 1; k < n; ++ k){
                max = std::max(max, a[i] | (a[j] & a[k]));
            }
        }
    }
    return max;
}*/

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int max = 0;
    for (int i = n - 1; i >= 0; -- i){
        dfs(a[i], 0);
        int cur = 0;
        for (int j = 20; j >= 0; -- j){
            if (a[i] >> j & 1){
                continue;
            }
            if (cnt[cur | 1 << j] >= 2){
                cur |= 1 << j;
            }
        }
        if (i <= n - 3) {
            max = std::max(max, cur | a[i]);
        }
    }
    printf("%d\n", max);
    //printf("%d\n", bf(n));
    return 0;
}
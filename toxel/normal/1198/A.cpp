#include <bits/stdc++.h>

const int N = 400010;

int a[N];

int main(){
    int n, I;
    scanf("%d%d", &n, &I);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    I = I * 8 / n;
    if (I >= 30){
        puts("0");
        return 0;
    }
    int length = 1 << I;
    int ans = INT_MAX, now = 1;
    for (int i = 0, j = 0; i < n; ){
        while (j < n && now <= length){
            ++ j;
            if (1 <= j && j < n && a[j] != a[j - 1]){
                ++ now;
            }
        }
        ans = std::min(ans, n - (j - i));
        ++ i;
        if (1 <= i && i < n && a[i] != a[i - 1]){
            -- now;
        }
    }
    printf("%d\n", ans);
    return 0;
}
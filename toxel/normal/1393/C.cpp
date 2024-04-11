#include <bits/stdc++.h>

const int N = 100010;

int cnt[N];

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        memset(cnt, 0, sizeof(cnt));
        int n;
        scanf("%d", &n);
        for (int i = 0, x; i < n; ++ i){
            scanf("%d", &x);
            ++ cnt[x];
        }
        int value = *std::max_element(cnt, cnt + N);
        int ccnt = 0;
        for (int i = 0; i < N; ++ i){
            ccnt += cnt[i] == value;
        }
        int ans = (n - ccnt) / (value - 1) - 1;
        printf("%d\n", ans);
    }
    return 0;
}
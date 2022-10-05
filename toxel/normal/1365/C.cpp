#include <bits/stdc++.h>

const int N = 200010;

int a[N], b[N];
int inva[N], invb[N];
int cnt[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        inva[a[i]] = i;
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
        invb[b[i]] = i;
    }
    for (int i = 1; i <= n; ++ i){
        int x = inva[i] - invb[i];
        x += x < 0 ? n : 0;
        ++ cnt[x];
    }
    int ans = *std::max_element(cnt, cnt + n);
    printf("%d\n", ans);
    return 0;
}
#include<bits/stdc++.h>

const int N = 200010;

int moder;
int inv[N];
int cnt[N];
int pre[N];
int ans;

void init(){
    inv[1] = 1;
    for (int i = 2; i < N; ++ i){
        inv[i] = moder - 1ll * (moder / i) * inv[moder % i] % moder;
    }
    for (int i = 1; i < N; ++ i){
        pre[i] = (pre[i - 1] + inv[2] - inv[i]) % moder;
        pre[i] += pre[i] < 0 ? moder : 0;
    }
}

void mergesort(int l, int r, int h){
    if (h <= 1){
        if (r >= l){
            ++ cnt[r - l + 1];
            ans = (ans + 1ll * (r - l + 1) * (r - l) % moder * inv[4]) % moder;
        }
        return;
    }
    int mid = (l + r) >> 1;
    mergesort(l, mid, h - 1);
    mergesort(mid + 1, r, h - 1);
}

int main(){
    int n, k;
    scanf("%d%d%d", &n, &k, &moder);
    init();
    if (k >= 20){
        puts("0");
        return 0;
    }
    mergesort(1, n, k);
    for (int i = 0; i <= n; ++ i){
        if (!cnt[i]) continue;
        for (int j = i; j <= n; ++ j){
            if (!cnt[j]) continue;
            int coe = i == j ? 1ll * cnt[i] * (cnt[i] - 1) / 2 % moder : 1ll * cnt[i] * cnt[j] % moder;
            for (int k = 1; k <= i; ++ k){
                ans = (ans + 1ll * coe * (pre[k + j] - pre[k])) % moder;
            }
        }
    }
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}
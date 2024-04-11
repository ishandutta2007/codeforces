#include <bits/stdc++.h>

const int N = 510;
const int moder = int(1e9) + 7;

int a[N];
int e[N];
int cnt[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        int fa = a[i] == -1 ? i : a[i];
        ++ cnt[fa];
    }
    e[1] = 114514;
    e[2] = 2 * e[1] - 1;
    for (int i = 2; i < N - 1; ++ i){
        e[i + 1] = (2 * e[i] - 1ll * (i - 1) * e[1] - 1) % moder;
        e[i + 1] += e[i + 1] < 0 ? moder : 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (cnt[i]){
            ans += e[cnt[i]];
            ans -= ans >= moder ? moder : 0;
        }
    }
    ans -= e[n];
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}
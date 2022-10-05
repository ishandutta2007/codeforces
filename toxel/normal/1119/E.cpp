#include <bits/stdc++.h>

typedef long long ll;

const int N = 300010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    ll ans = 0;
    for (int i = 0, j = 0; i < n; ++ i){
        if (a[i] != 1){
            continue;
        }
        j = std::max(j, i);
        while (j < n && a[j] < 2) {
            ++j;
        }
        if (a[j] >= 2){
            -- a[i];
            a[j] -= 2;
            ++ ans;
        }
    }
    ll tot = 0;
    for (int i = 0; i < n; ++ i){
        if (a[i] >= 2){
            tot += a[i];
        }
    }
    ans += tot / 3;
    printf("%lld\n", ans);
    return 0;
}
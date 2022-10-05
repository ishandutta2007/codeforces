#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int a[N];

int main(){
    int n, d, m;
    scanf("%d%d%d", &n, &d, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    int last = n;
    for (int i = 0; i < n; ++ i){
        if (a[i] > m){
            last = i;
            break;
        }
    }
    std::sort(a, a + last, std::greater<int>());
    ll ans = 0, sum = 0;
    for (int i = 0; i < last; ++ i){
        sum += a[i];
    }
    for (int i = last - 1, j = n - 1; i >= -1; -- i){
        while (j >= last){
            int num = i + 1 + (n - j) * (d + 1) - d;
            if (num > n){
                break;
            }
            sum += a[j --];
        }
        ans = std::max(ans, sum);
        if (i >= 0){
            sum -= a[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
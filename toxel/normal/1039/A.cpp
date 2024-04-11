#include<bits/stdc++.h>

typedef long long ll;
const int N = 200010;

ll a[N], b[N];
int x[N];
bool flag[N];

int main(){
    int n;
    ll t;
    scanf("%d%lld", &n, &t);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; ++ i){
        if (x[i] < i){
            puts("No");
            return 0;
        }
    }
    for (int i = 1; i < n; ++ i){
        if (x[i] > x[i + 1]){
            puts("No");
            return 0;
        }
        if (x[i] < x[i + 1] && a[i] + 1 == a[i + 1]){
            flag[i] = true;
        }
    }
    for (int i = 1, j = 1; i <= n; i = j){
        ll max = 0;
        while (j <= n && x[j] == x[i]){
            max = std::max(max, a[j]);
            ++ j;
        }
        if (x[j - 1] != j - 1){
            puts("No");
            return 0;
        }
        if (flag[j - 1] && i + 1 != j){
            puts("No");
            return 0;
        }
        if (flag[j - 1]){
            -- max;
        }
        for (int k = i; k < j; ++ k){
            b[k] = k + max + t + 2 - j;
        }
    }
    puts("Yes");
    for (int i = 1; i <= n; ++ i){
        printf("%lld%c", b[i], " \n"[i == n]);
    }
    return 0;
}
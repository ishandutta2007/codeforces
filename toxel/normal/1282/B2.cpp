#include <bits/stdc++.h>

const int N = 200010;

int a[N];
int pre[N];

int getpre(int sit){
    return sit < 0 ? 0 : pre[sit];
}

void solve(){
    int n, p, k;
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    for (int i = 0; i < n; ++ i){
        pre[i] = a[i] + (i == 0 ? 0 : pre[i - 1]);
    }
    int max = 0;
    for (int i = 0; i < k; ++ i){
        int sum = p - getpre(i - 1);
        if (sum < 0){
            continue;
        }
        max = std::max(i, max);
        for (int j = i - 1 + k; j < n; j += k){
            sum -= a[j];
            if (sum >= 0){
                max = std::max(max, j + 1);
            }
            else{
                break;
            }
        }
    }
    printf("%d\n", max);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
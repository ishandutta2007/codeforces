#include<bits/stdc++.h>

const int N = 200010;

int a[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    std::set <int> set;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        set.insert(a[i]);
    }
    int ans = n;
    for (int i = 0; i < n; ++ i){
        auto u = set.upper_bound(a[i]);
        ans -= u != set.end() && *u - a[i] <= k;
    }
    printf("%d\n", ans);
    return 0;
}
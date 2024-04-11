#include <bits/stdc++.h>

const int N = 100010;
using pii = std::pair <int, int>;

int a[N];
pii p[N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        p[i] = {a[i], i};
    }
    std::sort(p, p + n);
    int block = 1;
    for (int i = 1; i < n; ++ i){
        block += p[i].second != p[i - 1].second + 1;
    }
    puts(block <= k ? "Yes" : "No");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
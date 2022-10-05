#include <bits/stdc++.h>

const int N = 110;

int t[N], l[N], h[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%d", &t[i], &l[i], &h[i]);
    }
    int left = l[n - 1], right = h[n - 1];
    for (int i = n - 2; i >= 0; -- i){
        int diff = t[i + 1] - t[i];
        left = std::max(l[i], left - diff);
        right = std::min(h[i], right + diff);
        if (left > right){
            puts("NO");
            return;
        }
    }
    left -= t[0], right += t[0];
    if (left <= m && m <= right){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
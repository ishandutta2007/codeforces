#include <bits/stdc++.h>

void solve(){
    int n, x, m;
    scanf("%d%d%d", &n, &x, &m);
    int left = x, right = x;
    while (m --){
        int l, r;
        scanf("%d%d", &l, &r);
        int ll = std::max(l, left), rr = std::min(r, right);
        if (ll <= rr){
            left = std::min(left, l);
            right = std::max(right, r);
        }
    }
    printf("%d\n", right - left + 1);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}
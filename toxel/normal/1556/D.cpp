#include <bits/stdc++.h>

using ll = long long;
const int N = 10010;

int ask(int pos1, int pos2){
    printf("or %d %d\n", pos1, pos2);
    fflush(stdout);
    int ans1;
    scanf("%d", &ans1);
    printf("and %d %d\n", pos1, pos2);
    fflush(stdout);
    int ans2;
    scanf("%d", &ans2);
    return ans1 + ans2;
}

ll a[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int sum1 = ask(1, 2);
    int sum2 = ask(1, 3);
    int sum3 = ask(2, 3);
    ll sum123 = (0ll + sum1 + sum2 + sum3) / 2;
    a[1] = sum123 - sum3;
    a[2] = sum123 - sum2;
    a[3] = sum123 - sum1;
    for (int i = 4; i <= n; ++ i){
        a[i] = ask(1, i) - a[1];
    }
    std::sort(a + 1, a + n + 1);
    printf("finish %lld\n", a[k]);
    fflush(stdout);
    return 0;
}
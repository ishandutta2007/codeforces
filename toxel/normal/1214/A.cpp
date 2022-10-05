#include <bits/stdc++.h>

int main(){
    int n, d, e;
    scanf("%d%d%d", &n, &d, &e);
    int min = INT_MAX;
    for (int i = 0; i * 5 * e <= n; ++ i){
        min = std::min(min, (n - i * 5 * e) % d);
    }
    printf("%d\n", min);
    return 0;
}
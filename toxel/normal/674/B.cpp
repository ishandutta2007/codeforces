#include <bits/stdc++.h>

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (n == 4 || k < n + 1){
        puts("-1");
        return 0;
    }
    std::vector <int> middle;
    for (int i = 1; i <= n; ++ i){
        if (i != a && i != b && i != c && i != d){
            middle.push_back(i);
        }
    }
    printf("%d %d", a, c);
    for (auto u : middle){
        printf(" %d", u);
    }
    printf(" %d %d\n", d, b);
    printf("%d %d", c, a);
    for (int i = (int) middle.size() - 1; i >= 0; -- i){
        printf(" %d", middle[i]);
    }
    printf(" %d %d\n", b, d);
    return 0;
}
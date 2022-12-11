#include <bits/stdc++.h>

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    n = k + 1;
    std::map <int, int> map;
    for (int i = 1; i <= n; ++ i){
        putchar('?');
        for (int j = 1; j <= n; ++ j){
            if (j == i){
                continue;
            }
            printf(" %d", j);
        }
        puts("");
        fflush(stdout);
        int pos, value;
        scanf("%d%d", &pos, &value);
        ++ map[value];
    }
    auto u = std::prev(map.end());
    printf("! %d\n", u -> second);
    return 0;
}
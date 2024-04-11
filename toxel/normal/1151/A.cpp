#include <bits/stdc++.h>

const int N = 60;

char s[N], t[N] = "ACTG";

int main(){
    int n;
    scanf("%d%s", &n, s);
    int ans = INT_MAX;
    for (int i = 0; i <= n - 4; ++ i){
        int sum = 0;
        for (int j = 0; j < 4; ++ j){
            int x = s[i + j] - 'A';
            int y = t[j] - 'A';
            if (x > y){
                std::swap(x, y);
            }
            sum += std::min(y - x, 26 - (y - x));
        }
        ans = std::min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int p, f;
        scanf("%d%d", &p, &f);
        int cnts, cntw;
        scanf("%d%d", &cnts, &cntw);
        int s, w;
        scanf("%d%d", &s, &w);
        if (s > w){
            std::swap(s, w);
            std::swap(cnts, cntw);
        }
        int ans = 0;
        for (int i = 0; i <= cnts; ++ i){
            int num1 = 1ll * i * s;
            if (num1 > p){
                break;
            }
            int sum = i;
            int p1 = p - num1;
            int num2 = std::min(cntw, p1 / w);
            sum += num2;
            int cnts1 = cnts - i, cntw1 = cntw - num2;
            int num3 = std::min(f / s, cnts1);
            sum += num3;
            int f1 = f - num3 * s;
            sum += std::min(f1 / w, cntw1);
            ans = std::max(ans, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
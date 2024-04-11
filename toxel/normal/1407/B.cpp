#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        int gcd = 0;
        std::vector<int> vec(n);
        for (int i = 0; i < n; ++ i){
            scanf("%d", &vec[i]);
        }
        for (int i = 0; i < n; ++ i){
            int max = 0, pos = -1;
            for (int j = 0, sz = vec.size(); j < sz; ++ j){
                int x = std::__gcd(gcd, vec[j]);
                if (max < x){
                    max = x;
                    pos = j;
                }
            }
            printf("%d%c", vec[pos], " \n"[i == n - 1]);
            gcd = max;
            vec.erase(vec.begin() + pos);
        }
    }
    return 0;
}
#include <bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i){
            scanf("%d", &a[i]);
        }
        int min = *std::min_element(a, a + n);
        std::vector<int> vec;
        for (int i = 0; i < n; ++ i){
            if (a[i] % min == 0){
                vec.emplace_back(a[i]);
            }
        }
        std::sort(vec.begin(), vec.end());
        int cur = 0;
        for (int i = 0; i < n; ++ i){
            if (a[i] % min){
                continue;
            }
            a[i] = vec[cur ++];
        }
        bool flag = true;
        for (int i = 0; i < n - 1; ++ i){
            if (a[i] > a[i + 1]){
                flag = false;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
}
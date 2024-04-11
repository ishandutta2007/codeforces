#include <bits/stdc++.h>

const int N = 110;

int a[N];

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; ++ i){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int max = *std::max_element(a, a + n);
        if (max * 2 > sum){
            puts("T");
        }
        else{
            puts(sum & 1 ? "T" : "HL");
        }
    }
    return 0;
}
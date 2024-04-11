#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int s;
        scanf("%d", &s);
        printf("%d\n", int(std::ceil(std::sqrt(s))));
    }
    return 0;
}
#include<bits/stdc++.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < b){
        puts("-1");
        return 0;
    }
    if (a == b){
        printf("%.10lf\n", 1.0 * a);
        return 0;
    }
    printf("%.10lf\n", std::min(0.5 * (a + b) / ((a + b) / (2 * b)), 0.5 * (a - b) / ((a - b) / (2 * b))));
    return 0;
}
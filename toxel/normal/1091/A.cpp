#include<bits/stdc++.h>

int main(){
    int y, b, r;
    scanf("%d%d%d", &y, &b, &r);
    int x = std::min(y, std::min(b - 1, r - 2));
    printf("%d\n", 3 * x + 3);
    return 0;
}
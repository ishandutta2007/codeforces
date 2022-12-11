#include<bits/stdc++.h>

int main(){
    int w1, h1, w2, h2;
    scanf("%d%d%d%d", &w1, &h1, &w2, &h2);
    printf("%d\n", std::max(w1, w2) * 2 + (h1 + h2) * 2 + 4);
    return 0;
}
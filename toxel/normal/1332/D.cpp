#include <bits/stdc++.h>

const int HIGHBIT = 17;

int main(){
    int k;
    scanf("%d", &k);
    printf("2 3\n");
    int max = (1 << (HIGHBIT + 1)) - 1;
    printf("%d %d %d\n", max, k, 0);
    printf("%d %d %d\n", 1 << HIGHBIT, max, k);
}
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n < 4) {
        printf("NO\n");
    } else {
        printf("YES\n");
        if (n % 2 == 1) {
            printf("3 * 5 = 15\n");
            printf("2 * 4 = 8\n");           
            printf("15 + 8 = 23\n");
            printf("23 + 1 = 24\n");
            for (int i = 6; i <= n; i += 2) {
                printf("%d - %d = 1\n", i + 1, i);
                printf("24 * 1 = 24\n");
            }
        } else {
            printf("2 * 4 = 8\n");           
            printf("8 * 3 = 24\n");
            printf("24 * 1 = 24\n");
            for (int i = 5; i <= n; i += 2) {
                printf("%d - %d = 1\n", i + 1, i);
                printf("24 * 1 = 24\n");
            }
        }
    }
    return 0;
}
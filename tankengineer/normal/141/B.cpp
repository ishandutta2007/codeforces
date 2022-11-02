#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int a, x, y;
    scanf("%d%d%d", &a, &x, &y);
    if (y % a == 0) {
        printf("-1\n");
    } else {
        int t = y / a;
        if (t == 0) {
            if (2 * x < a && 2 * x > -a) {
                printf("1\n");
            } else {
                printf("-1\n");
            }
        } else {
            if (t % 2 == 1) {
                if (2 * x < a && 2 * x > -a) {
                    printf("%d\n", t / 2 * 3 + 2);
                } else {
                    printf("-1\n");
                }
            } else {
                if (x < 0 && x > -a) {
                    printf("%d", (t / 2 - 1) * 3 + 3);
                } else if (x > 0 && x < a) {
                    printf("%d", (t / 2 - 1) * 3 + 4);
                } else {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}
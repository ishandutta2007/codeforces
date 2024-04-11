#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int r1, r2, c1, c2, d1, d2;
    scanf("%d%d%d%d%d%d", &r1, &r2, &c1, &c2, &d1, &d2);
    for (int a = 1; a <= 9; ++a) {
        for (int b = 1; b <= 9; ++b) {
            for (int c = 1; c <= 9; ++c) {
                for (int d = 1; d <= 9; ++d) {
                    if (a == b || a == c || a == d ||
                        b == c || b == d || c == d) {
                            continue;
                    }
                    if (a + b == r1 && c + d == r2 &&
                        a + c == c1 && b + d == c2 &&
                        a + d == d1 && b + c == d2) {
                            printf("%d %d\n%d %d\n", a, b, c, d);
                            return 0;
                        }
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
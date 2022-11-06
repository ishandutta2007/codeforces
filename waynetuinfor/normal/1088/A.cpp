#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; scanf("%d", &x);
    for (int a = 1; a <= x; ++a) {
        for (int b = 1; b <= a; ++b) {
            if (b % a != 0) continue;
            if (a * b <= x) continue;
            if (b / a >= x) continue;
            printf("%d %d\n", a, b);
            return 0;
        }
    }
    puts("-1");
}
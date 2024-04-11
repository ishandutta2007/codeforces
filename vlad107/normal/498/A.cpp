#include <stdio.h>
#include <iostream>

using namespace std;

int sign(long long u) {
    if (u < 0) return -1;
    if (u > 0) return +1;
    return 0;
}

int main() {
//  freopen("input.txt", "r", stdin);
    long long ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        ans += (sign(a * ax + b * ay + c) != sign(a * bx + b * by + c));
    }
    printf("%d\n", ans);
}
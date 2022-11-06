#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r; scanf("%d%d", &n, &r);
    double deg = sin(acos(-1) / n);
    printf("%.20lf\n", (r * deg) / (1 - deg));
}
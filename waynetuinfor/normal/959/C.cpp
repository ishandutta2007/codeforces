#include <bits/stdc++.h>
using namespace std;

void solve1(int n) {
    if (n < 6) return puts("-1"), void();
    puts("1 2"); puts("1 3"); puts("1 4");
    for (int i = 5; i <= n; ++i) printf("4 %d\n", i);
}

void solve2(int n) {
    for (int i = 2; i <= n; ++i) printf("1 %d\n", i);
}

int main() {
    int n; scanf("%d", &n);
    solve1(n);
    solve2(n);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int x, ans = 0;

    printf("?");
    for(int i = 0; i < 100; ++i)
        printf(" %d", i);
    puts("");
    fflush(stdout);

    scanf("%d", &x);
    ans += x & 16256;

    printf("?");
    for(int i = 1; i <= 100; ++i)
        printf(" %d", (i<<7));
    puts("");
    fflush(stdout);

    scanf("%d", &x);
    ans += x & 127;

    printf("! %d\n", ans);
    fflush(stdout);

    return 0;
}
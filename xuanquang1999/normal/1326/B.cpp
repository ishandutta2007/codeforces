#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
int n, a[MAXN], b[MAXN];

int main() {    
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);

    a[1] = b[1];
    int maxA = b[1];

    for(int i = 2; i <= n; ++i) {
        a[i] = maxA + b[i];
        maxA = max(maxA, a[i]);
    }

    for(int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    puts("");

    return 0;
}
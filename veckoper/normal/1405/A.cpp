#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, Case, a[N];
int main() {
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", a + i);
        for (int i = n; i; --i) printf("%d ", a[i]);
        puts("");
    }
    return 0;
}
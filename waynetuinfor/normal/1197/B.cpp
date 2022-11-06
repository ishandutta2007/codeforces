#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int p = max_element(a, a + n) - a;
    for (int i = 1; i < p; ++i) {
        if (a[i] < a[i - 1]) {
            puts("NO");
            return 0;
        }
    }
    for (int i = p; i < n - 1; ++i) {
        if (a[i] < a[i + 1]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
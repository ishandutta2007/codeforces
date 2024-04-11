#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d%d", &n, &k);
        if (n % k == 0) {
            printf("%d\n", n);
        } else {
            int a = n / k, b = n / k + 1, c = n % k;
            if (c <= k / 2) printf("%d\n", n);
            else printf("%d\n", n - (c - k / 2));
        }
    }
}
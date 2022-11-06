#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    long long s = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), s += a[i];
    long long z = 0;
    for (int i = 0; i < n; ++i) {
        z += a[i];
        if (z * 2 >= s) return 0 * printf("%d\n", i + 1);
    }
    return 0;
}
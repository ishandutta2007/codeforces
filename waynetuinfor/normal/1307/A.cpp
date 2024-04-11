#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, d; scanf("%d%d", &n, &d);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        while (d--) {
            for (int i = 1; i < n; ++i) {
                if (a[i] > 0) {
                    a[i - 1]++;
                    a[i]--;
                    break;
                }
            }
        }
        printf("%d\n", a[0]);
    }
}
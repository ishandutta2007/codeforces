#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] | a[i];
    int suff = 0, ans = -1, z = -1;
    for (int i = n - 1; i >= 0; --i) {
        int g = a[i] - (a[i] & (pref[i] | suff));
        if (g > ans) {
            ans = g;
            z = i;
        }
        suff |= a[i];
    }
    printf("%d ", a[z]);
    for (int i = 0; i < n; ++i) {
        if (i != z) printf("%d ", a[i]);
    }
    puts("");
}
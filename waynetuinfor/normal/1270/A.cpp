#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k1, k2; scanf("%d%d%d", &n, &k1, &k2);
        vector<int> a(k1), b(k2);
        for (int i = 0; i < k1; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < k2; ++i) scanf("%d", &b[i]);
        if (*max_element(a.begin(), a.end()) > *max_element(b.begin(), b.end())) puts("YES");
        else puts("NO");
    }
}
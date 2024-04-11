#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[103];
int skip(int i) {
    if(i == s) return i + 1;
    return i;
}
int main() {
    int i, j;
    scanf(" %d", &n);
    for(i = 0; i < n; i++)
        scanf(" %d", &a[i]);
    int mn = INT_MAX;
    for(s = 1; s < n - 1; s++) {
        int mx = 0;
        for(i = 0; i < n - 1; i = skip(i+1)) {
            mx = max(mx, a[skip(i+1)] - a[i]);
        }
        mn = min(mn, mx);
    }
    printf("%d\n", mn);
    return 0;
}
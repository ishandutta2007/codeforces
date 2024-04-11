#include <bits/stdc++.h>
using namespace std;
long long n, a[100007], dem, maxK;
int main() {
    scanf("%d", &n);
    scanf("%d", &a[0]);
    dem = 1;
    maxK = 1;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] >= a[i-1]) ++dem;
        else {
            maxK = max(maxK, dem);
            dem = 1;
        }
    }
    maxK = max(maxK, dem);
    printf("%d", maxK);
    return 0;
}
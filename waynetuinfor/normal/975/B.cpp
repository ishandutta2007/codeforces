#include <bits/stdc++.h>
using namespace std;

long long a[20];

int main() {
    for (int i = 1; i <= 14; ++i) scanf("%lld", &a[i]);
    long long ans = 0;
    for (int i = 1; i <= 14; ++i) if (a[i] > 0) {
        long long x = a[i] / 14;
        vector<long long> b(a, a + 20);
        b[i] = 0;
        for (int j = 1; j <= 14; ++j) b[j] += x;
        long long y = a[i] % 14;
        for (int j = i + 1; y; ) {
            if (j == 15) j = 1;
            b[j]++;
            --y;
            j++;
        }
        long long c = 0;
        for (int j = 1; j <= 14; ++j) if (b[j] % 2 == 0) c += b[j];
        ans = max(ans, c);
    }  
    printf("%lld\n", ans);
    return 0;
}
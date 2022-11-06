#include <bits/stdc++.h>
using namespace std;

const int magic = 100;
char s[100];

int main() {
    srand(clock() + time(nullptr));
    long long n; int k;
    scanf("%lld%d", &n, &k);
    long long l = 1, r = n;
    while (true) {
        if (r - l + 1 <= magic || r - l + 1 <= 6 * k) {
            long long x = l + rand() % (r - l + 1);
            printf("%lld %lld\n", x, x);
            fflush(stdout);
            scanf("%s", s);
            if (s[0] == 'Y') return 0;
        } else {
            long long m = (l + r) >> 1;
            printf("%lld %lld\n", l, m);
            fflush(stdout);
            scanf("%s", s);
            if (s[0] == 'Y') r = m;
            else l = m + 1;
        }
        l = max(1ll, l - k);
        r = min(n, r + k);
    }
    return 0;
}
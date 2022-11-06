#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

int main() {
    long long l, r; int k; scanf("%lld %lld %d", &l, &r, &k);
    if (k < 4) {
        if (k == 1) {
            printf("%lld\n1\n%lld\n", l, l);
            return 0;
        }
        long long tl = l;
        while (tl % 2 == 1) ++tl;
        long long tr = tl;
        while (tr % 2 == 0) ++tr;
        if (k == 3) {
            int p = 0;
            while ((1ll << p) - 1 < l) ++p;
            long long a = (1ll << p) - 1, b = (1ll << p) + (1ll << (p - 1)), c = (a ^ b);
            if (a >= l && a <= r && b >= l && b <= r && c >= l && c <= r && (a ^ b ^ c) == 0) {
                printf("%lld\n3\n%lld %lld %lld\n", a ^ b ^ c, a, b, c);
                return 0;
            }
        }  
        if (tr <= r) printf("%lld\n2\n%lld %lld\n", tl ^ tr, tl, tr);
        else if ((l ^ r) < l) printf("%lld\n2\n%lld %lld\n", l ^ r, l, r);
        else printf("%lld\n1\n%lld\n", l, l);
        return 0;
    }
    long long tl = l;
    while (tl % 4) ++tl;
    long long tr = tl;
    while (tr % 4 != 3) ++tr;
    if (tr <= r) {
        printf("0\n4\n%lld %lld %lld %lld\n", tl, tl + 1, tl + 2, tl + 3);
        return 0;
    } 
    int p = r - l + 1, bmask = -1;
    long long ans = inf;
    for (int i = 1; i < (1 << p); ++i) {
        long long x = 0;
        for (int j = 0; j < p; ++j) {
            if ((1 << j) & i) x ^= (l + j);
        }
        if (x < ans) ans = x, bmask = i;
    } 
    vector<long long> v;
    for (int i = 0; i < p; ++i) if ((1 << i) & bmask) v.push_back(l + i);
    printf("%lld\n%d\n", ans, v.size());
    for (long long i : v) printf("%lld ", i); puts("");
    return 0;
}
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a ? a : b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, q;
        scanf("%d%d%d", &a, &b, &q);
        if (a == b) {
            while (q--) {
                long long l, r;
                scanf("%lld%lld", &l, &r);
                printf("0 ");
            }
            printf("\n");
            continue;
        }
        if (a < b) swap(a, b);
        int md = a * b / gcd(a, b);
        long long l, r;
        long long prev, first, last;
        while (q--) {
            long long ans = 0;
            scanf("%lld%lld", &l, &r);
            prev = ((l - 1) / md) * md;
            ans += max(min(prev + a - 1 - l + 1, r - l + 1), (long long)0);
//            printf("first %d\n", ans);
            first = (l - 1) / md + 1;
            last = r / md;
//            printf("f = %d, l = %d", first, last);
            ans += max((long long)0, (last - first) * a);
//            printf("second %d\n", ans);
            if (last != prev / md) ans += min((r - last * md + 1), (long long)a);
//            printf("third %d\n", ans);
            printf("%lld ", r - l + 1 - ans);
        }
        printf("\n");
    }
    return 0;
}
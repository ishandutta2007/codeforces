#include <cstdio>
long long n, m, k, f, e;
int main () {
    scanf ("%I64d%I64d%I64d", &n, &m, &k);
    e = n * m;
    while (f + 1 < e){
        long long mid = f + e >> 1, t = 0;
        for (long long i = 1; i <= n; i++)
            t += (mid / i) > m ? m : mid / i;
        if (t >= k) e = mid;
        else f = mid;
    }
    printf ("%I64d", e);
}
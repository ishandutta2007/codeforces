#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int a[maxn], b[maxn];
long long af[maxn], bf[maxn], ab[maxn], bb[maxn];
long long afp[maxn], bfp[maxn], abp[maxn], bbp[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i) {
        af[i] = af[i - 1] + a[i];
        bf[i] = bf[i - 1] + b[i];
        afp[i] = afp[i - 1] + i * 1ll * a[i];
        bfp[i] = bfp[i - 1] + i * 1ll * b[i];
    }
    for (int i = n; i >= 1; --i) {
        ab[i] = ab[i + 1] + a[i];
        bb[i] = bb[i + 1] + b[i];
        abp[i] = abp[i + 1] + (n - i + 1) * 1ll * a[i];
        bbp[i] = bbp[i + 1] + (n - i + 1) * 1ll * b[i];
    }
    long long ans = 0;
    long long cur = 0;
    int z = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            cur += a[i] * 1ll * z;
            long long tans = cur + afp[n] - afp[i] + (z - i) * 1ll * (af[n] - af[i]);
            int tz = z + n - i;
            tans += tz * 1ll * bb[i] + bbp[i];
            // printf("tans = %lld\n", tans);
            // printf("cur = %lld\n", cur);
            ans = max(ans, tans);
            ++z;
            cur += b[i] * 1ll * z;
            tans = cur + bfp[n] - bfp[i] + (z - i) * 1ll * (bf[n] - bf[i]);
            tz = z + n - i;
            tans += tz * 1ll * ab[i + 1] + abp[i + 1];
            // printf("tans = %lld\n", tans);
            // printf("cur = %lld\n", cur);
            ans = max(ans, tans);
            ++z;
        } else {
            cur += b[i] * 1ll * z;
            long long tans = cur + bfp[n] - bfp[i] + (z - i) * 1ll * (bf[n] - bf[i]);
            int tz = z + n - i;
            tans += tz * 1ll * ab[i] + abp[i];
            // printf("tans = %lld\n", tans);
            // printf("cur = %lld\n", cur);
            ans = max(ans, tans);
            ++z;
            cur += a[i] * 1ll * z;
            tans = cur + afp[n] - afp[i] + (z - i) * 1ll * (af[n] - af[i]);
            tz = z + n - i;
            tans += tz * 1ll * bb[i + 1] + bbp[i + 1];
            ans = max(ans, tans);
            // printf("tans = %lld\n", tans);
            // printf("cur = %lld\n", cur);
            ++z;
        }
    }
    printf("%lld\n", ans);
}
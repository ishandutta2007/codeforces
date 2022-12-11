#include <bits/stdc++.h>
using namespace std;

const long double PI = acos(-1.0L);

void fft(long double *r, long double *im, int N, bool f) {
    for (int i = 1, j = 0; i < N; i++) {
        int k; for (k = N >> 1; j >= k; k >>= 1) j -= k;
        j += k; if (i < j) swap(r[i], r[j]), swap(im[i], im[j]);
    }
    for (int i = 1; i < N; i <<= 1) {
        long double w = PI / i; if (f) w = -w;
        long double c = cos(w), s = sin(w);
        for (int j = 0; j < N; j += i << 1) {
            long double yr = 1, yi = 0;
            for (int k = 0; k < i; k++) {
                long double zr = r[i + j + k] * yr - im[i + j + k] * yi;
                long double zi = r[i + j + k] * yi + im[i + j + k] * yr;
                r[i + j + k] = r[j + k] - zr;
                im[i + j + k] = im[j + k] - zi;
                r[j + k] += zr; im[j + k] += zi;
                tie(yr, yi) = make_pair(yr * c - yi * s, yr * s + yi * c);
            }
        }
    }
}    

// Compute Poly(a)*Poly(b), write to r; Indexed from 0
// O(n*logn)
int mult(int *a, int n, int *b, int m, long long *r) {
    const int maxn = 1048576;
    static long double ra[maxn], rb[maxn], ia[maxn], ib[maxn];
    int fn = 1;
    while (fn < n + m) fn <<= 1; // n + m: interested length
    for (int i = 0; i < n; ++i) ra[i] = a[i], ia[i] = 0;
    for (int i = n; i < fn; ++i) ra[i] = ia[i] = 0;
    for (int i = 0; i < m; ++i) rb[i] = b[i], ib[i] = 0;
    for (int i = m; i < fn; ++i) rb[i] = ib[i] = 0;
    fft(ra, ia, fn, false);
    fft(rb, ib, fn, false);
    for (int i = 0; i < fn; ++i) {
        long double real = ra[i] * rb[i] - ia[i] * ib[i];
        long double imag = ra[i] * ib[i] + rb[i] * ia[i];
        ra[i] = real, ia[i] = imag;
    }
    fft(ra, ia, fn, true);
    for (int i = 0; i < fn; ++i) r[i] = round(ra[i] / fn);
    return fn;
}

int dat[200005];
long long ans[200005];
long long ret[1048576];
int A[200005];
int B[200005];

void recur(int L, int R)
{
    if (R - L < 100)
    {
        for (int i = L; i <= R; i++)
        {
            int sum = 0;
            for (int j = i; j <= R; j++)
            {
                sum += dat[j];
                ans[sum]++;
            }
        }
        return;
    }

    int mid = (L + R) / 2;
    int lastA = 0, lastB = 0;

    memset(A, 0, 4 * (mid - L + 2));
    memset(B, 0, 4 * (R - mid + 2));

    for (int i = mid; i >= L; i--)
    {
        if (i != mid) lastA += dat[i];
        A[lastA]++;
    }

    for (int i = mid; i <= R; i++)
    {
        if (i != mid) lastB += dat[i];
        B[lastB]++;
    }
    
    memset(ret, 0, 8 * (R - L + 3));

    mult(A, lastA + 1, B, lastB + 1, ret);

    for (int i = 0; i <= R - L + 1; i++)
    {
        ans[i + dat[mid]] += ret[i];
    }

    recur(L, mid - 1);
    recur(mid + 1, R);
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dat[i]);
        dat[i] = (dat[i] < x);
    }

    recur(0, n - 1);

    for (int i = 0; i <= n; i++) printf("%lld ", ans[i]);
    printf("\n");
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef complex<double> cd;
double PI = 4 * atan(1.);

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int LOG = 20;
const int N = 1 << LOG;
const int NN = N + 5;
cd w[NN];
int rev[NN];

void initFFT()
{
    for (int i = 0; i < N; i++)
        w[i] = cd(cos(2 * PI * i / N), sin(2 * PI * i / N));
    rev[0] = 0;
    for (int mask = 1; mask < N; mask++) {
        int k = 0;
        while(((mask >> k) & 1) == 0) k++;
        rev[mask] = rev[mask ^ (1 << k)] ^ (1 << (LOG - 1 - k));
    }
}

cd F[2][NN];
void FFT(cd* A, int k)
{
    int L = 1 << k;
    for (int mask = 0; mask < L; mask++)
        F[0][rev[mask] >> (LOG - k)] = A[mask];
    int t = 0, nt = 1;
    for (int lvl = 0; lvl < k; lvl++) {
        int len = 1 << lvl;
        for (int st = 0; st < L; st += (len << 1))
            for (int i = 0; i < len; i++) {
                cd ad = F[t][st + len + i] * w[i << (LOG - 1 - lvl)];
                F[nt][st + i] = F[t][st + i] + ad;
                F[nt][st + len + i] = F[t][st + i] - ad;
            }
        swap(t, nt);
    }
    for (int i = 0; i < L; i++)
        A[i] = F[t][i];
    return;
}

cd A[NN], B[NN];
char s[NN];
int a[NN];
int ans[NN];
int n;

void solve()
{
    scanf("%d %s", &n, s);
    int k = 0;
    while((1 << k) < (2 * n + 3)) k++;
    if (k > 5) {
        int L = 1 << k;
        for (int i = 0; i < L; i++)
            A[i] = B[i] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'V')
                A[i] = 1;
            else if (s[i] == 'K')
                B[n - i] = 1;
        }
        FFT(A, k);
        FFT(B, k);
        for (int i = 0; i < L; i++)
            A[i] *= B[i];
        FFT(A, k);
        for (int i = 0; i < L; i++)
            a[i] = (int)(A[i].real() / L + 0.5);
        reverse(a + 1, a + L);
        for (int d = 1; d <= n; d++)
            ans[d] = 1;
        for (int d = 1; d < n; d++)
            if (a[n - d] + a[n + d] > 0)
                ans[d] = 0;
    } else {
        for (int d = 1; d <= n; d++) {
            ans[d] = 1;
            for (int i = 0; i + d < n; i++) {
                if (s[i] != s[i + d] && s[i] != '?' && s[i + d] != '?')
                    ans[d] = 0;
            }
        }
    }
    int cnt = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = x + x; y <= n; y += x)
            ans[x] &= ans[y];
        cnt += ans[x];
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
        if (ans[i])
            printf("%d ", i);
    printf("\n");
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    initFFT();

    int t;
    scanf("%d", &t);
    while(t--) solve();

    return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <complex>
using namespace std;

#define N 524288
typedef complex<double> cp;
typedef double db;

const cp II(0,1);
cp E[N];

int n, x;
int a[N];
long long A[N], B[N];

void fft(int n, db t, cp *a) {
  for (int m = n; m >= 2; t *= 2) {
    int h = m/2;
    for (int i = 0; i < h; i ++)
      E[i] = exp(i*t*II);
    for (int j = 0; j < n; j += m)
      for (int i = 0; i < h; i ++) {
        cp x = a[j+i]-a[j+i+h];
        a[j+i] += a[j+i+h];
        a[j+i+h] = E[i]*x;
      }
    m = h;
  }
  int i = 0;
  for (int j = 1; j < n-1; j ++) {
    for (int k = n/2; k > (i^=k); k /= 2);
    if (j < i) swap(a[i], a[j]);
  }
}

cp aa[N], bb[N];
cp s0[N];

void mul(long long* a, long long* b, int n) {
  for (int i = 0; i < n; i ++) {
    aa[i] = a[i];
    bb[i] = b[i];
  }
  memset(aa+n, 0, sizeof(cp)*n);
  memset(bb+n, 0, sizeof(cp)*n);
  fft(n*2, M_PI/n, aa);
  fft(n*2, M_PI/n, bb);
  for (int i = 0; i < n*2; i ++) {
    s0[i] = aa[i]*bb[i];
  }
  fft(n*2, -M_PI/n, s0);
  for (int i = 0; i < 2*n; i ++) {
    b[i] = (long long)(s0[i].real()/(n*2)+0.5);
  }
}

int main() {
	scanf("%d%d", &n, &x);
	long long ans0 = 0;
	int pre = 0;
	for (int i = 1; i <= n; i++) {
		int y;
		scanf("%d", &y);
		if (y < x)
			a[i] = a[i - 1] + 1, pre = i;
		else
			a[i] = a[i - 1], ans0 += i - pre;
	}
	for (int i = 0; i <= n; i++)
		A[a[i]] += 1, B[n - a[i]] += 1;
	mul(A, B, 262144);
	printf("%I64d ", ans0);
	for (int i = 1; i <= n; i++)
		printf("%I64d ", B[i + n]);
	printf("\n");
}
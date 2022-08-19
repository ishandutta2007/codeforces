#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const double PI = 4 * atan(1);

typedef complex<double> cd;

//const int LOG = 6;
const int LOG = 19;
const int N = 1 << LOG;
const int NN = N + 5;
cd w[NN];
int rev[NN];
int a[NN];
int n, x;

cd A[NN], B[NN];

void initFFT() {
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
void FFT(cd* A) {
	for (int i = 0; i < N; i++)
		F[0][rev[i]] = A[i];
	int t = 0, nt = 1;
	for (int lvl = 0; lvl < LOG; lvl++) {
		//cerr << lvl << endl;
		int len = 1 << lvl;
		for (int st = 0; st < N; st += (1 << (lvl + 1)))
			for (int i = 0; i < len; i++) {
				cd ad = F[t][st + len + i] * w[i << (LOG - 1 - lvl)];
				F[nt][st + i] = F[t][st + i] + ad;
				F[nt][st + len + i] = F[t][st + i] - ad;
			}
		swap(t, nt);
	}
	for (int i = 0; i < N; i++)
		A[i] = F[t][i];
}

ll ans[NN];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	initFFT();

	int x;
	scanf("%d%d", &n, &x);
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		int y;
		scanf("%d", &y);
		a[i + 1] = a[i] + (int)(y < x);
	}

	for (int i = 0; i <= n; i++) {
		A[a[i]] += 1;
		B[n - a[i]] += 1;
	}
//	cerr << "before FFT" << endl;
	FFT(A);
	FFT(B);
	for (int i = 0; i < N; i++)
		A[i] *= B[i];
	FFT(A);
//	cerr << "all FFT" << endl;
	for (int i = 0; i < N; i++)
		ans[i] = (ll)(A[i].real() / N + 0.5);
	reverse(ans + 1, ans + N);
	for (int i = 0; i <= n; i++)
		ans[i] = ans[n + i];
	ans[0] = 0;
	int L = 0;
	while(L <= n) {
		int R = L;
		while(R <= n && a[R] == a[L]) R++;
		ans[0] += (ll)(R - L) * (R - L - 1) / 2;
		L = R;
	}
	for (int i = 0; i <= n; i++)
		printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}
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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100100;
const int A = 26;
//const int A = 5;
const int K = 17;
const int M = (1 << 26) + 7;
unsigned char ppc[M];
int p2[N];
int sparse[K][N];
int nearLeft[N][A], nearRight[N][A];
pii nearLeftSort[N][A], nearRightSort[N][A];
ll jumpLeft[N][K][2];
ll jumpRight[N][K][2];
ll ANS;
int n;
char s[N];
int a[N];
int curSegm[N][2];
int curIter[N];

int getMask(int l, int r) {
	int k = p2[r - l];
	return sparse[k][l] | sparse[k][r - (1 << k)];
}

void solve(int P) {
//	eprintf("solve %d\n", P);
//	eprintf("segms\n");
//	for (int i = 0; i < n; i++)
//		eprintf("%d %d\n", curSegm[i][0], curSegm[i][1]);
	for (int i = 0; i < n; i++) {
		if (jumpLeft[i][0][0] == 0) continue;
		int c = nearRightSort[i - 1][P - 1].second;
		jumpLeft[i][0][0] = min((int)jumpLeft[i][0][0], nearLeft[i][c]);
	}
	for (int i = 1; i <= n; i++) {
		if (jumpRight[i][0][0] == n) continue;
		int c = nearLeftSort[i][P - 1].second;
		jumpRight[i][0][0] = max((int)jumpRight[i][0][0], nearRight[i - 1][c] + 1);
	}
	for (int i = 0; i <= n; i++) {
		jumpLeft[i][0][0] = max(0, (int)jumpLeft[i][0][0]);
		jumpRight[i][0][0] = min((int)jumpRight[i][0][0], n);
		jumpLeft[i][0][1] = jumpLeft[i][0][0];
		jumpRight[i][0][1] = jumpRight[i][0][0];
	}
/*
	for (int i = 0; i <= n; i++)
		eprintf("%d ", (int)jumpLeft[i][0][0]);
	eprintf("\n");
	for (int i = 0; i <= n; i++)
		eprintf("%d ", (int)jumpRight[i][0][0]);
	eprintf("\n");
*/
	for (int k = 0; k < K - 1; k++) {
		for (int i = 0; i <= n; i++) {
			int w = jumpLeft[i][k][0];
			jumpLeft[i][k + 1][0] = jumpLeft[w][k][0];
			jumpLeft[i][k + 1][1] = jumpLeft[i][k][1] + jumpLeft[w][k][1];
		}
		for (int i = 0; i <= n; i++) {
			int w = jumpRight[i][k][0];
			jumpRight[i][k + 1][0] = jumpRight[w][k][0];
			jumpRight[i][k + 1][1] = jumpRight[i][k][1] + jumpRight[w][k][1];
		}
	}
	for (int i = 0; i < n; i++) {
		int mask = getMask(curSegm[i][0], curSegm[i][1]);
		if ((int)ppc[mask] != P) continue;
		if (curIter[i] == n) continue;
		for (int k = K - 1; k >= 0; k--) {
			if (curIter[i] + (1 << k) >= n) continue;
			int l = jumpLeft[curSegm[i][0]][k][0], r = jumpRight[curSegm[i][1]][k][0];
			if ((int)ppc[getMask(l, r)] != P) continue;
			curIter[i] += 1 << k;
			ANS += jumpLeft[curSegm[i][0]][k][1];
			ANS -= jumpRight[curSegm[i][1]][k][1];
			curSegm[i][0] = l;
			curSegm[i][1] = r;
		}
		curIter[i]++;
//		eprintf("%d %d\n", curSegm[i][0], curSegm[i][1]);
		ANS += jumpLeft[curSegm[i][0]][0][1];
		ANS -= jumpRight[curSegm[i][1]][0][1];
		curSegm[i][0] = jumpLeft[curSegm[i][0]][0][0];
		curSegm[i][1] = jumpRight[curSegm[i][1]][0][0];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int mask = 1; mask < M; mask++)
		ppc[mask] = ppc[mask >> 1] + (mask & 1);

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		a[i] = (int)(s[i] - 'a');
	for (int i = 0; i < n; i++)
		sparse[0][i] = 1 << a[i];
	for (int k = 0; k < K - 1; k++)
		for (int i = 0; i + (1 << (k + 1)) <= n; i++)
			sparse[k + 1][i] = sparse[k][i] | sparse[k][i + (1 << k)];

	for (int c = 0; c < A; c++) {
		nearLeft[0][c] = -1;
		nearRight[n - 1][c] = n;
	}
	for (int i = 1; i < n; i++) {
		for (int c = 0; c < A; c++)
			nearLeft[i][c] = nearLeft[i - 1][c];
		nearLeft[i][a[i - 1]] = i - 1;
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int c = 0; c < A; c++)
			nearRight[i][c] = nearRight[i + 1][c];
		nearRight[i][a[i + 1]] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < A; c++) {
			nearLeftSort[i][c] = mp(nearLeft[i][c], c);
			nearRightSort[i][c] = mp(nearRight[i][c], c);
		}
		sort(nearLeftSort[i], nearLeftSort[i] + A);
		reverse(nearLeftSort[i], nearLeftSort[i] + A);
		sort(nearRightSort[i], nearRightSort[i] + A);
	}
	ANS = (ll)n * n * n - n;
	for (int i = 0; i <= n; i++) {
		curSegm[i][0] = i;
		curSegm[i][1] = i + 1;
		curIter[i] = 1;
		jumpLeft[i][0][0] = i;
		jumpRight[i][0][0] = i;
	}
	for (int i = 1; i <= A; i++)
		solve(i);
	printf("%lld\n", ANS);

	return 0;
}
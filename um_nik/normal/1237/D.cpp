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

const int N = 300300;
const int LOG = 19;
int a[LOG][N], b[LOG][N];
int p2[N];
int n;
int ans[N];

int getMin(int l, int r) {
	int k = p2[r - l];
	return min(a[k][l], a[k][r - (1 << k)]);
}
int getMax(int l, int r) {
	int k = p2[r - l];
	return max(b[k][l], b[k][r - (1 << k)]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[0][i]);
	for (int i = n; i < 3 * n; i++)
		a[0][i] = a[0][i - n];
	for (int i = 0; i < 3 * n; i++)
		b[0][i] = a[0][i];
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i + (1 << (k + 1)) <= 3 * n; i++) {
			a[k + 1][i] = min(a[k][i], a[k][i + (1 << k)]);
			b[k + 1][i] = max(b[k][i], b[k][i + (1 << k)]);
		}


	int mx = a[0][n - 1];
	ans[n - 1] = -1;
	for (int i = n; i < 3 * n; i++) {
		if (2 * a[0][i] < mx) {
			ans[n - 1] = i - (n - 1);
			break;
		}
		mx = max(mx, a[0][i]);
	}
	if (ans[n - 1] == -1) {
		for (int i = 0; i < n; i++)
			printf("-1 ");
		printf("\n");
		return 0;
	}

	for (int i = n - 2; i >= 0; i--) {
		int l = 1, r = ans[i + 1] + 2;
		while(r - l > 1) {
			int x = (l + r) / 2;
			if (a[0][i] > 2 * getMin(i, i + x))
				r = x;
			else
				l = x;
		}
		ans[i] = l;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
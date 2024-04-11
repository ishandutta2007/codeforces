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

const int K = 10;
const int N = (int)1e6 + 3;
int a[N];
int b[K][N];

int f(int x) {
	int res = 1;
	while(x > 0) {
		if (x % 10 > 0) res *= x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int x = 1; x < 10; x++)
		a[x] = x;
	for (int x = 10; x < N; x++)
		a[x] = a[f(x)];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < K; j++)
			b[j][i] = b[j][i - 1];
		b[a[i]][i]++;
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		l--;
		printf("%d\n", b[k][r] - b[k][l]);
	}

	return 0;
}
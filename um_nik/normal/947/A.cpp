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

const int N = (int)1e6 + 3;
int d[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		d[i] = -1;
	for (int x = 2; x < N; x++) {
		if (d[x] != -1) continue;
		for (int y = x; y < N; y += x)
			d[y] = x;
	}
	int r;
	scanf("%d", &r);
	int l = r - d[r] + 1;
	int ans = r;
	for (int x = l; x <= r; x++) {
		int y = x - d[x] + 1;
		if (y >= 3) ans = min(ans, y);
	}
	printf("%d\n", ans);

	return 0;
}
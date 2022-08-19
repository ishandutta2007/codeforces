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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
int n, h;
int a[N][2];
int ans;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &h);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i][0], &a[i][1]);
	int r = 0;
	int curH = h;
	for (int l = 0; l < n; l++) {
		while(r < n - 1 && curH > a[r + 1][0] - a[r][1]) {
			curH -= a[r + 1][0] - a[r][1];
			r++;
		}
		ans = max(ans, a[r][1] - a[l][0] + curH);
		if (l < n - 1)
			curH += a[l + 1][0] - a[l][1];
	}
	printf("%d\n", ans);

	return 0;
}
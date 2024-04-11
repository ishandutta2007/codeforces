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

const int INF = (int)1e9;
const int N = 3222;
int n;
int ans = INF;
int a[N][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i][k]);
	for (int i = 0; i < n; i++) {
		int b = -1;
		int cost = a[i][1];
		for (int j = 0; j < i; j++) {
			if (a[j][0] >= a[i][0]) continue;
			if (b == -1 || a[b][1] > a[j][1])
				b = j;
		}
		if (b == -1) continue;
		cost += a[b][1];
		b = -1;
		for (int j = i + 1; j < n; j++) {
			if (a[j][0] <= a[i][0]) continue;
			if (b == -1 || a[b][1] > a[j][1])
				b = j;
		}
		if (b == -1) continue;
		cost += a[b][1];
		ans = min(ans, cost);
	}
	if (ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}
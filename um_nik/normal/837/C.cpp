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

const int N = 111;
int n, a, b;
int x[N][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i][0], &x[i][1]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) {
			int S = x[i][0] * x[i][1] + x[j][0] * x[j][1];
			for (int k = 0; k < 4; k++) {
				if (x[i][0] + x[j][0] <= a && x[i][1] <= b && x[j][1] <= b)
					ans = max(ans, S);
				if (x[i][0] <= a && x[j][0] <= a && x[i][1] + x[j][1] <= b)
					ans = max(ans, S);
				swap(x[j][0], x[j][1]);
				if (k % 2 == 1)
					swap(x[i][0], x[i][1]);
			}
		}
	printf("%d\n", ans);

	return 0;
}
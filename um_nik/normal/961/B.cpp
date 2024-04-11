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

const int N = 100100;
int ans;
int pplus;
int n, k;
int a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x) {
			pplus += a[i];
			a[i] = 0;
		}
	}
	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += a[i];
	ans = sum;
	for (int i = k; i < n; i++) {
		sum += a[i] - a[i - k];
		ans = max(ans, sum);
	}
	printf("%d\n", ans + pplus);

	return 0;
}
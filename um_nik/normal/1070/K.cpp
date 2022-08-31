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

const int N = 100100;
int n, k;
int a[N];
int ans[N];
int ansSz;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	int S = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		S += a[i];
	}
	if (S % k != 0) {
		printf("No\n");
		return 0;
	}
	S /= k;
	int cur = 0;
	int lst = 0;
	for (int i = 0; i <= n; i++) {
		if (cur > S) {
			printf("No\n");
			return 0;
		}
		if (cur == S) {
			ans[ansSz++] = i - lst;
			lst = i;
			cur = 0;
		}
		if (i == n) break;
		cur += a[i];
	}
	printf("Yes\n");
	for (int i = 0; i < k; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
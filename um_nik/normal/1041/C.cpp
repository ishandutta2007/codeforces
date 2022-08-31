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
int n, m, d;
pii a[N];
int ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	int k = 0;
	int r = 0;
	for (int l = 0; l < n; l++) {
		while(r < n && a[r].first - a[l].first <= d) r++;
		k = max(k, r - l);
	}
	printf("%d\n", k);
	for (int i = 0; i < n; i++)
		ans[a[i].second] = i % k;
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}
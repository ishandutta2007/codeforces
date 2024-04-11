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


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	int k = 0;
	vector<int> a, b;
	while((ll)(k + 1) * (k + 2) / 2 <= (ll)n + m) k++;
	for (int i = k; i > 0; i--) {
		if (i <= n) {
			n -= i;
			a.push_back(i);
		} else {
			m -= i;
			b.push_back(i);
		}
	}
	printf("%d\n", (int)a.size());
	for (int x : a)
		printf("%d ", x);
	printf("\n");
	printf("%d\n", (int)b.size());
	for (int x : b)
		printf("%d ", x);
	printf("\n");

	return 0;
}
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

const int N = (int)1e5;
ll ans[N];
int ansSz;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int x, d;
	ll y = 1;
	scanf("%d%d", &x, &d);
	d++;
	while(x > 0) {
		int k = 0;
		while(((1 << (k + 1)) - 1) <= x) k++;
		for (int i = 0; i < k; i++)
			ans[ansSz++] = y;
		y += d;
		x -= (1 << k) - 1;
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}
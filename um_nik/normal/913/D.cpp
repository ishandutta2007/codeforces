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

struct Item {
	int t, x, id;

	Item() : t(), x(), id() {}

	void scan(int _id) {
		scanf("%d%d", &x, &t);
		id = _id;
	}

	bool operator < (const Item &I) const {
		return t < I.t;
	}
};

const int N = 200200;
int n, T;
Item a[N];
int ans[N];
int ansSz;

bool solve(int k) {
	ansSz = 0;
	int sum = 0;
	for (int i = 0; ansSz < k && i < n; i++) {
		if (a[i].x < k) continue;
		sum += a[i].t;
		ans[ansSz++] = a[i].id;
	}
	return ansSz == k && sum <= T;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &T);
	for (int i = 0; i < n; i++)
		a[i].scan(i);
	sort(a, a + n);
	int l = 0, r = n + 1;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(x))
			l = x;
		else
			r = x;
	}
	solve(l);
	printf("%d\n%d\n", l, l);
	for (int i = 0; i < l; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}
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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
pii a[N];
int n;

map<int, int> mapchik;

void add(int x, int y) {
	mapchik[x] += y;
	if (mapchik[x] == 0)
		mapchik.erase(x);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++)
		add(a[i].first - a[i - 1].first, 1);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			add(a[i + 1].first - a[i].first, -1);
		} else if (i == n - 1) {
			add(a[i].first - a[i - 1].first, -1);
		} else {
			add(a[i].first - a[i - 1].first, -1);
			add(a[i + 1].first - a[i].first, -1);
			add(a[i + 1].first - a[i - 1].first, 1);
		}
		if ((int)mapchik.size() <= 1) {
			printf("%d\n", a[i].second + 1);
			return 0;
		}
		if (i == 0) {
			add(a[i + 1].first - a[i].first, 1);
		} else if (i == n - 1) {
			add(a[i].first - a[i - 1].first, 1);
		} else {
			add(a[i].first - a[i - 1].first, 1);
			add(a[i + 1].first - a[i].first, 1);
			add(a[i + 1].first - a[i - 1].first, -1);
		}
	}
	printf("-1\n");

	return 0;
}
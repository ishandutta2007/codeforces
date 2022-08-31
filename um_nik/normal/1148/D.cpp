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

const int N = 300300;
int n;
vector<pii> a, b;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < y)
			a.push_back(mp(x, i));
		else
			b.push_back(mp(x, i));
	}
	if ((int)a.size() > (int)b.size()) {
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		printf("%d\n", (int)a.size());
		for (pii t : a)
			printf("%d ", t.second + 1);
		printf("\n");
	} else {
		sort(b.begin(), b.end());
		printf("%d\n", (int)b.size());
		for (pii t : b)
			printf("%d ", t.second + 1);
		printf("\n");

	}

	return 0;
}
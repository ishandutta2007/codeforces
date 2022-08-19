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

pii query(vector<int> w) {
	printf("?");
	for (int x : w)
		printf(" %d", x + 1);
	printf("\n");
	fflush(stdout);
	int x, y;
	scanf("%d%d", &x, &y);
	return mp(x - 1, y);
}



int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	pii t;
	vector<int> w;

	w.clear();
	for (int i = 0; i < k; i++)
		w.push_back(i);
	t = query(w);
	int V = t.first, Vval = t.second;
	w[V] = k;
	t = query(w);
	int U = t.first, Uval = t.second;
	int ans = 1;
	for (int i = 0; i < k; i++) {
		if (w[i] == U) continue;
		int old = w[i];
		w[i] = V;
		t = query(w);
		if (t.second > Uval || (t.second == Uval && Vval < Uval))
			ans++;
		w[i] = old;
	}
	printf("! %d\n", ans);
	fflush(stdout);

	return 0;
}
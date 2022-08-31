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
int n, m;
set<pii> a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		a[i].insert(mp(-1, 0));
	while(m--) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		auto it = a[v].lower_bound(mp(w, -1));
		it--;
		int d = it->second + 1;
		it = a[u].lower_bound(mp(w + 1, -1));
		it--;
		if (it->second >= d) continue;
		while(true) {
			it = a[u].lower_bound(mp(w, -1));
			if (it == a[u].end()) break;
			if (it->second > d) break;
			a[u].erase(it);
		}
		a[u].insert(mp(w, d));
	}
	int ans = 0;
	for (int v = 1; v <= n; v++) {
		auto it = a[v].end();
		it--;
		ans = max(ans, it->second);
	}
	printf("%d\n", ans);

	return 0;
}
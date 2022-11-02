#include <cstdio>
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#	define debug(args...) //
#endif
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <set>
using namespace std;
const int MAX = 100009;
int n;
struct leg {
	int l, d;
	bool operator < (const leg &o) const { return l < o.l; }
};
leg ls[MAX];
int ac[MAX];
struct leg2 {
	int l, d;
	leg2() : l(0), d(0) {}
	leg2(leg &l) : l(l.l), d(l.d) {} 
	bool operator < (const leg2 &o) const { 
		if(d == o.d) return l > o.l;
		return d > o.d; 
	}
};
multiset<leg2> legs;

int solve(int k) {
	if(k < 0) return 0;
	int i;
	int low = (lower_bound(ls, ls + n, ls[k]) - ls) - 1;
	debug("sz %d\n", (int)legs.size());
	for(i = low + 1; i <= k; i++) {
		legs.erase(ls[i]);
		debug("sz after %d\n", (int)legs.size());
	}
	int a = solve(low) + ac[k] - ac[low];
	int b = ac[low];
	int x = k - low - 1;
	i = 0;
	debug("x %d %d\n", x, int(legs.size()));
	for(auto it = legs.begin(); i < x && it != legs.end(); i++, ++it) {
		debug("i %d\n", i);
		b -= it->d;
	}
	if(i < x) b = 0;
	debug("k %d a %d b %d\n", k, a, b);
	for(i = low + 1; i <= k; i++) {
		legs.insert(ls[i]);
		debug("sz after %d\n", (int)legs.size());
	}
	return min(a, b);
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &ls[i].l);
	for(i = 0; i < n; i++) {
		scanf("%d", &ls[i].d);
		legs.insert(ls[i]);
	}
	sort(ls, ls + n);
	// for(i = 0; i < n; i++)
	// 	printf("%d ", ls[i].l);
	// printf("\n");
	// for(i = 0; i < n; i++)
	// 	printf("%d ", ls[i].d);
	// printf("\n");
	ac[0] = ls[0].d;
	for(i = 1; i < n; i++)
		ac[i] = ac[i - 1] + ls[i].d;
	printf("%d\n", solve(n - 1));
	return 0;
}
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

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = (int)1e6 + 10;
int n;
int deg[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		deg[v]++;
		deg[u]++;
	}
	int L = 0;
	for (int i = 0; i < n; i++)
		if (deg[i] == 1)
			L++;
	int p = 1;
	for (int i = 0; i < n - L; i++)
		p = add(p, p);
	int ans = add(mult(L, add(p, p)), mult(n - L, p));
	printf("%d\n", ans);

	return 0;
}
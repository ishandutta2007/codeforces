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

const int N = 77;
int n;
int L, R;
int a[N];

int query(int x) {
	printf("%d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	L = 1;
	scanf("%d%d", &R, &n);
	R++;
	for (int i = 0; i < n; i++) {
		a[i] = query(L);
		if (a[i] == 0) return 0;
	}
	int it = 0;
	while(L < R) {
		int x = (L + R) / 2;
		int z = query(x) * a[it];
		it = (it + 1) % n;
		if (z == 0) return 0;
		if (z == 1)
			L = x;
		else
			R = x;
	}
	throw;

	return 0;
}
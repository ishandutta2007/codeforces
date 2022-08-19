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

int n;

int query(int x) {
	x = (x + 2 * n) % n + 1;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

bool bigQuery(int x) {
	int q1 = query(x), q2 = query(x + n / 2);
	if (q1 == q2) {
		x %= n;
		x++;
		printf("! %d\n", x);
		fflush(stdout);
		exit(0);
	}
	return q1 < q2;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	if (n % 4 == 2) {
		printf("! -1\n");
		fflush(stdout);
		return 0;
	}

	int L = 0, R = n / 2;
	if (!bigQuery(L)) {
		L += n / 2;
		R += n / 2;
	}
	while(R - L > 1) {
		int x = (L + R) / 2;
		if (bigQuery(x))
			L = x;
		else
			R = x;
	}
	throw;

	return 0;
}
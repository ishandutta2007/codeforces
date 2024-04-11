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

const int N = 200;
int a[N][N];

bool brute(int d) {
	//cerr << d << endl;
	if (d > 153) return true;
	for (int x = -2; x <= 2; x++) {
		for (int i = 0; i < d - 1; i++)
			a[d][i + 1] = a[d - 1][i];
		a[d][0] = 0;
		for (int i = 0; i < d - 1; i++)
			a[d][i] += x * a[d - 1][i];
		for (int i = 0; i < d - 1; i++)
			a[d][i] += a[d - 2][i];
		bool ok = true;
		for (int i = 0; i < d - 1; i++)
			ok &= abs(a[d][i]) <= 1;
		if (!ok) continue;
		if (brute(d + 1)) return true;
	}
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	a[0][0] = 0;
	a[1][0] = 1;
	
	brute(2);

	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	for (int i = 0; i <= n; i++)
		printf("%d ", a[n + 1][i]);
	printf("\n%d\n", n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", a[n][i]);
	printf("\n");

	return 0;
}
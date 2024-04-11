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

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, k;
	int ans;
	scanf("%d%d", &n, &k);
	ans = k;
	while(n--) {
		int x;
		scanf("%d", &x);
		ans = gcd(ans, x);
	}
	printf("%d\n", k / ans);
	for (int i = 0; i < k; i += ans)
		printf("%d ", i);
	printf("\n");

	return 0;
}
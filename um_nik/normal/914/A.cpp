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

bool isSq(int x) {
	for (int i = 0; i * i <= x; i++)
		if (x == i * i)
			return true;
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int ans = -(int)1e7;
	int n;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		if (!isSq(x))
			ans = max(ans, x);
	}
	printf("%d\n", ans);

	return 0;
}
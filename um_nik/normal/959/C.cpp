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



int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	if (n < 6) {
		printf("-1\n");
	} else {
		printf("1 2\n");
		printf("1 3\n");
		printf("1 4\n");
		for (int i = 5; i <= n; i++)
			printf("4 %d\n", i);
	}
	for (int i = 1; i < n; i++)
		printf("%d %d\n", i, i + 1);

	return 0;
}
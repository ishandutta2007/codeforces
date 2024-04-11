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

	int n, A, B;
	scanf("%d%d%d", &n, &A, &B);
	for (int k = 0; k * A <= n; k++) {
		int m = n - k * A;
		if (m % B != 0) continue;
		m /= B;
		int st = 1;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < A; j++)
				printf("%d ", st + (j + 1) % A);
			st += A;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < B; j++)
				printf("%d ", st + (j + 1) % B);
			st += B;
		}
		printf("\n");
		return 0;
	}
	printf("-1\n");

	return 0;
}
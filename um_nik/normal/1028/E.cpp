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

const int N = 200200;
int n;
ll a[N], b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	bool allEq = true;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
		allEq &= b[i] == b[0];
	}
	if (allEq) {
		if (b[0] == 0) {
			printf("YES\n");
			for (int i = 0; i < n; i++)
				printf("1 ");
			printf("\n");
		} else
			printf("NO\n");
		return 0;
	}

	int p = 0;
	for (int i = 0; i < n; i++)
		if (b[i] > b[p])
			p = i;
	while(p > 0 && b[p - 1] == b[p]) p--;
	if (p == 0 && b[n - 1] == b[0]) p = n - 1;
	while(p > 0 && b[p - 1] == b[p]) p--;

	a[p] = b[p];
	int q = p - 1;
	if (q < 0) q += n;
	a[q] = 2 * a[p] + b[q];
	for (int i = p - 2; i >= 0; i--)
		a[i] = a[i + 1] + b[i];
	a[n] = a[0];
	for (int i = (q == n - 1 ? n - 2 : n - 1); i > p; i--)
		a[i] = a[i + 1] + b[i];

	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%lld ", a[i]);
	printf("\n");

	return 0;
}
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

const int N = 100100;
int h[N];
int ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	h[1] = 1;
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		h[i] = h[x] + 1;
	}
	for (int i = 1; i <= n; i++)
		ans[h[i]] ^= 1;
	int sum = 0;
	for (int i = 0; i <= n; i++)
		sum += ans[i];
	printf("%d\n", sum);

	return 0;
}
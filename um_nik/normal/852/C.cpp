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

const int N = (int)1e6 + 10;
int n;
int a[N];
pii b[N];
int ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		b[i] = mp(a[i] + a[(i + 1) % n], i);
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		ans[b[i].second] = i;
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
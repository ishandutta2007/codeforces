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
int n;
int a[N];
int ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int r = 0;
	for (int i = 0; i < n; i++) {
		while(r < n && a[i] >= a[r]) r++;
		ans[r - i]++;
		ans[n - i]--;
	}
	for (int i = 1; i < n; i++)
		ans[i] += ans[i - 1];
	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, ans[i]);
	printf("%d\n", res);

	return 0;
}
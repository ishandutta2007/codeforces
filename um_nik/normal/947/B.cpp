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
ll a[N];
ll b[N];
ll sum[N];
int n;
ll ans[N];
ll c[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sum[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
		sum[i + 1] = sum[i] + b[i];
	}
	for (int i = 0; i < n; i++) {
		int l = i, r = n + 1;
		while(r - l > 1) {
			int m = (l + r) / 2;
			if (sum[m] - sum[i] <= a[i])
				l = m;
			else
				r = m;
		}
		r--;
		//printf("%d ", r);
		ans[r] += a[i] - (sum[r] - sum[i]);
		c[i]++;
		c[r]--;
	}
	//printf("\n");
	for (int i = 1; i <= n; i++)
		c[i] += c[i - 1];
	for (int i = 0; i < n; i++)
		printf("%lld ", b[i] * c[i] + ans[i]);
	printf("\n");

	return 0;
}
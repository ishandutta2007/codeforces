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
ll fenv[N];
void addFenv(int p) {
	for(; p < N; p |= p + 1)
		fenv[p]++;
}
ll getFenv(int r) {
	ll res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}
ll getSum(int l, int r) {
	return getFenv(r - 1) - getFenv(l - 1);
}

int a[N];
int n;
vector<int> b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] = min(a[i], n);
		b[min(i - 1, a[i])].push_back(i);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		addFenv(a[i]);
		for (int x : b[i])
			ans += getSum(x, n + 1);
	}
	printf("%lld\n", ans);

	return 0;
}
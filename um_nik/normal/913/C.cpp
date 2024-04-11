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

const ll INF = (ll)1e18 + 6;
const int N = 33;
int n;
ll a[N];
ll m;
ll ans = 0;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++)
		a[i] = min(a[i], 2 * a[i - 1]);
	for (int i = n - 2; i >= 0; i--)
		a[i] = min(a[i], a[i + 1]);
	ll ANS = INF;
	for (int i = n - 1; i >= 0; i--) {
		ans += a[i] * (m >> i);
		ANS = min(ANS, ans + a[i]);
		m %= (1LL << i);
	}
	printf("%lld\n", min(ANS, ans));

	return 0;
}
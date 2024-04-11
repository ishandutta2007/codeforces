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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
int n;
pll a[N];
ll ans = 0;
ll sum = 0;
multiset<ll> setik;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i].first);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i].second);
	sort(a, a + n);
	ll cur = -1;
	int p = 0;
	while(p < n || !setik.empty()) {
		if (setik.empty()) cur = a[p].first;
		while(p < n && a[p].first == cur) {
			sum += a[p].second;
			setik.insert(-a[p].second);
			p++;
		}
		sum += *setik.begin();
		setik.erase(setik.begin());
		ans += sum;
		cur++;
	}
	printf("%lld\n", ans);

	return 0;
}
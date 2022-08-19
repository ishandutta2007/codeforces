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

	ll p, k;
	scanf("%lld%lld", &p, &k);
	vector<ll> ans;
	while(p != 0) {
		ll x = p % k;
		while(x < 0) x += k;
		ans.push_back(x);
		p -= x;
		p /= k;
		p *= -1;
	}
	printf("%d\n", (int)ans.size());
	for (ll x : ans)
		printf("%lld ", x);
	printf("\n");

	return 0;
}
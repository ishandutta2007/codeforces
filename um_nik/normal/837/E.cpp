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

const int N = 45;
ll a[N];
int n;
ll b;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld", &b);
	n = 0;
	for (ll x = 2; x * x <= b; x++) {
		while(b % x == 0) {
			b /= x;
			a[n++] = x;
		}
	}
	if (b != 1)
		a[n++] = b;
	scanf("%lld", &b);
	ll ans = 0;
	while(b > 0) {
		int bst = -1;
		for (int i = 0; i < n; i++) {
			if (bst == -1 || b % a[i] < b % a[bst])
				bst = i;
		}
		if (bst == -1) {
			ans += b;
			b = 0;
			break;
		}
		swap(a[bst], a[n - 1]);
		ans += b % a[n - 1];
		b /= a[n - 1];
		n--;
	}
	printf("%lld\n", ans);

	return 0;
}
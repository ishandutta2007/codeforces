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

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

char s[10];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int ans = 1;
	int n;
	scanf("%d", &n);
	set<ll> L, M, R;
	while(n--) {
		ll x;
		scanf("%s %lld", s, &x);
		if (s[1] == 'D') {
			if (!L.empty() && x < *L.rbegin())
				L.insert(x);
			else if (!R.empty() && x > *R.begin())
				R.insert(x);
			else
				M.insert(x);
		} else {
			if (!L.empty() && x < *L.rbegin()) {
				printf("0\n");
				return 0;
			}
			if (!R.empty() && x > *R.begin()) {
				printf("0\n");
				return 0;
			}
			if (!L.empty() && x == *L.rbegin()) {
				L.erase(x);
				while(!M.empty()) {
					x = *M.begin();
					R.insert(x);
					M.erase(x);
				}
				continue;
			}
			if (!R.empty() && x == *R.begin()) {
				R.erase(x);
				while(!M.empty()) {
					x = *M.begin();
					L.insert(x);
					M.erase(x);
				}
				continue;
			}
			if (M.find(x) == M.end()) throw;
			ans = add(ans, ans);
			while(!M.empty()) {
				ll y = *M.begin();
				M.erase(y);
				if (y < x)
					L.insert(y);
				if (y > x)
					R.insert(y);
			}
		}
	}
	ans = mult(ans, (int)M.size() + 1);
	printf("%d\n", ans);

	return 0;
}
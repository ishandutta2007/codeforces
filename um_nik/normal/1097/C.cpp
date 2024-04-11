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

const int N = 500500;
char s[N];
int n;
int a[N][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	while(n--) {
		scanf("%s", s);
		int L = strlen(s);
		int bal = 0, minBal = 0;
		for (int i = 0; i < L; i++) {
			if (s[i] == '(')
				bal++;
			else
				bal--;
			minBal = min(minBal, bal);
		}
		if (bal < 0) {
			minBal = 0;
			bal = 0;
			for (int i = L - 1; i >= 0; i--) {
				if (s[i] == ')')
					bal++;
				else
					bal--;
				minBal = min(minBal, bal);
			}
			if (minBal >= 0)
				a[bal][1]++;
		} else if (bal == 0) {
			if (minBal >= 0) a[0][0]++;
		} else {
			if (minBal >= 0) a[bal][0]++;
		}
	}
	int ans = 0;
	ans += a[0][0] / 2;
	for (int i = 1; i < N; i++)
		ans += min(a[i][0], a[i][1]);
	printf("%d\n", ans);

	return 0;
}
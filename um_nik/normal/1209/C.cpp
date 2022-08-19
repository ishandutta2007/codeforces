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

const int A = 10;
const int N = 200200;
char s[N];
int n;
char ans[N];

bool solve(char x, char y) {
	char sy = y;
	for (int i = 0; i < n; i++) {
		if (s[i] >= y) {
			ans[i] = '2';
			y = s[i];
		} else if (s[i] >= x) {
			ans[i] = '1';
			x = s[i];
		} else return false;
	}
	if (x > sy) return false;
	ans[n] = '\0';
	printf("%s\n", ans);
	return true;
}

void solve() {
	scanf("%d", &n);
	scanf("%s", s);
	for (int x = 0; x < A; x++) {
		if (solve('0', '0' + x)) {
			return;
		}
	}
	printf("-\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}
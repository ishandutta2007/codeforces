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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 5050;
int n;
char s[N];
char p[N];
char ans[N];
int bst;

void solve() {
	scanf("%d", &n);
	scanf("%s", s);
	bst = 1;
	for (int i = 0; i < n; i++)
		ans[i] = s[i];
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i < n; i++)
			p[i] = s[i];
		rotate(p, p + k - 1, p + n);
		if ((n - k + 1) & 1) reverse(p + n - k + 1, p + n);
		int pos = 0;
		while(pos < n && p[pos] == ans[pos]) pos++;
		if (pos == n || ans[pos] < p[pos]) continue;
		bst = k;
		for (int i = 0; i < n; i++)
			ans[i] = p[i];
	}
	ans[n] = '\0';
	printf("%s\n%d\n", ans, bst);
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();


	return 0;
}
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 300300;
int n, m;
char s[N], p[N];
vector<int> a, b;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%s%s", &n, &m, s, p);
	int pos = 0;
	for (int i = 0; i < m; i++) {
		while(s[pos] != p[i]) pos++;
		assert(pos < n);
		a.push_back(pos);
		pos++;
	}
	pos = n - 1;
	for (int i = m - 1; i >= 0; i--) {
		while(s[pos] != p[i]) pos--;
		assert(pos >= 0);
		b.push_back(pos);
		pos--;
	}
	reverse(all(b));
	int ans = 0;
	for (int i = 0; i < m - 1; i++)
		ans = max(ans, b[i + 1] - a[i]);
	printf("%d\n", ans);

	return 0;
}
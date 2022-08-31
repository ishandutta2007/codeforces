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

const int N = 111;
int n, m;
char a[N][N];
char b[N][N];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int c = t ^ ((i + j) & 1);
				if (c == 0)
					b[i][j] = 'R';
				else
					b[i][j] = 'W';
			}
		bool ok = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ok &= a[i][j] == '.' || a[i][j] == b[i][j];
		if (!ok) continue;
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			b[i][m] = '\0';
			printf("%s\n", b[i]);
		}
		return;
	}
	printf("NO\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}
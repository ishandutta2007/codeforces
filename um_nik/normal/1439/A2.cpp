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
char s[N];
int a[N][N];
int b[2][2];
vector<vector<pii>> ans;

void addAns(vector<pii> x) {
	ans.push_back(x);
	for (pii t : x) {
		a[t.first][t.second] ^= 1;
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++)
			a[i][j] = (int)(s[j] == '1');
	}
	ans.clear();
	for (int x = n - 1; x >= 2; x--) {
		for (int y = m - 2; y >= 0; y--) {
			vector<pii> cur;
			for (int i = 0; i < 2; i++) {
				if (a[x][y + i]) cur.push_back(mp(x, y + i));
			}
			if (cur.empty()) continue;
			for (int i = 0; (int)cur.size() < 3; i++) {
				cur.push_back(mp(x - 1, y + i));
			}
			addAns(cur);
		}
	}
	for (int y = m - 1; y >= 2; y--) {
		vector<pii> cur;
		for (int i = 0; i < 2; i++) {
			if (a[i][y]) cur.push_back(mp(i, y));
		}
		if (cur.empty()) continue;
		for (int i = 0; (int)cur.size() < 3; i++) {
			cur.push_back(mp(i, y - 1));
		}
		addAns(cur);
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			b[i][j] = 0;
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++) {
			if (a[x][y] == 0) continue;
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					b[i][j] ^= 1;
			b[x][y] ^= 1;
		}
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++) {
			if (b[x][y] == 0) continue;
			vector<pii> cur;
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					if (i != x || j != y)
						cur.push_back(mp(i, j));
			addAns(cur);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			assert(!a[i][j]);
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++) {
		for (int j = 0; j < 3; j++)
			printf("%d %d ", ans[i][j].first + 1, ans[i][j].second + 1);
		printf("\n");
	}
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
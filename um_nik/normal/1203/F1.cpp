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

struct Item {
	int a, b;

	Item() : a(), b() {}
	
	void scan() {
		scanf("%d%d", &a, &b);
	}

	bool operator < (const Item &I) const {
		return a + b > I.a + I.b;
	}
};

const int N = 101;
const int C = 60600;
vector<Item> pos, neg;
int dp[N][C];
int X;
int n;

int solve() {
	int ans = 0;
	while(true) {
		bool fnd = false;
		for (int i = 0; !fnd && i < (int)pos.size(); i++) {
			if (pos[i].a <= X) {
				ans++;
				X += pos[i].b;
				fnd = true;
				swap(pos[i], pos.back());
				pos.pop_back();
			}
		}
		if (!fnd) break;
	}
	if (X >= C) throw;
	sort(neg.begin(), neg.end());
	int m = (int)neg.size();
	for (int i = 0; i <= m; i++)
		for (int j = 0; j < C; j++)
			dp[i][j] = -1;
	dp[0][X] = 0;
	for (int i = 0; i < m; i++)
		for (int x = 0; x < C; x++) {
			if (dp[i][x] == -1) continue;
			dp[i + 1][x] = max(dp[i + 1][x], dp[i][x]);
			if (x >= neg[i].a && x + neg[i].b >= 0)
				dp[i + 1][x + neg[i].b] = max(dp[i + 1][x + neg[i].b], dp[i][x] + 1);
		}
	int mx = 0;
	for (int i = 0; i < C; i++)
		mx = max(mx, dp[m][i]);
	return ans + mx;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &X);
	for (int i = 0; i < n; i++) {
		Item I;
		I.scan();
		if (I.b >= 0)
			pos.push_back(I);
		else
			neg.push_back(I);
	}
	if (solve() == n)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
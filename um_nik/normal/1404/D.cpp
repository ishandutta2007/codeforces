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

const int N = (int)1e6 + 7;
int a[N];
int b[N];
int g[N];
bool used[N];
vector<vector<int>> ans;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("First\n");
		for (int i = 0; i < 2 * n; i++)
			printf("%d ", 1 + (i % n));
		printf("\n");
		fflush(stdout);
	} else {
		printf("Second\n");
		fflush(stdout);
		for (int i = 1; i <= n; i++)
			a[i] = -1;
		for (int x = 1; x <= 2 * n; x++) {
			int z;
			scanf("%d", &z);
			b[x] = z;
			if (a[z] == -1) {
				a[z] = x;
			} else {
				g[a[z]] = x;
				g[x] = a[z];
			}
		}
		for (int x = 1; x <= 2 * n; x++) {
			if (used[x]) continue;
			vector<int> cur;
			int y = x;
			while(!used[y]) {
				cur.push_back(y);
				used[y] = 1;
				y = g[y];
				assert(!used[y]);
				used[y] = 1;
				if (y > n)
					y -= n;
				else
					y += n;
			}
			ans.push_back(cur);
		}
		ll sum = 0;
		for (int i = 0; i < (int)ans.size(); i++)
			for (int x : ans[i])
				sum += x;
		assert(sum % n == 0);
		if (sum % 2 != 0) {
			int p = 0;
			while((int)ans[p].size() % 2 == 0) p++;
			for (int &x : ans[p]) {
				if (x > n)
					x -= n;
				else
					x += n;
			}
		}
		vector<pii> res;
		for (int i = 0; i < (int)ans.size(); i++)
			for (int x : ans[i])
				res.push_back(mp(b[x], x));
		sort(all(res));
		for (pii w : res)
			printf("%d ", w.second);
		printf("\n");
		fflush(stdout);
	}
	int z;
	scanf("%d", &z);

	return 0;
}
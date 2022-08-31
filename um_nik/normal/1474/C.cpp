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

const int N = 2020;
const int C = (int)1e6 + 77;
int n;
int a[N];
vector<int> b[C];
int pos[C];
bool used[N];

bool mark(int x) {
	if (pos[x] == 0) return false;
	int z = b[x][--pos[x]];
	used[z] = 1;
	return true;
}

vector<int> solve(int x) {
	vector<int> res;
	for (int i = n - 1; i >= 0; i--) {
		if (used[i]) continue;
		int y = a[i];
		int z = x - y;
		if (z <= 0 || z > y) return {};
		if (!mark(y) || !mark(z)) return {};
		res.push_back(y);
		res.push_back(z);
		x = y;
	}
	if ((int)res.size() != n) throw;
	return res;
}

void solve2() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			pos[a[j]] = (int)b[a[j]].size();
			used[j] = 0;
		}
		vector<int> res = solve(a[i] + a[n - 1]);
		if (!res.empty()) {
			printf("YES\n");
			printf("%d\n", a[i] + a[n - 1]);
			for (int j = 0; j < n; j += 2)
				printf("%d %d\n", res[j], res[j + 1]);
			return;
		}
	}
	printf("NO\n");
}

void solve() {
	scanf("%d", &n);
	n *= 2;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		b[a[i]].push_back(i);
	solve2();
	for (int i = 0; i < n; i++) {
		pos[a[i]] = 0;
		b[a[i]].clear();
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
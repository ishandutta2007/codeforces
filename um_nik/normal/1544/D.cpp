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

const int N = 200200;
int n;
int a[N];
int b[N];
bool used[N];
vector<int> fr;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		used[i] = 0;
	fr.clear();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		if (used[a[i]]) {
			b[i] = -1;
		} else {
			b[i] = a[i];
			used[a[i]] = 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	int p = 0;
	int q = -1;
	for (int i = 0; i < n; i++) {
		if (b[i] != -1) continue;
		if (!fr.empty()) {
			b[i] = fr.back();
			used[b[i]] = 1;
			fr.pop_back();
			ans++;
			continue;
		}
		while(p < n && used[p]) p++;
		if (p == i) {
			fr.push_back(i);
			p++;
		}
		while(p < n && used[p]) p++;
		if (p < n) {
			b[i] = p;
			used[p] = 1;
			ans++;
			continue;
		}
		assert(q == -1);
		q = i;
	}
	if (q != -1) {
		b[q] = a[q];
		for (int i = 0; i < n; i++) {
			if (i == q) continue;
			if (b[i] == a[q]) {
				b[i] = q;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", b[i] + 1);
	printf("\n");
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
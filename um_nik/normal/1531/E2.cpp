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

const int N = 100100;
const int L = (int)1e7 + 3;
char s[L];
int m;
int ans[N];
int ansSz;
int q[N][4];
int k;

int solve(int n, int &cur) {
	if (n == 1) return -1;
	int l = n / 2;
	int r = n - l;
	int L = solve(l, cur);
	int R = solve(r, cur);
	int v = k++;
	q[v][2] = L;
	q[v][3] = R;
	q[v][0] = cur;
	int c0 = 0, c1 = 0;
	while(c0 < l && c1 < r) {
		if (cur == m) return v;
		if (s[cur] == '0')
			c0++;
		else
			c1++;
		cur++;
	}
	q[v][1] = cur;
	return v;
}

void restoreAns(int v, int n, vector<int> vals) {
	assert(n == (int)vals.size());
	if (v == -1) {
		assert(n == 1);
		ans[ansSz++] = vals[0];
		return;
	}
	int l = n / 2;
	int r = n - l;
	vector<int> L, R;
	int c0 = 0, c1 = 0;
	int pos = 0;
	for (int i = q[v][0]; i < q[v][1]; i++) {
		assert(c0 < l);
		assert(c1 < r);
		if (s[i] == '0') {
			c0++;
			L.push_back(vals[pos++]);
		} else {
			c1++;
			R.push_back(vals[pos++]);
		}
	}
	assert(c0 == l || c1 == r);
	while(c0 < l) {
		c0++;
		L.push_back(vals[pos++]);
	}
	while(c1 < r) {
		c1++;
		R.push_back(vals[pos++]);
	}
	restoreAns(q[v][2], l, L);
	restoreAns(q[v][3], r, R);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	m = strlen(s);
	int l = 1;
	int r = N - 77;
	while(r - l > 1) {
		int x = (l + r) / 2;
		int w = 0;
		k = 0;
		solve(x, w);
		if (w < m)
			l = x;
		else
			r = x;
	}
//	printf("n = %d\n", r);
//	return 0;
	int w = 0;
	vector<int> val(r);
	for (int i = 0; i < r; i++)
		val[i] = i + 1;
	k = 0;
	restoreAns(solve(r, w), r, val);
	assert(ansSz == r);
	printf("%d\n", r);
	for (int i = 0; i < r; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
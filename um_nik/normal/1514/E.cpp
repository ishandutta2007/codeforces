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

int Q1, Q2;
bool query1(int v, int u) {
	assert(Q1 > 0);
	Q1--;
	printf("1 %d %d\n", v, u);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	assert(x != -1);
	return x;
}
bool query2(int v, vector<int> S) {
	if (S.empty()) return false;
	if ((int)S.size() == 1 && Q1 > 0) {
		return query1(v, S[0]);
	}
	assert(Q2 > 0);
	Q2--;
	printf("2 %d %d", v, (int)S.size());
	for (int x : S)
		printf(" %d", x);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	assert(x != -1);
	return x;
}

const int N = 103;
int n;
int ord[N];
int ord2[N];
char ans[N][N];

bool querySeg(int v, int l, int r) {
	vector<int> S;
	for (int i = l; i < r; i++)
		S.push_back(ord[i]);
	return query2(v, S);
}

void solve() {
	scanf("%d", &n);
	Q1 = 9 * n;
	Q2 = 2 * n;
	for (int i = 0; i < n; i++)
		ord[i] = i;
	for (int len = 1; len < n; len <<= 1) {
		for (int st = 0; st < n; st += (len << 1)) {
			if (st + len >= n) {
				for (int i = st; i < n; i++)
					ord2[i] = ord[i];
				continue;
			}
			int mid = st + len;
			int fin = min(st + 2 * len, n);
			int pos = st;
			int p = st, q = mid;
			while(p < mid && q < fin) {
				if (query1(ord[p], ord[q])) {
					ord2[pos++] = ord[p++];
				} else {
					ord2[pos++] = ord[q++];
				}
			}
			while(p < mid) ord2[pos++] = ord[p++];
			while(q < fin) ord2[pos++] = ord[q++];
			assert(pos == fin);
		}
		for (int i = 0; i < n; i++)
			ord[i] = ord2[i];
	}
	assert(Q1 >= n);
	vector<pii> segms;
	int r = n;
	int pos = n;
	for (int i = n - 1; i >= 0; i--) {
		if (i < pos) {
			if (pos < r) {
				segms.push_back(mp(pos, r));
			}
			r = pos;
			pos--;
		}
		while(true) {
			if (!querySeg(ord[i], 0, pos)) break;
			int cur = pos;
			while(true) {
				cur--;
				if (querySeg(ord[i], cur, pos)) break;
			}
			pos = cur;
		}
	}
	segms.push_back(mp(0, r));
	for (int i = 0; i < n; i++) {
		ans[i][n] = '\0';
		for (int j = 0; j < n; j++)
			ans[i][j] = '0';
	}
	for (int i = 0; i < (int)segms.size(); i++)
		for (int j = 0; j <= i; j++) {
			for (int x = segms[i].first; x < segms[i].second; x++)
				for (int y = segms[j].first; y < segms[j].second; y++)
					ans[ord[x]][ord[y]] = '1';
		}
	printf("3\n");
	for (int i = 0; i < n; i++)
		printf("%s\n", ans[i]);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	assert(x == 1);
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
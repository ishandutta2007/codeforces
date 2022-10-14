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
 
const int N = 200200;
const int A = 26;
char s[N];
int n;
int cnt[A];
set<int> hv[A][A];
set<int> setik;
pii ans[N];
int ansSz;
int fenv[N];
 
void addFenv(int p, int x) {
	for(; p < N; p |= p + 1)
		fenv[p] += x;
}
int getFenv(int r) {
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}
 
void add(int x, int y) {
	int c1 = (int)(s[x] - 'a');
	int c2 = (int)(s[y] - 'a');
	hv[c1][c2].insert(x);
}
void del(int x, int y) {
	int c1 = (int)(s[x] - 'a');
	int c2 = (int)(s[y] - 'a');
	hv[c1][c2].erase(x);
}
 
void eraseSet(int x) {
	auto it = setik.lower_bound(x);
	if (*it != x) throw;
	int l = 0, r = n;
	if (it != setik.begin()) {
		it--;
		l = *it;
		it++;
	}
	it++;
	if (it != setik.end()) {
		r = *it;
	}
	if (l != 0) {
		del(l, x);
	}
	if (r != n) {
		del(x, r);
	}
	if (l != 0 && r != n) {
		add(l, r);
	}
	setik.erase(x);
}
void myErase(int x) {
	int y = n;
	auto it = setik.upper_bound(x);
	if (it != setik.end()) y = *it;
	int c1 = (int)(s[x] - 'a');
	int c2 = c1;
	if (y != n) c2 = (int)(s[y] - 'a');
	ans[ansSz++] = mp(x, y);
	if (c1 != c2) {
		cnt[c1]--;
		cnt[c2]--;
		eraseSet(x);
		eraseSet(y);
	} else {
		cnt[c1]--;
		eraseSet(x);
	}
}
 
void printAns() {
	printf("%d\n", ansSz);
	for (int i = 0; i <= n; i++)
		fenv[i] = 0;
	for (int i = 0; i < ansSz; i++) {
		int l = ans[i].first, r = ans[i].second;
		l -= getFenv(l - 1);
		r -= getFenv(r - 1);
		printf("%d %d\n", l + 1, r);
		addFenv(ans[i].first, r - l);
	}
}
 
void solve() {
	scanf("%s", s);
	n = strlen(s);
	setik.clear();
	for (int i = 0; i < A; i++)
		cnt[i] = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) continue;
		if (!setik.empty()) {
			int lst = *setik.rbegin();
			add(lst, i);
		}
		int c = (int)(s[i] - 'a');
		cnt[c]++;
		setik.insert(i);
	}
	ansSz = 0;
	while(true) {
		int mc = 0;
		for (int i = 0; i < A; i++)
			if (cnt[i] > cnt[mc])
				mc = i;
		if (cnt[mc] == (int)setik.size()) break;
		bool fnd = false;
		for (int c = 0; c < A; c++) {
			if (c == mc) continue;
			if (!hv[c][mc].empty()) {
				myErase(*hv[c][mc].begin());
				fnd = true;
				break;
			}
			if (!hv[mc][c].empty()) {
				myErase(*hv[mc][c].begin());
				fnd = true;
				break;
			}
		}
		assert(fnd);
	}
	while(!setik.empty()) {
		int p = *setik.begin();
		myErase(p);
	}
	ans[ansSz++] = mp(0, n);
	printAns();
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
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

const int N = 100100;
char s[N];
int n, k;
vector<int> a[2];

void printAns(int x) {
	if (x == 0) {
		printf("tokitsukaze\n");
	} else if (x == 1) {
		printf("quailty\n");
	} else {
		printf("once again\n");
	}
}

pii get(int id, int l, int r) {
	pii res = mp(-1, -1);
	if (a[id].empty()) return res;
	if (l <= a[id][0] && a[id].back() < r) return res;
	if (l <= a[id][0]) {
		int pos = lower_bound(a[id].begin(), a[id].end(), r) - a[id].begin();
		if (pos >= (int)a[id].size()) throw;
		res.first = a[id][pos];
	} else {
		res.first = a[id][0];
	}
	if (a[id].back() < r) {
		int pos = lower_bound(a[id].begin(), a[id].end(), l) - a[id].begin();
		pos--;
		if (pos < 0) throw;
		res.second = a[id][pos];
	} else {
		res.second = a[id].back();
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		a[(int)(s[i] - '0')].push_back(i);
	for (int i = 0; i + k <= n; i++) {
		for (int x = 0; x < 2; x++) {
			pii t = get(x, i, i + k);
			if (t.first == -1) {
				printAns(0);
				return 0;
			}
		}
	}
	for (int i = 0; i + k <= n; i++) {
		for (int x = 0; x < 2; x++) {
			pii t = get(x, i, i + k);
			if (t.first + k <= t.second) {
				printAns(-1);
				return 0;
			}
		}
	}
	printAns(1);

	return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int INF = 1e9 + 19;
const int N = 2e3 + 100;
const int MAXA = 5e3 + 10;
const int ZERO = MAXA * 3 + 100;

int n, a[N];
int cnt[MAXA];
vector< pair<int, int> > v;
long long f[2 * ZERO];

void upd(bool flag) {
	if (flag) {
		for (int i = 0; i < 2 * ZERO; i++) {
			if (f[i] != 0) {
				for (int j = 0; j < (int)v.size(); j++) {
					assert(i - v[j].fr >= 0);
					long long cur = f[i] * v[j].sc;
					f[i - v[j].fr] += cur;
				}
			}
			f[i] = 0;
		}
	} else {
		for (int i = 2 * ZERO - 1; i >= 0; i--) {
			if (f[i] != 0) {
				for (int j = 0; j < (int)v.size(); j++) {
					assert(i + v[j].fr < 2 * ZERO);
					long long cur = f[i] * v[j].sc;
					f[i + v[j].fr] += cur;
				}
			}
			f[i] = 0;
		}
	}
}
 
int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	// n = 2000;
	long long d = n * 1LL * (n - 1) / 2;
	d = d * d * d;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	// for (int i = 0; i < n; i++) a[i] = i + 1;
	sort(a, a + n);
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) ++cnt[a[j] - a[i]];
	for (int i = 1; i < MAXA; i++) {
		if (cnt[i] != 0) v.pb(mp(i, cnt[i]));
	}
	// for (int i = 0; i < (int)v.size(); i++) cerr << v[i].fr << " " << v[i].sc << endl;
	f[ZERO] = 1;
	upd(true); upd(true);
	upd(false);
	long long ans = 0;
	for (int i = ZERO + 1; i < 2 * ZERO; i++) ans += f[i];
	printf("%.20lf\n", ans * 1.0 / d);
}
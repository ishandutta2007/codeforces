#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 2e6 + 100;
const int INF = 1e9 + 19;
const int BASE = 1e9 + 7;

int n, k;
long long l;
int a[N];
pair<int, int> b[N];
int ans;
int csum[N], cnt[N], nom[N];

int add(int x, int y) {
	x += y;
	if (x >= BASE) x -= BASE;
	return x;
}

void go(int k) {
	for (int i = 0; i < n; i++) {
		long long len;
		if (i < l % n) {
			len = l / n + 1;
		} else {
			len = l / n;
		}
		len = len - k + 1;
		if (len < 0) len = 0;
		int cur = ((len % BASE) * 1LL * cnt[i]) % BASE;
		ans = add(ans, cur);
	}	
}

int main() {
	// freopen("input.txt", "r", stdin);
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) b[i] = mp(a[i], i);
	sort(b, b + n);
	for (int i = 0; i < n; i++) nom[i] = upper_bound(b, b + n, mp(a[i], n)) - b;
	for (int i = 0; i < n; i++) cnt[i] = 1;
	ans = 0;
	for (int j = 1; j <= k; j++) {
		go(j);
		// cerr << j << " " << ans << endl;
		if (j == k) break;
		csum[0] = 0;
		for (int i = 0; i < n; i++) {
			csum[i + 1] = add(csum[i], cnt[b[i].sc]);
		}
		for (int i = 0; i < n; i++) {
			cnt[i] = csum[nom[i]];
		}
	}

	cout << ans << endl;
}
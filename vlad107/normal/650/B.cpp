#include <iostream>
#include <sstream>
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

const int N = 1e6;
const int C = -1;

int n, a, b, t, cnt[N];
string orient;

bool ok(int len) {
	if (len == n) {
		long long score = (n - 1) * 1LL * a + n + cnt[n] * 1LL * b;
		return score <= t;
	} else {
		for (int i = 1; i <= len; i++) {
			int k1 = i - 1;
			int k2 = len - i;
			if (k1 > k2) swap(k1, k2);
			long long score = (2 * k1 + k2) * 1LL * a + len;
			int cc = cnt[i] + cnt[n] - cnt[n - (len - i)];
			score += cc * 1LL * b;
			if (score <= t) return true;
		}
		return false;
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d%d%d\n", &n, &a, &b, &t);
	getline(cin, orient);
	cnt[0] = 0;
	for (int i = 0; i < n; i++) {
		cnt[i + 1] = cnt[i] + (orient[i] == 'w');
	}
	int ll = 0, rr = n + 1;
	while (ll < rr - 1) {
		int mid = (ll + rr) / 2;
		if (ok(mid)) {
			ll = mid;
		} else {
			rr = mid;
		}
	}
	cout << ll << endl;
	return 0;
}
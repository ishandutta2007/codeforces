#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
int x[3000000], q[3000000], c[3000000];

int main() {
	int n, m = 0;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		if (x[i] > x[m]) m = i;
		x[n + i] = x[i];
	}
	int r = 1;
	q[0] = x[m];
	c[0] = 1;
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int y = x[i + m];
		while (q[r - 1] < y) {
			r--;
			ans += c[r];
		}
		if (q[r - 1] > y) {
			ans++;
			q[r] = y;
			c[r] = 1;
			r++;
		} else {
			ans += c[r - 1];
			if (r > 1) ans += 1;
			c[r - 1]++;
		}
//		printf ("%d %I64d\n", y, ans);
	}
	while (r >= 3) { ans += (long long)c[r - 1]; r--; }
	if (r >= 2) ans += int (c[0] > 1) * c[r - 1];
	cout << ans << endl;
	return 0;
}
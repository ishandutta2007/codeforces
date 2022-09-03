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

int main() {
	int n, p1, t1, p2, t2, p3;
	scanf ("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
	int ans = 0, R;
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf ("%d%d", &l, &r);
		if (i > 0) {
			int d = l - R;
			if (d <= t1) ans += d * p1; else
			if (d <= t1 + t2) ans += t1 * p1 + (d - t1) * p2; else
			ans += t1 * p1 + t2 * p2 + (d - t1 - t2) * p3;
		}
		ans += (r - l) * p1;
		R = r;
	}
	printf ("%d\n", ans);
	return 0;
}
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
char w[1001][1001];
int x[1001], y[1001];

int main() {
	scanf ("%d%d", &n, &m);
	gets (w[0]);
	for (int i = 0; i < n; i++) gets (w[i]);
	for (int i = 1; i <= n; i++) x[i] = 0;
	for (int i = 1; i <= m; i++) y[i] = 0;
	int free = 0, fx = 0, fy = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (w[i][j] == 'X') {
				fx++;
				fy++;
				x[i + 1] = j + 1;
				y[j + 1] = i + 1;
			} else free++;
	ll ans = 0;
	int cx = 0, cy = 0;
	for (int i = 1; i < n; i++) {
		cx += int (x[i] > 0);
		ans += (ll)(m * i - cx) * (m * (n - i) - (fx - cx)) * 2;
	}
	for (int i = 1; i < m; i++) {
		cy += int (y[i] > 0);
		ans += (ll)(n * i - cy) * (n * (m - i) - (fy - cy)) * 2;
	}
	ll bad = 0;
	int cl = 0, cr = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || x[i - 1] == 0 || x[i] < x[i - 1]) cl = 0;
		if (i == 1 || x[i - 1] == 0 || x[i] > x[i - 1]) cr = 0;
		if (x[i] > 0) { bad += cl * (m - x[i]) + cr * (x[i] - 1); cl += x[i] - 1; cr += m - x[i]; bad += (x[i] - 1) * (m - x[i]) * 2; }
	}           
	cl = cr = 0;
	for (int i = n; i >= 1; i--) {
		if (i == n || x[i + 1] == 0 || x[i] < x[i + 1]) cl = 0;
		if (i == n || x[i + 1] == 0 || x[i] > x[i + 1]) cr = 0;
		if (x[i] > 0) { bad += cl * (m - x[i]) + cr * (x[i] - 1); cl += x[i] - 1; cr += m - x[i]; }
	}           
	cl = cr = 0;
	for (int i = 1; i <= m; i++) {
		if (i == 1 || y[i - 1] == 0 || y[i] < y[i - 1]) cl = 0;
		if (i == 1 || y[i - 1] == 0 || y[i] > y[i - 1]) cr = 0;
		if (y[i] > 0) { bad += cl * (n - y[i]) + cr * (y[i] - 1); cl += y[i] - 1; cr += n - y[i]; bad += (y[i] - 1) * (n - y[i]) * 2;}
	}           
	cl = cr = 0;
	for (int i = m; i >= 1; i--) {
		if (i == m || y[i + 1] == 0 || y[i] < y[i + 1]) cl = 0;
		if (i == m || y[i + 1] == 0 || y[i] > y[i + 1]) cr = 0;
		if (y[i] > 0) { bad += cl * (n - y[i]) + cr * (y[i] - 1); cl += y[i] - 1; cr += n - y[i]; }
	}
	ans += bad * 2;
	printf ("%.10f\n", (ans + 0.0) / ((ll)free * free));
	return 0;
}
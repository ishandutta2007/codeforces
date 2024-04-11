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
	long long a, v, l, d, w;
	cin >> a >> v >> l >> d >> w;
	if (w * w >= 2 * d * a || v <= w) {	
		if (v * v >= l * 2 * a) printf ("%.10f\n", sqrt ((2.0 * l) / a)); else {
			double at = (double)v / a;
			double al = (double)(v * v) / (2 * a);
			printf ("%.10f\n", at + (l - al) / v);
		}
	} else {
		double tt;
		if (2 * v * v - w * w <= 2 * d * a) {
			double al = (2.0 * v * v - w * w) / (2 * a);
			tt = (d - al + 0.0) / v + (2.0 * v - w) / a;
		} else {
			double x = sqrt (d * a + w * w / 2.0);
			tt = (2 * x - w) / a;
		}
		if (v * v - w * w <= (l - d) * 2 * a) {
			double at = (double)(v - w) / a;
			double al = (v * v - w * w + 0.0) / (2 * a);
			tt += at + (l - d - al + 0.0) / v;
		} else tt += (-w + sqrt (w * w + 2 * a * (l - d))) / a;
		printf ("%.10f\n", tt);
	}
	return 0;
}
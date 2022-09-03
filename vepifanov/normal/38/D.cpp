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
int x1[100], y1[100], x2[100], y2[100], x[100], y[100], w[100];

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		if (x1[i] > x2[i]) swap (x1[i], x2[i]);
		if (y1[i] > y2[i]) swap (y1[i], y2[i]);
		w[i] = (x2[i] - x1[i]) * (y2[i] - y1[i]) * (y2[i] - y1[i]);
		x[i] = (x1[i] + x2[i]);
		y[i] = (y1[i] + y2[i]);
		int ok = 1;
		ll sx = 0, sy = 0, sw = 0;
		for (int j = i; j > 0; j--) {
			sx += x[j] * w[j];
			sy += y[j] * w[j];
			sw += w[j];
			if (!(sx >= x1[j - 1] * sw * 2 && sx <= x2[j - 1] * sw * 2 && sy >= y1[j - 1] * sw * 2 && sy <= y2[j - 1] * sw * 2)) ok = 0;
		}
		if (!ok) {
			printf ("%d\n", i);
			re 0;
		}
	}
	printf ("%d\n", n);
	
	return 0;
}
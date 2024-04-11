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
int x[200000];
int a, b, c;

int f1 (int d) {
	int l = 0, r = n;
	while (r - l > 1) {
		int s = ((ll)l + r) / 2;
		if (x[s] - x[0] > 2 * d) r = s; else l = s;
	}
	re l;
}

int f2 (int d) {
	int l = -1, r = n - 1;
	while (r - l > 1) {
		int s = ((ll)l + r) / 2;
		if (x[n - 1] - x[s] > 2 * d) l = s; else r = s;
	}
	re r;
}

int check (int d) {
	int l = f1 (d);
	int r = f2 (d);
	a = ((ll)x[0] + x[l]) / 2;
	c = b = ((ll)x[r] + x[n - 1]) / 2;
	if (l + 1 < r) {
		if (x[r - 1] - x[l + 1] <= 2 * d) {
			c = ((ll)x[l + 1] + x[r - 1]) / 2;
			re 1;
		}
	} else re 1;
	re 0;
}

int main() {
	scanf ("%d", &n);	
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		x[i] *= 2;
	}
	sort (x, x + n);
	int l = -1, r = 1e9;
	while (r - l > 1) {
		int s = ((ll)l + r) / 2;
		if (check (s)) r = s; else l = s;
	}
	printf ("%.6f\n", r / 2.0);
	check (r);
	printf ("%.6f %.6f %.6f\n", a / 2.0, b / 2.0, c / 2.0);
	return 0;
}
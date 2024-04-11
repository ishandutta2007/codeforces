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
	scanf ("%d", &n);
	double l = 1, r = 1e9;
	for (int i = 1; i <= n; i++) {
		double x;
		scanf ("%lf", &x);
		l = max ((x + 0.0) / i, l);
		r = min ((x + 1.0) / i, r);
	}
	int L = int ((n + 1) * l + 0.000001);
	int R = int ((n + 1) * r - 0.000001);
	if (L == R) printf ("unique\n%d\n", L); else printf ("not unique\n");
	return 0;
}
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
int m, k;
int x[500000], v[500000];
double res[500000];

int check (double s) {
	double a = 1e100, b = -1e100;
	for (int i = 0; i < n; i++) {
		if (v[i] > 0)
			b = max (b, x[i] + v[i] * s);
		res[i] = b;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] < 0)
			a = min (a, x[i] + v[i] * s);
		if (a < res[i]) return 1;
	}                                
	return 0;
}

int main() {
	scanf ("%d", &n);	
	for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &v[i]);
	int ok = 0;
	for (int i = 0; i + 1 < n; i++)
		if (v[i] > 0 && v[i + 1] < 0) ok = 1;
	if (!ok) {
		printf ("-1\n");
		return 0;
	}
	double L = 0, R = 1e10;
	for (int it = 0; it < 200; it++) {
		double S = (L + R) / 2;
		if (check (S)) R = S; else L = S;
	}
	printf ("%.15f\n", R);
	return 0;
}
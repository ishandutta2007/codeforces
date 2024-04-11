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
int l[100], r[100];

int main() {
	int n, x;
	scanf ("%d%d", &n, &x);
	int L = -1, R = 1001;
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &l[i], &r[i]);
		if (l[i] > r[i]) swap (l[i], r[i]);
		L = max (L, l[i]);
		R = min (R, r[i]);
	}
	if (L > R) printf ("-1\n"); else
	if (x >= L && x <= R) printf ("0\n"); else
	if (x < L) printf ("%d\n", L - x); else printf ("%d\n", x - R);
	return 0;
}
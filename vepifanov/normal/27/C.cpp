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
int x[100000], a[100000], b[100000], c[100000], d[100000];

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	a[0] = b[0] = 0;
	for (int i = 1; i < n; i++) {
		a[i] = a[i - 1];
		b[i] = b[i - 1];
		if (x[i] < x[a[i]]) a[i] = i;
		if (x[i] > x[b[i]]) b[i] = i;
	}	
	c[n - 1] = d[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		c[i] = c[i + 1];
		d[i] = d[i + 1];
		if (x[i] < x[c[i]]) c[i] = i;
		if (x[i] > x[d[i]]) d[i] = i;
	}	
	for (int i = 1; i + 1 < n; i++)
		if (x[a[i - 1]] < x[i] && x[c[i + 1]] < x[i]) {
			printf ("3\n%d %d %d\n", a[i - 1] + 1, i + 1, c[i + 1] + 1);
			re 0;
		} else
		if (x[b[i - 1]] > x[i] && x[d[i + 1]] > x[i]) {
			printf ("3\n%d %d %d\n", b[i - 1] + 1, i + 1, d[i + 1] + 1);
			re 0;
		}
	printf ("0\n");
	return 0;
}
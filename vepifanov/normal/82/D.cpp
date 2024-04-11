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
int x[1000];
int was[1001][1001];
int res[1001][1001];

int go (int i, int j) {	
	int a = j, b = i, c = i + 1;
	if (i == j) {
		b++;
		c++;
	}
	if (a >= n) re 0; else
	if (b >= n) re x[a]; else
	if (c >= n) re max (x[a], x[b]); else
	if (was[i][j]) re res[i][j];
	was[i][j] = 1;
	int cur = 2e9;
	cur = min (cur, max (x[a], x[b]) + go (c, c));
	cur = min (cur, max (x[a], x[c]) + go (c + 1, b));
	cur = min (cur, max (x[b], x[c]) + go (c + 1, a));
	re res[i][j] = cur;
}

int out (int i, int j) {	
	int a = j, b = i, c = i + 1;
	if (i == j) {
		b++;
		c++;
	}
	if (a >= n) re 0;
	if (b >= n) { printf ("%d\n", a + 1); re 0; }
	if (c >= n) { printf ("%d %d\n", a + 1, b + 1); re 0; }
	int cur = res[i][j];
	if (cur == max (x[a], x[b]) + go (c, c)) { printf ("%d %d\n", a + 1, b + 1); out (c, c); re 0; }
	if (cur == max (x[a], x[c]) + go (c + 1, b)) { printf ("%d %d\n", a + 1, c + 1); out (c + 1, b); re 0; }
	if (cur == max (x[b], x[c]) + go (c + 1, a)) { printf ("%d %d\n", b + 1, c + 1); out (c + 1, a); re 0; }
	re 0;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	memset (was, 0, sizeof (was));
	printf ("%d\n", go (0, 0));
	out (0, 0);
	return 0;
}
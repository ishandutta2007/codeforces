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

int n, t;
int m;
int was[21][11][11][4][4];
long long res[21][11][11][4][4];

long long go (int i, int t1, int t2, int a, int b) {
	if (t1 < 0 || t2 < 0) return 0;
	if (i == n) return int (t1 == 0 && t2 == 0);
	if (i > 1 && was[i][t1][t2][a][b]) return res[i][t1][t2][a][b];
	long long cur = 0;
	for (int c = 0; c < 4; c++)
		if (c != b)
			cur += go (i + 1, t1 - int (i > 1 && a > b && c > b), t2 - int (i > 1 && a < b && c < b), b, c);
	if (i > 1) {
		was[i][t1][t2][a][b] = 1;
		res[i][t1][t2][a][b] = cur;
	}
	return cur;
}

int main() {
	scanf ("%d%d", &n, &t);
	printf ("%I64d\n", go (0, t, t - 1, -1, -1));
	return 0;
}
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

int n, a, b;
int m;
int was[10][17][17], res[10][17][17], prev[10][17][17], x[10];

int go (int i, int l, int ll) {
	if (i + 1 == n) {
		if (x[i] - l * b < 0) return 0;
		return 1e9;
	}
	if (was[i][l][ll]) return res[i][l][ll];
	int ans = 1e9, s = 0;
	for (int k = 0; k <= 16; k++) {
		int tmp = 1e9;
		if (x[i - 1] - l * a - k * b - ll * b < 0 && (i + 2 < n || x[i] - l * b - k * a < 0)) tmp = go (i + 1, k, l) + k;
		if (tmp < ans) {
			ans = tmp;
			s = k;
		}
	}
	was[i][l][ll] = 1;
	res[i][l][ll] = ans;
	prev[i][l][ll] = s;
	return ans;
}

int out (int i, int l, int ll) {
	if (i + 1 == n) return 0;
	for (int j = 0; j < prev[i][l][ll]; j++) printf ("%d ", i + 1);
	out (i + 1, prev[i][l][ll], l);
	return 0;
}

int main() {
	scanf ("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++)
		scanf ("%d", &x[i]);
	printf ("%d\n", go (1, 0, 0));
	out (1, 0, 0);
	printf ("\n");
	return 0;
}
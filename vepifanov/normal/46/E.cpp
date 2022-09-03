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
int was[1501][1501];
ll res[1501][1501];
int s[1501][1501], g[1501][1501];

ll go (int i, int j) {
	if (i == n) re 0;
	if (j == -1 || j == m) re -1e15;
	if (was[i][j]) re res[i][j];
	was[i][j] = 1;
	res[i][j] = -1e15;
	if (i & 1) {
		res[i][j] = max (go (i, j - 1), go (i + 1, j + 1) + s[i][j]);
	} else {
		res[i][j] = max (go (i, j + 1), go (i + 1, j - 1) + s[i][j]);
	}
	re res[i][j];
}

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			scanf ("%d", &g[i][j]);
	for (int i = 0; i < n; i++) {
		s[i][0] = g[i][0];
		for (int j = 0; j + 1 < m; j++) s[i][j + 1] = s[i][j] + g[i][j + 1];
	}
	cout << go (0, 1) << endl;
	return 0;
}
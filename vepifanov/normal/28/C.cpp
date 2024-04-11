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
ld res[100][100][100], pw[100][100];
int a[100];

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf ("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		pw[i][0] = 1;
		for (int j = 1; j <= n; j++)
			pw[i][j] = pw[i][j - 1] * i;
	}
	res[m][n][0] = 1;
	for (int i = m; i > 0; i--)
		for (int j = n; j >= 0; j--) 
			for (int t = 0; t <= n; t++) {
				if (i == 1) res[0][0][max (t, (j + a[i] - 1) / a[i])] += res[i][j][t]; else {
					ld cur = 1 / pw[i][j];
					for (int k = 0; k <= j; k++) {
						res[i - 1][j - k][max (t, (k + a[i] - 1) / a[i])] += res[i][j][t] * cur * pw[i - 1][j - k];
						if (k < j) cur = (cur * (j - k)) / (k + 1);
					}
	                	}
			}
	ld ans = 0;
	for (int t = 1; t <= n; t++)
		ans += t * res[0][0][t];
	printf ("%.10f\n", (double)ans);
	return 0;
}
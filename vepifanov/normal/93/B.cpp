#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int w;
double x[50], y[50];
double h;
int cnt[50];
vector<pair<int, double> > res[50];

int main () {
	scanf ("%d%d%d", &n, &w, &m);	
	h = (n * w * 1.0) / m;
	int i = 0, j = 0;
	while (i < n) {
		double tmp = min (w - x[i], h - y[j]);
		if (tmp > 1e-8) {
//			printf ("%d %d %.10f\n", i, j, tmp);
			x[i] += tmp;
			cnt[i]++;
			if (cnt[i] > 2) {
				printf ("NO\n");
				re 0;
			}
			y[j] += tmp;
			res[j].pb (mp (i, tmp));
		}
		if (x[i] + 1e-7 > w) i++;
		if (y[j] + 1e-7 > h) j++;
	}
	printf ("YES\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < sz (res[i]); j++)
			printf ("%d %.10f ", res[i][j].fi + 1, res[i][j].se);
		printf ("\n");
	}
	return 0;
}
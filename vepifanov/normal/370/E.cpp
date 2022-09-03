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

#define filename ""

int n;
int m;
int x[200001];
int l[200001];
int r[200001];

int out (int i, int j) {
	set<int> u;
	for (int k = 1; k <= 5; k++) {
		if (x[i - k] != 0) u.insert (x[i - k]);
		if (k >= 2 && l[i - k] <= j - 1 && r[i - k] >= j - 1)
			if (u.empty () || (sz (u) == 1 && *u.begin () == j)) {
				out (i - k, j - 1);
				for (int t = 0; t < k; t++) printf ("%d ", j);
				break;
			}
	}
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	for (int i = 0; i < n; i++)	l[i + 1] = 1e9, r[i + 1] = -1e9;
	l[0] = r[0] = 0;
	for (int i = 0; i < n; i++)
		if (l[i] <= r[i]) {
			set<int> u;
			for (int j = 0; j < 5 && i + j < n; j++) {
				if (x[i + j] != 0) u.insert (x[i + j]);
				if (j >= 1) {
					if (u.empty ()) {
						l[i + j + 1] = min (l[i + j + 1], l[i] + 1);
						r[i + j + 1] = max (r[i + j + 1], r[i] + 1);
					} else
					if (sz (u) == 1) {
						int tmp = *u.begin ();
						if (tmp - 1 >= l[i] && tmp - 1 <= r[i]) {
							l[i + j + 1] = min (l[i + j + 1], tmp);
							r[i + j + 1] = max (r[i + j + 1], tmp);
						}
					}
				}
			}
		}
	if (l[n] > r[n]) printf ("-1\n"); else {
		printf ("%d\n", r[n]);
		out (n, r[n]);
	}
	return 0;
}
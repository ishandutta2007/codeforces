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
int x[1000], y[1000], res[1000], l[1000], use[1000];

int scal (int x1, int y1, int x2, int y2) {
	re x1 * x2 + y1 * y2;
}

int dist (int x, int y) {
	re x * x + y * y;
}
	
int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf ("%d%d", &x[i], &y[i]);
	x[n + 1] = x[1];
	y[n + 1] = y[1];
	x[0] = x[n];
	y[0] = y[n];
	for (int i = 0; i < m; i++) scanf ("%d", &l[i]);
	for (int t = 1; t <= 2; t++) {
		int ok = 1;
		memset (use, 0, sizeof (use));
		for (int i = 1; i <= n; i++) res[i] = -1;
		for (int i = t; i <= n; i += 2) 
			if (scal (x[i - 1] - x[i], y[i - 1] - y[i], x[i + 1] - x[i], y[i + 1] - y[i]) == 0) {
				ll a = dist (x[i - 1] - x[i], y[i - 1] - y[i]);
				ll b = dist (x[i + 1] - x[i], y[i + 1] - y[i]);
				int ok2 = 0;
				for (int j = 0; j < m; j++)
					if (!use[j]) {
						ll c = l[j];
						c = c * c - a - b;
						if (c % 2 == 0) {
							c /= 2;
							if (a * b / c == c) {
								if (c * c == a * b) {
									ok2 = 1;
									res[i] = j + 1;
									use[j] = 1;
									break;
								}
							}
						}
					}
				if (!ok2) {
					ok = 0;
					break;
				}
	        	} else {
	        		ok = 0;
	        		break;
	        	}	

		if (ok) {
			printf ("YES\n");
			for (int i = 1; i <= n; i++)
				printf ("%d ", res[i]);
			printf ("\n");
			re 0;
		}
	}
	printf ("NO\n");
	return 0;
}
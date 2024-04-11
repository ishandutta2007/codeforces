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
int ax[4], ay[4], bx[4], by[4];

int go (int x1, int y1, int x2, int y2) {
	for (int i = 0; i < 4; i++)
		if (ax[i] == x1 && ay[i] == y1 && bx[i] == x2 & by[i] == y2)
			return 1;
	return 0;
}

int main() {
	int x1, y1, x2, y2;
	x1 = y1 = 2e9;
	x2 = y2 = -2e9;
	for (int i = 0; i < 4; i++) {
	        scanf ("%d%d%d%d", &ax[i], &ay[i], &bx[i], &by[i]);
	        if (ax[i] > bx[i] || ax[i] == bx[i] && ay[i] > by[i]) {
	        	swap (ax[i], bx[i]);
	        	swap (ay[i], by[i]);
	        }
	        x1 = min (x1, min (ax[i], bx[i]));
	        y1 = min (y1, min (ay[i], by[i]));
	        x2 = max (x2, max (ax[i], bx[i]));
	        y2 = max (y2, max (ay[i], by[i]));
	}
	if (x2 > x1 && y2 > y1 && go (x1, y1, x2, y1) && go (x1, y1, x1, y2) && go (x1, y2, x2, y2) && go (x2, y1, x2, y2)) printf ("YES\n"); else printf ("NO\n");
	return 0;
}
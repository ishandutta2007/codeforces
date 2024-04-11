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

int main() {
	scanf ("%d", &n);
	int x1 = 1e9, y1 = 1e9, x2 = -1e9, y2 = -1e9, s1 = 1e9, s2 = -1e9, r1 = 1e9, r2 = -1e9;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d%d", &x, &y);
		x1 = min (x1, x - 1);
		y1 = min (y1, y - 1);
		x2 = max (x2, x + 1);
		y2 = max (y2, y + 1);
		s1 = min (s1, x + y - 1);
		r1 = min (r1, x - y - 1);
		s2 = max (s2, x + y + 1);
		r2 = max (r2, x - y + 1);
	}	
	int ans = 2 * (x2 - x1) + 2 * (y2 - y1) - abs (s1 - (x1 + y1)) - abs (s2 - (x2 + y2)) - abs (r1 - (x1 - y2)) - abs (r2 - (x2 - y1));
	printf ("%d\n", ans);
	return 0;
}
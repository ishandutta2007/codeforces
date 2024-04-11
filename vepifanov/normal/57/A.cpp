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
int x1, y1, x2, y2;

int dist (int x1, int y1, int x2, int y2) {
	int ans = 1e6;
	if (x1 == 0 && x2 == 0 || x1 == n && x2 == n) ans = min (ans, abs (y1 - y2));
	if (y1 == 0 && y2 == 0 || y1 == n && y2 == n) ans = min (ans, abs (x1 - x2));
	re ans;
}

int main() {
	scanf ("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
	int ans = dist (x1, y1, x2, y2);
	for (int p1 = 0; p1 <= n; p1 += n)
		for (int q1 = 0; q1 <= n; q1 += n)
			for (int p2 = 0; p2 <= n; p2 += n)
				for (int q2 = 0; q2 <= n; q2 += n)
					ans = min (ans, dist (x1, y1, p1, q1) + dist (p1, q1, p2, q2) + dist (p2, q2, x2, y2));
	printf ("%d\n", ans);
	return 0;
}
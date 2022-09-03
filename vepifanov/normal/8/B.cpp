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

int w[300][300], qx[200], qy[200], d[300][300];
char s[200];

int main() {
	gets (s);
	int x = 150, y = 150;
	for (int i = 0; i < strlen (s); i++) {
		if (s[i] == 'U') y++;
		if (s[i] == 'D') y--;
		if (s[i] == 'R') x++;
		if (s[i] == 'L') x--;
		w[x][y] = 1;
	}
	int l = 0, r = 1;
	qx[0] = qy[0] = 150;
	while (l < r) {
		int xx = qx[l];
		int yy = qy[l];
		l++;
		int dx = 1, dy = 0;
		for (int k = 0; k < 4; k++) {
			int nx = xx + dx;
			int ny = yy + dy;
			if (w[nx][ny]) {
				w[nx][ny] = 0;
				d[nx][ny] = d[xx][yy] + 1;
				qx[r] = nx;
				qy[r++] = ny;
			}
			swap (dx, dy); dx = -dx;
		}
	}
	if (d[x][y] != strlen (s)) printf ("BUG\n"); else printf ("OK\n");
	return 0;
}
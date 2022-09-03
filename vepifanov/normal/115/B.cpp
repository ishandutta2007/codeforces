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

char g[152][152];

int main () {
	scanf ("%d%d", &n, &m);
	gets (g[0]);
	for (int i = 0; i < n; i++) gets (g[i]);
	for (int i = 0; i < m; i++) g[n][i] = 'G';
	int rem = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rem += int (g[i][j] == 'W');
	int ans = 0, x = 0;
	for (int i = 0; i < n && rem; i++)
		if (i & 1) {
			int y = x;
			for (int j = x; j >= 0; j--)
				if (g[i][j] == 'W' || g[i + 1][j] == 'W') 
					y = j;
			ans += x - y;
			for (int j = y; j <= x; j++)
				if (g[i][j] == 'W') {
					g[i][j] = 'G';
					rem--;
				}
			if (!rem) break;
			ans++;
			x = y;
			if (g[i + 1][x] == 'W') { rem--; g[i + 1][x] = 'G'; }
		} else {
			int y = x;
			for (int j = x; j < m; j++)
				if (g[i][j] == 'W' || g[i + 1][j] == 'W') 
					y = j;
			ans += y - x;
			for (int j = x; j <= y; j++)
				if (g[i][j] == 'W') {
					g[i][j] = 'G';
					rem--;
				}
			if (!rem) break;
			ans++;
			x = y;
			if (g[i + 1][x] == 'W') { rem--; g[i + 1][x] = 'G'; }
		}
	printf ("%d\n", ans);
	return 0;
}
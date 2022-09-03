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
char w[11][11];

int main () {
	scanf ("%d%d", &n, &m);	
	gets (w[0]);
	for (int i = 0; i < n; i++) gets (w[i]);
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (w[i][j] == 'P') {
				for (int t = 0; t < 4; t++) {
					int ni = i + int (t == 0) - int (t == 1);
					int nj = j + int (t == 2) - int (t == 3);
					if (ni >= 0 && nj >= 0 && ni < n && nj < m && w[ni][nj] == 'W') {
						w[ni][nj] = '.';
						res++;
					}
				}
			}
	printf ("%d\n", res);
	return 0;
}
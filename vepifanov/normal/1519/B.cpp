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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 100;
const int M = N * N * 2 + 1;

int n;
int m;
int k;
bitset<M> can[N][N];

int main () {
	can[0][0][0] = 1;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++) {
			if (i + 1 < 100)
				can[i + 1][j] |= can[i][j] << (j + 1);
			if (j + 1 < 100)
				can[i][j + 1] |= can[i][j] << (i + 1);
		}
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d%d", &n, &m, &k);
		printf ("%s\n", can[n - 1][m - 1][k] ? "YES" : "NO");
	}
    return 0;
}
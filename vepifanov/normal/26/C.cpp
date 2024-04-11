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

char g[301][301];

int main() {
	int n, m, a, b, c;
	scanf ("%d%d%d%d%d", &n, &m, &b, &a, &c);
	int N = n, M = m;
	if ((n & 1) && (m & 1)) printf ("IMPOSSIBLE\n"); else {
		if (n & 1) {
			b -= m / 2;
			N--;
			for (int i = 0; i < m; i++) g[N][i] = (i & 2) + 6;
		}
		if (m & 1) {
			a -= n / 2;
			M--;	
			for (int i = 0; i < n; i++) g[i][M] = (i & 2) + 6;
		}
		if (a < 0 || b < 0 || (a / 2 + b / 2 + c) * 4 < N * M) printf ("IMPOSSIBLE\n"); else {
			for (int i = 0; i < N; i += 2)
				for (int j = 0; j < M; j += 2) {
					int q = (i + j) & 2;
					if (a >= 2) {
						a -= 2;
						g[i][j] = g[i + 1][j] = q;
						g[i][j + 1] = g[i + 1][j + 1] = q + 1;
					} else
					if (b >= 2) {
						b -= 2;
						g[i][j] = g[i][j + 1] = q;
						g[i + 1][j] = g[i + 1][j + 1] = q + 1;
					} else g[i][j] = g[i][j + 1] = g[i + 1][j] = g[i + 1][j + 1] = q;
				}
					
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					printf ("%c", g[i][j] + 'a');
				printf ("\n");
			}
		}
	}
	return 0;
}
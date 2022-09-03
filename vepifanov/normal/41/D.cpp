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
int m, k;
char g[101][101];
int res[101][101][11], prev[101][101][11], pk[101][101][11];

int out (int i, int j, int k) {
	if (i == 0) printf ("%d\n", j + 1); else {
		if (prev[i][j][k]) { out (i - 1, j - 1, pk[i][j][k]); printf ("R"); } else { out (i - 1, j + 1, pk[i][j][k]); printf ("L"); }
	}
	re 0;
}
           
int main() {
	scanf ("%d%d%d", &n, &m, &k); k++;
	gets (g[0]);
	for (int i = 0; i < n; i++) gets (g[n - i - 1]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int l = 0; l < k; l++)
				res[i][j][l] = -1;
	for (int i = 0; i < m; i++)
		res[0][i][(g[0][i] - '0') % k] = g[0][i] - '0';
	for (int i = 0; i + 1 < n; i++)
		for (int j = 0; j < m; j++) 
			for (int l = 0; l < k; l++) {
				if (res[i][j][l] == -1) continue;
				if (j > 0 && res[i + 1][j - 1][(l + g[i + 1][j - 1] - '0') % k] < res[i][j][l] + g[i + 1][j - 1] - '0') {
					res[i + 1][j - 1][(l + g[i + 1][j - 1] - '0') % k] = res[i][j][l] + g[i + 1][j - 1] - '0';
					prev[i + 1][j - 1][(l + g[i + 1][j - 1] - '0') % k] = 0;
					pk[i + 1][j - 1][(l + g[i + 1][j - 1] - '0') % k] = l;
				}
				if (j + 1 < m && res[i + 1][j + 1][(l + g[i + 1][j + 1] - '0') % k] < res[i][j][l] + g[i + 1][j + 1] - '0') {
					res[i + 1][j + 1][(l + g[i + 1][j + 1] - '0') % k] = res[i][j][l] + g[i + 1][j + 1] - '0';
					prev[i + 1][j + 1][(l + g[i + 1][j + 1] - '0') % k] = 1;
					pk[i + 1][j + 1][(l + g[i + 1][j + 1] - '0') % k] = l;
				}
			}
	int ans = -1, ai = -1;
	for (int i = 0; i < m; i++)
		if (res[n - 1][i][0] > ans) {
			ans = res[n - 1][i][0];
			ai = i;
		}
	printf ("%d\n", ans);
	if (ans != -1) {
		out (n - 1, ai, 0);
		printf ("\n");
	}
	return 0;     
}
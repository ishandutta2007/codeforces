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
int g[50][50], w[50][50];

int main() {
	scanf ("%d", &n);
	m = n * (n - 1) / 2;
	for (int i = 0; i + 1 < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		g[a][b] = 1;
		w[a][b] = w[b][a] = 1;
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] |= g[i][k] & g[k][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && !w[i][j] && g[i][j]) {
				printf ("%d %d\n", i + 1, j + 1);
				re 0;
			}	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && !w[i][j])	{
				printf ("%d %d\n", i + 1, j + 1);
				re 0;
			}
	return 0;
}
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
char g[301][301];

int main() {
        scanf ("%d%d%d", &n, &m, &k);
        gets (g[0]);
        for (int i = 0; i < n; i++) gets (g[i]);
	for (int l = 1; l < n; l++)
		for (int i = l; i + l < n; i++)
			for (int j = l; j + l < m; j++)
				if (g[i][j] == '*' && g[i - l][j] == '*' && g[i][j - l] == '*' && g[i + l][j] == '*' && g[i][j + l] == '*') {
					k--;
					if (k == 0) {
						i++; j++;
						printf ("%d %d\n", i, j);
						printf ("%d %d\n", i - l, j);
						printf ("%d %d\n", i + l, j);
						printf ("%d %d\n", i, j - l);
						printf ("%d %d\n", i, j + l);
						re 0;
					}
				}
	printf ("-1\n");
	return 0;
}
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
string a, b, w[50];
vi ca[26][51], cb[26][51];
int fa[26][51][51], fb[26][51][51];
int res[51][51];
int p;

int main() {
	cin >> a >> b;
	cin >> p;
	for (int i = 0; i < p; i++) cin >> w[i];
	int n = a.size ();
	int m = b.size ();
	for (int l = 1; l <= n; l++)
		for (int i = 0; i + l <= n; i++)
			if (l == 1) {
				ca[a[i] - 'a'][i].pb (l); 
				fa[a[i] - 'a'][i][l] = 1;
			} else {
				for (int j = 0; j < p; j++) {
					char x = w[j][0], y = w[j][3], z = w[j][4];
					for (int k = 0; k < sz (ca[y - 'a'][i]); k++) 
						if (ca[y - 'a'][i][k] < l && fa[z - 'a'][i + ca[y - 'a'][i][k]][l - ca[y - 'a'][i][k]]) {
							if (!fa[x - 'a'][i][l]) ca[x - 'a'][i].pb (l);
							fa[x - 'a'][i][l] = 1;
						}
				}
			}
	for (int l = 1; l <= m; l++)
		for (int i = 0; i + l <= m; i++)
			if (l == 1) {
				cb[b[i] - 'a'][i].pb (l); 
				fb[b[i] - 'a'][i][l] = 1;
			} else
				for (int j = 0; j < p; j++) {
					char x = w[j][0], y = w[j][3], z = w[j][4];
					for (int k = 0; k < sz (cb[y - 'a'][i]); k++) 
						if (cb[y - 'a'][i][k] < l && fb[z - 'a'][i + cb[y - 'a'][i][k]][l - cb[y - 'a'][i][k]]) {
							if (!fb[x - 'a'][i][l]) cb[x - 'a'][i].pb (l);
							fb[x - 'a'][i][l] = 1;
						}
				}
	memset (res, -1, sizeof (res));
	res[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (res[i][j] != -1)
			for (int c = 0; c < 26; c++)
				for (int x = 0; x < sz (ca[c][i]); x++)
					for (int y = 0; y < sz (cb[c][j]); y++) {
						int ni = i + ca[c][i][x];
						int nj = j + cb[c][j][y];
						if (res[ni][nj] == -1 || res[ni][nj] > res[i][j] + 1) res[ni][nj] = res[i][j] + 1;
					}
	printf ("%d\n", res[n][m]);
	return 0;
}
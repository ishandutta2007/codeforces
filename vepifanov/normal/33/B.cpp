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
int k;
int g[26][26];
string a, b;

int main() {
	cin >> a >> b;
	n = a.size ();
	m = b.size ();
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			g[i][j] = 10000000 * int (i != j);
	cin >> k;
	for (int i = 0; i < k; i++) {
		string X, Y;
		int c;
		cin >> X >> Y >> c;
		g[X[0] - 'a'][Y[0] - 'a'] = min (g[X[0] - 'a'][Y[0] - 'a'], c);
	}
	for (int k = 0; k < 26; k++)
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
	if (n != m) cout << -1 << endl; else {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cur = 10000000;
			int rc = 0;
			for (int j = 0; j < 26; j++)
				if (g[a[i] - 'a'][j] + g[b[i] - 'a'][j] < cur) {
					cur = g[a[i] - 'a'][j] + g[b[i] - 'a'][j];
					rc = j;
				}
			if (cur == 10000000) {
				cout << -1 << endl;
				re 0;
			}
			a[i] = 'a' + rc;
			ans += cur;
		}
		cout << ans << endl << a << endl;
	}
	return 0;
}
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
vi v[200];
string wrd[200000];
map<string, int> num;
int was[200], q[200], p[200000];

int get (string s) {
	if (num.count (s)) re num[s];
	num[s] = m;
	wrd[m] = s;
	m++;
	re m - 1;
}

int go (int x) {
	if (x == -1) re 1;
	if (was[x]) re 0;
	was[x] = 1;
	for (int i = 0; i < sz (v[x]); i++)
		if (go (p[v[x][i]])) {
			q[x] = v[x][i];
			p[v[x][i]] = x;
			re 1;
		}
	re 0;
}

int calc (int i, int j, string s, string w) {
	if (j == sz (s)) {
		if (w != "") v[i].pb (get (w));
		re 0;
	}	
	calc (i, j + 1, s, w);
	if (sz (w) < 4) calc (i, j + 1, s, w + s[j]);
	re 0;
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		calc (i, 0, s, "");
	}
	for (int i = 0; i < m; i++) p[i] = -1;
	for (int i = 0; i < n; i++) {
		memset (was, 0, sizeof (was));
		if (!go (i)) {
			printf ("-1\n");
			re 0;
		}
	}
	for (int i = 0; i < n; i++) cout << wrd[q[i]] << endl;
	return 0;
}
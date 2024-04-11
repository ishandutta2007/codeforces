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
typedef unsigned long long ll;
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
string s;
int was[20][20];
ll res[20][20];
ll p[20];

ll go (int i, int j) {
	if (i + j == 2 * n) re 0;
	if (was[i][j]) re res[i][j];
	was[i][j] = 1;
	res[i][j] = 0;
	if (i < n) res[i][j] = max (res[i][j], go (i + 1, j) + p[i] * (s[i + j] - '0'));
	if (j < n) res[i][j] = max (res[i][j], go (i, j + 1) + p[j] * (s[i + j] - '0'));
	re res[i][j];
}

ll out (int i, int j) {
	if (i + j == 2 * n) re 0;
	if (i < n && res[i][j] == res[i + 1][j] + p[i] * (s[i + j] - '0')) { out (i + 1, j); printf ("H"); } else { out (i, j + 1); printf ("M"); }
	re 0;
}

int main() {
	p[0] = 1;
	for (int i = 1; i < 19; i++)
		p[i] = p[i - 1] * 10;
	cin >> n >> s;
	reverse (all (s));

	go (0, 0);

	out (0, 0);
	return 0;
}
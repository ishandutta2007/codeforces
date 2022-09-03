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
int m = 0;
string s, w;
vs v;
int res[10000];
int st[10000];

int main() {
	while (cin >> w) s += w;
	w = "";
	for (int i = 0; i < sz (s); i++) {
		if (s[i] == '<') w += ' ';
		w += s[i];
	}
	stringstream in (w);
	while (in >> s) v.pb (s);
	int r = 0;
	for (int i = 0; i < sz (v); i++) {
		if (v[i] == "<table>") {
			res[m] = 0;
			st[r] = m;
			m++; r++;
		} else
		if (v[i] == "<td>") res[st[r - 1]]++; else
		if (v[i] == "</table>") r--;
	}                           
	sort (res, res + m);
	for (int i = 0; i < m; i++) printf ("%d ", res[i]);
	printf ("\n");
	return 0;
}
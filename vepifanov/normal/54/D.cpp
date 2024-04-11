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

int n, k;
int m;
string ans = "";
int p[101];
int was[101][102];
int g[101][26];
string w, s;

int go (int i, int j) {
	if (i == n) re 1;
	if (was[i][j + 1]) re 0;
	was[i][j + 1] = 1;
	for (int c = 0; c < m; c++) {
		int nj = g[j + 1][c];
		if (nj == k - 1 && w[i] == '1' && go (i + 1, p[k - 1])) { ans = ans + char (c + 'a'); re 1; }
		if (nj != k - 1 && w[i] == '0' && go (i + 1, nj)) { ans = ans + char (c + 'a'); re 1; }
	}
	re 0;
}

int main() {
	cin >> n >> m;
	cin >> s;
	cin >> w;
	p[0] = -1;
	k = sz (s);
	while (sz (w) < n) w = "0" + w;
	for (int i = 1; i < k; i++) {
		int t = p[i - 1];
		while (t != -1 && s[t + 1] != s[i]) t = p[t];
		if (s[t + 1] == s[i]) t++;
		p[i] = t;
	} 
	for (int i = -1; i + 1 < k; i++)
		for (int c = 0; c < m; c++) {
			int t = i;
			while (t != -1 && s[t + 1] != c + 'a') t = p[t];
			if (s[t + 1] == c + 'a') t++;
			g[i + 1][c] = t;
		}
	if (go (0, -1)) {
		reverse (all (ans));
		cout << ans << endl; 
	}else cout << "No solution" << endl;
	return 0;
}
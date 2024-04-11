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
int m, ans, g[100][100], w[100][100];

int go (int x, int p, int s) {
	if (x == 0 && p != -1) {
		ans = min (ans, s);
		return 0;
	}
	for (int i = 0; i < n; i++) 
		if (g[x][i] && i != p)
			go (i, x, s + w[x][i]);
	return 0;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		g[a][b] = g[b][a] = 1;
		w[a][b] = 0;
		w[b][a] = c;
	}
	ans = 1e9;
	go (0, -1, 0);
	printf ("%d\n", ans);
	return 0;
}
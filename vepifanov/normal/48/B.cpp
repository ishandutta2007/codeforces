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
int m, a, b;
int g[50][50];

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &g[i][j]);
	scanf ("%d%d", &a, &b);
	int ans = n * m;
	for (int i = 0; i + a <= n; i++)
		for (int j = 0; j + b <= m; j++) {
			int cur = 0;
			for (int p = 0; p < a; p++)
				for (int q = 0; q < b; q++)
					cur += g[i + p][j + q];
			ans = min (ans, cur);
		}
	swap (a, b);
	for (int i = 0; i + a <= n; i++)
		for (int j = 0; j + b <= m; j++) {
			int cur = 0;
			for (int p = 0; p < a; p++)
				for (int q = 0; q < b; q++)
					cur += g[i + p][j + q];
			ans = min (ans, cur);
		}
	printf ("%d\n", ans);
	return 0;
}
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
int g[10][10];
int was[1 << 10][1 << 10];
int res[1 << 10][1 << 10];

int go (int mask, int leaf, int cn, int cl) {
	if (cl < 2) re 0;
	if (cn == 2) {
		int x = -1, y = -1;
		for (int i = 0; i < n; i++)
			if ((mask >> i) & 1)
				if (x == -1) x = i; else y = i;
		re g[x][y];
	}
	if (cl == n) re 0;
	if (was[mask][leaf]) re res[mask][leaf];
	was[mask][leaf] = 1;
	int cur = 0;
	for (int i = 0; i < n; i++)
		if ((leaf >> i) & 1) {
			for (int j = 0; j < n; j++)
				if (((mask >> j) & 1) && ((leaf >> j) & 1) == 0 && g[i][j]) 
					cur += go (mask - (1 << i), leaf - (1 << i), cn - 1, cl - 1) + go (mask - (1 << i), leaf - (1 << i) + (1 << j), cn - 1, cl);
			break;
		}
	res[mask][leaf] = cur;
	re cur;
}

int main() {
	scanf ("%d%d%d", &n, &m, &k);	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b);
		a--; b--;
		g[a][b] = g[b][a] = 1;
	}
	int tmp = 0;
	for (int i = 0; i < (1 << n); i++) {
		int s = 0;
		for (int j = 0; j < n; j++) s += (i >> j) & 1;
		if (s == k) tmp += go ((1 << n) - 1, i, n, k);
	}
	printf ("%d\n", tmp);
	return 0;
}
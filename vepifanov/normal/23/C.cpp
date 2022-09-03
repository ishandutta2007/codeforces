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
int p[200000], x[200000], y[200000];

bool myless (int i, int j) {
	return x[i] > x[j] || x[i] == x[j] && i < j;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &m); m = m * 2 - 1;
		for (int j = 0; j < m; j++) {
			scanf ("%d%d", &x[j], &y[j]);
			p[j] = j;
		}
		sort (p, p + m, myless);
		long long s[2];
		s[0] = s[1] = 0;
		for (int j = 1; j < m; j++)
			s[j & 1] += y[p[j]];
		int r = 0;
		if (s[1] > s[0]) r = 1;
		printf ("YES\n");
		printf ("%d", p[0] + 1);
		for (int j = 2 - r; j < m; j += 2) printf (" %d", p[j] + 1);
		printf ("\n");
	}
	return 0;
}
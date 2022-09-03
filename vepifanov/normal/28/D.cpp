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

const int MAX = 200000;

int n;
int m;
int res[MAX], v[MAX], l[MAX], r[MAX], c[MAX], prev[MAX];
map<pair<int, int>, int> all;

int out (int x, int c) {
	if (x == -1) printf ("%d\n", c); else {
		out (prev[x], c + 1);
		printf ("%d ", x + 1);
	}
	re 0;
}

int upd (int a, int b, int i) {
	if (!all.count(mp (a, b)) || res[all[mp (a, b)]] < res[i]) all[mp (a, b)] = i;
	re 0;
}

int get (int a, int b) {
	if (all.count (mp (a, b))) re all[mp (a, b)];
	re -1;
}

int main() {
	scanf ("%d", &n);
	memset (res, 0, sizeof (res));
	memset (prev, 0, sizeof (prev));
	for (int i = 0; i < n; i++) {
		scanf ("%d%d%d%d", &v[i], &c[i], &l[i], &r[i]);
		if (l[i] == 0) {
			res[i] = v[i];
			prev[i] = -1;
			upd (c[i] + l[i], r[i], i);
		}
	}	
	int ans = 0;
	int last = -1;
	for (int i = 0; i < n; i++) {
		int j = get (l[i], c[i] + r[i]);
		if (j != -1 && res[i] < res[j] + v[i]) {
			res[i] = res[j] + v[i];
			prev[i] = j;
			upd (c[i] + l[i], r[i], i);
		}
		if (r[i] == 0 && res[i] > ans) {
			ans = res[i];
			last = i;
		}
	}
	out (last, 0);
	if (ans > 0) printf ("\n");
	return 0;
}
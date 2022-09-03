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
int m, k;
int d[100], x[100];
vi res;

int main() {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) scanf ("%d", &d[i]);
	for (int i = 0; i < k; i++) scanf ("%d", &x[i]);
	int ans = k + 1;
	for (int i = 0; i < m; i++) {
		int cur = 0;
		for (int j = 0; j < k; j++)
			cur += int (x[j] % d[i] == 0);
		if (cur < ans) { ans = cur; res.clear (); }
		if (cur == ans) res.pb (i + 1);
	}
	printf ("%d\n", sz (res));
	for (int i = 0; i < sz (res); i++) printf ("%d ", res[i]);
	printf ("\n");
	return 0;
}
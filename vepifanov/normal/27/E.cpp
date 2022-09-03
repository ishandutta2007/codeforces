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

const ll inf = 2e18;

int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int n;
int m;
bool was[1001][11][70];
ll res[1001][11][70];

ll go (int n, int i, int l) {
	if (n == 1) re 1;
	if (i == 10) re inf;
	if (was[n][i][l]) re res[n][i][l];
	was[n][i][l] = 1;
	ll tmp = inf, cur = 1, tmp2;
	for (int j = 1; j <= l; j++) {
		if (cur > inf / p[i]) break;
		cur *= p[i];
		if (n % (j + 1) == 0) {
			tmp2 = go (n / (j + 1), i + 1, j);
			if (tmp2 <= inf / cur) tmp = min (tmp, tmp2 * cur);
		}
	}
	res[n][i][l] = tmp;
	re tmp;
}

int main() {
	scanf ("%d", &n);

	printf ("%I64d\n", go (n, 0, n));
		
	return 0;
}
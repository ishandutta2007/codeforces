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
double prob[1001][1001];
ll x[1000], y[1000];

ll calc (ll x) {
        ll a = 1, b = 1, res = 0;
        while (true) {
        	res += max (0LL, min (x, b) - a + 1);
        	if (a > x / 10) break;
        	a = a * 10;
        	b = b * 10 + 9;
        }
        re res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		y[i] = r - l + 1;
		x[i] = calc (r) - calc (l - 1);
	}
	cin >> m;
	memset (prob, 0, sizeof (prob));
	prob[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++) {
			prob[i + 1][j] += prob[i][j] / y[i] * (y[i] - x[i]);
			prob[i + 1][j + 1] += prob[i][j] / y[i] * x[i];
		}
	double res = 0;
	for (int i = 0; i <= n; i++)
		if (100 * i >= n * m)
			res += prob[n][i];
	printf ("%.10f\n", res);
	return 0;
}
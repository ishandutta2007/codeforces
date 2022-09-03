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
vi res;
pair<ii, int> x[10000];

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &x[i].fi.fi, &x[i].fi.se);
		x[i].se = i + 1;
	}	
	sort (x, x + n);
	for (int i = 1; i <= n; i++) {
		int k = -1, ok = 1;
		for (int j = 0; j < n; j++) 
			if (x[j].se != i) {
				if (k != -1) {
					if (x[j].fi.fi < x[k].fi.se) {
						ok = 0;
						break;
					}
				}
				k = j;
			}
		if (ok) res.pb (i);
	}
	printf ("%d\n", sz (res));
	for (int i = 0; i < sz (res); i++)
		printf ("%d ", res[i]);
	printf ("\n");
	return 0;
}
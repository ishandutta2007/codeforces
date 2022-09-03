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
vii v;

int main() {
	int n, t;
	scanf ("%d%d", &n, &t);
	for (int i = 0; i < n; i++) {
		int x, a;
		scanf ("%d%d", &x, &a);
		v.push_back (make_pair (x, a));
	}
	sort (v.begin (), v.end ());
	int ans = 2;
	for (int i = 0; i + 1 < n; i++)
		if (2 * (v[i + 1].fi - v[i].fi) > v[i].se + v[i + 1].se + 2 * t) ans += 2; else
		if (2 * (v[i + 1].fi - v[i].fi) == v[i].se + v[i + 1].se + 2 * t) ans++;
	printf ("%d\n", ans);
	return 0;
}
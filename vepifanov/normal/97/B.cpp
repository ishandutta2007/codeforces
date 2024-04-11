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
ii v[300000];
            
int go (int l, int r) {
	if (l + 1 >= r) re 0;
	int s = l + (r - l) / 2;
	int x = v[s].fi;
	int nl = l, nr = r;
	while (nl < r && v[nl].fi < x) nl++;
	while (nr > l && v[nr - 1].fi > x) nr--;
	go (l, nl);
	go (nr, r);
	set<int> all;
	for (int i = l; i < nl; i++) all.insert (v[i].se);
	for (int i = nr; i < r; i++) all.insert (v[i].se);
	for (int i = nl; i < nr; i++) all.erase (v[i].se);
	set<int>::iterator it;
	for (it = all.begin (); it != all.end (); it++)
		v[n++] = mp (x, *it);
	re 0;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d%d", &v[i].fi, &v[i].se);
	sort (v, v + n);
	go (0, n);
	printf ("%d\n", n);
	for (int i = 0; i < n; i++) printf ("%d %d\n", v[i].fi, v[i].se);
	return 0;
}
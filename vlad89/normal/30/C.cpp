#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/STACK:256000000")
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

pair <pair <int, double>, pii> a[1024];
double d[1024];

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf ("%d", &n);
	REP (i, n) 
		scanf ("%d%d%d%lf", &a[i].Y.X, &a[i].Y.Y, &a[i].X.X, &a[i].X.Y);		
	sort (a, a + n);
#define sqr(x) ((x)*(x))
	REP (i, n) {
		d[i] += a[i].X.Y;
		FOR (j, i + 1, n)
			if (sqr (a[j].Y.X - a[i].Y.X) + sqr (a[j].Y.Y - a[i].Y.Y) <= (long long) (a[j].X.X - a[i].X.X) * (a[j].X.X - a[i].X.X))
				d[j] = max (d[j], d[i]);
	}
	printf ("%.10lf\n", *max_element (d, d + n));
	return 0;
}
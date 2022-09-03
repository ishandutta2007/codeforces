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

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		int n, m, x1, y1, x2, y2;
		scanf ("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
		int dx = abs (x2 - x1);
		int dy = abs (y2 - y1);
		if (n - dx >= dx && m - dy >= dy)
			printf ("%I64d\n", 2 * (long long)dx * dy);
		else
			printf ("%I64d\n", 2 * (long long)dx * dy - (long long)(2 * dx - n) * (2 * dy - m));			
	}
	
	return 0;
}
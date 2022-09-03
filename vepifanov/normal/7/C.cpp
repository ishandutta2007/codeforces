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

long long gcd (long long a, long long b, long long *x, long long *y) {
	if (!a) {
		*x = 0;
		*y = 1;
		return b;
	}
	long long nx, ny;
	long long d = gcd (b % a, a, &nx, &ny);
	long long k = b / a;
	*y = nx;
	*x = -k * nx + ny;
	return d;
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long x, y;
	int qa = int (a < 0) - int (a > 0), qb = int (b < 0) - int (b > 0);
	long long d = gcd (abs (a), abs (b), &x, &y);
	if (abs (c) % d != 0) cout << "-1" << endl; else {
		c /= d;
		cout << x * qa * c << " " << y * qb * c << endl; 	
	}
	return 0;
}
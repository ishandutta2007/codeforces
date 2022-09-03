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

const int ms[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int d, m, y, a, b, c;

int check (int a, int b, int c) {
	if (b < 1 || b > 12 || a < 1 || a > ms[b] + int (b == 2 && c % 4 == 0)) re 0;
	re (c + 18 < y || c + 18 == y && b < m || c + 18 == y && b == m && a <= d);
}

int main() {
	scanf ("%d.%d.%d", &d, &m, &y);
	scanf ("%d.%d.%d", &a, &b, &c);
	if (check (a, b, c) || check (a, c, b) || check (b, a, c) || check (b, c, a) || check (c, a, b) || check (c, b, a)) printf ("YES\n"); else printf ("NO\n");
	return 0;
}
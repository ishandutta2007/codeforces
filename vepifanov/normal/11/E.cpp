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

char w[1000010];
int x[1000010];

int main() {
	gets (w);
	int n = strlen (w);
	int m = int (w[0] == 'R' && w[n - 1] == 'R'), k = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && w[i] == w[i - 1] && w[i] != 'X') m++;
		if (w[i] != 'X') { x[r++] = 1 - (int (w[i] == 'R') == (m & 1)); m += x[r - 1];}
		m++;
	}
	int M = m;
	if (M % 2 == 0) M++;
	long double ans = r / (2.0 * M);
	M = m;
	int R = r;
	if (M & 1) { x[r++] = 1; M++; }
	for (int i = 0; i < r; i++)
		if (x[i] == 1 && x[i + 1] == 1)
			if ((long long)R * (M - 2) <= (long long)(R - 1) * M) {
				M -= 2;
				R--;
				i++;
			}
	if ((long double)R / M > ans) ans = (long double)R / M;
	long long ANS = ans * 100000000 + 0.0000001;
	printf ("%.6f\n", ANS / 1000000.0);
	return 0;
}
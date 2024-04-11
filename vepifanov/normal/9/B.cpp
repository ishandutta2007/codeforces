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

int x[101];

int main() {
	int n, vb, vs;
	scanf ("%d%d%d", &n, &vb, &vs);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	int X, Y;
	scanf ("%d%d", &X, &Y);
	int ai = -1;
	double ans = 1e9, dans = 1e9;;
	for (int i = 1; i < n; i++) {
		double cur = (x[i] - x[0] + 0.0) / vb + sqrt ((X - x[i] + 0.0) * (X - x[i]) + (Y + 0.0) * Y) / vs;
		double dcur = sqrt ((X - x[i] + 0.0) * (X - x[i]) + (Y + 0.0) * Y);
		if (cur < ans - 1e-7 || cur < ans + 1e-7 && dcur < dans - 1e-7) {
			ans = cur;
			dans = dcur;
			ai = i;	
		}
	}
	printf ("%d\n", ai + 1);
	return 0;
}
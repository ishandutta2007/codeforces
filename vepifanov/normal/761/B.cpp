#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

int n;
int m;
int x[51];
int y[51];
int p[51];
int q[51];

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
	x[n] = x[0] + m;
	y[n] = y[0] + m;
	for (int i = 0; i < n; i++) {
		p[i] = x[i + 1] - x[i];
		q[i] = y[i + 1] - y[i];
	}
	for (int i = 0; i < n; i++) {
		int ok = 1;
		for (int j = 0; j < n; j++)
			ok &= int (p[j] == q[(i + j) % n]);
		if (ok) {
			printf ("YES\n");
			return 0;
		}
	}
	printf ("NO\n");
	return 0;
}
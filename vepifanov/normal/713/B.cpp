#include <bits/stdc++.h>

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

int ask (int x1, int y1, int x2, int y2) {
	printf ("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush (stdout);
	int k;
	scanf ("%d", &k);
	re k;
}

int cool (int x1, int x2, int y1, int y2, int x3, int x4, int y3, int y4) {
	if (x1 > x2 || y1 > y2 || x3 > x4 || y3 > y4) re 0;
	if (max (x1, x3) < min (x2, x4) && max (y1, y3) < min (y2, y4)) re 0;
	if (ask (x1, y1, x2, y2) != 1) re 0;
	if (ask (x3, y3, x4, y4) != 1) re 0;
	printf ("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
	fflush (stdout);
	re 1;
}

int main () {
	scanf ("%d", &n);
	int rx1, rx2, ry1, ry2;
	int lx1, ly1, lx2, ly2;
	{
		int l = 1, r = n + 1;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (ask (s, 1, n, n) >= 1) l = s; else r = s;
		}
		lx1 = l;
	}
	{
		int l = 1, r = n + 1;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (ask (s, 1, n, n) >= 2) l = s; else r = s;
		}
		lx2 = l;
	}
	{
		int l = 1, r = n + 1;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (ask (1, s, n, n) >= 1) l = s; else r = s;
		}
		ly1 = l;
	}
	{
		int l = 1, r = n + 1;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (ask (1, s, n, n) >= 2) l = s; else r = s;
		}
		ly2 = l;
	}
	{
		int l = 0, r = n;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (ask (1, 1, s, n) <= 0) l = s; else r = s;
		}
		rx1 = r;
	}
	{
		int l = 0, r = n;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (ask (1, 1, s, n) <= 1) l = s; else r = s;
		}
		rx2 = r;
	}
	{
		int l = 0, r = n;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (ask (1, 1, n, s) <= 0) l = s; else r = s;
		}
		ry1 = r;
	}
	{
		int l = 0, r = n;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (ask (1, 1, n, s) <= 1) l = s; else r = s;
		}
		ry2 = r;
	}
	if (cool (lx1, rx1, ly1, ry1, lx2, rx2, ly2, ry2)) re 0;
	if (cool (lx1, rx1, ly1, ry2, lx2, rx2, ly2, ry1)) re 0;
	if (cool (lx1, rx2, ly1, ry1, lx2, rx1, ly2, ry2)) re 0;
	if (cool (lx1, rx2, ly1, ry2, lx2, rx1, ly2, ry1)) re 0;
	if (cool (lx1, rx1, ly2, ry2, lx2, rx2, ly1, ry1)) re 0;
	if (cool (lx1, rx1, ly2, ry1, lx2, rx2, ly1, ry2)) re 0;
	if (cool (lx1, rx2, ly2, ry2, lx2, rx1, ly1, ry1)) re 0;
	if (cool (lx1, rx2, ly2, ry1, lx2, rx1, ly1, ry2)) re 0;
	return 0;
}
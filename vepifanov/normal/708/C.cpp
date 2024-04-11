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

const int N = 400000;

int n;
int m;
int mid;
int col[N];
int cnt[N];
vi v[N];

int go (int x, int p, int c) {
	col[x] = c;
	cnt[x] = 1;
	int up = n - 1;
	int down = 0;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i];
		if (y == p) continue;
		int z = go (y, x, c);
		down = max (down, z);
		cnt[x] += z;
		up -= z;
	}
	if (mid == -1 && max (up, down) <= n / 2) mid = x;
	re cnt[x];
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	mid = -1;
	go (0, 0, -1);
	ii t1 (0, -1), t2 (0, -1);
	for (int i = 0; i < sz (v[mid]); i++) {
		ii cur (go (v[mid][i], mid, i), i);
		if (cur > t1) { t2 = t1; t1 = cur; } else
		if (cur > t2) { t2 = cur; }
	}
	for (int i = 0; i < n; i++) {
		int ok = 0;
		if (i == mid)
			ok = 1;
		else {
			int j = col[i];
			int up = n - cnt[i];
			if (up <= n / 2) ok = 1; else {
				if (t1.se != j && up - t1.fi <= n / 2) ok = 1; else
				if (t2.se != j && up - t2.fi <= n / 2) ok = 1; else
				if (n - cnt[v[mid][j]] <= n / 2) ok = 1;
			}
		}
		printf ("%d ", ok);
	}
	printf ("\n");
	return 0;
}
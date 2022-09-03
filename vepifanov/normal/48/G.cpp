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

int n, r = 0;
int m;
int prev[200001], was[200001], q[200001], ql[200001], pl[200001], cyc[200001], cnt[200001];
ll sum[200001];
ll res[200001];
vii v[200001];

inline int gp (int x) {
	if (x > 0) re x - 1; else re r - 1;
}

inline int gn (int x) {
	if (x + 1 < r) re x + 1; else re 0;
}

inline int sp (int x) {
	re ql[x];
}

inline int sn (int x) {
	if (x + 1 < r) re ql[x + 1]; else re ql[0];
}

int go (int x, int p, int l) {
//	printf ("%d %d %d\n", x, p, l);
	prev[x] = p;
	pl[x] = l;
	was[x] = 1;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i].fi;
		int z = v[x][i].se;
		if (was[y] && p != y) {
			r = 0;
			int k = x;
			ql[0] = z;
			while (true) {
				cyc[k] = 1;
				q[r++] = k;
				if (k == y) break;
				ql[r] = pl[k];
				k = prev[k];
			}
			re 1;
		} else
		if (!was[y] && go (y, x, z)) re 1;
	}           
	re 0;
}

int go2 (int x, int p, int l) {
	sum[x] = 0;
	cnt[x] = 1;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i].fi;
		if (cyc[y]) continue;
		int z = v[x][i].se;
		if (p != y) {
			go2 (y, x, z);
			sum[x] += sum[y] + cnt[y] * z;
			cnt[x] += cnt[y];
		}
	}
	re 0;
}

int go3 (int x, int p, int l) {
	prev[x] = p;
	pl[x] = l;
	if (x != p) res[x] = res[p] - l * cnt[x] + l * (n - cnt[x]);
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i].fi;
		if (cyc[y]) continue;
		int z = v[x][i].se;
		if (p != y) go3 (y, x, z);
	}
	re 0;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		v[a].pb (mp (b, c));
		v[b].pb (mp (a, c));
	}
	go (0, 0, -1);
	ll all = 0;
	for (int i = 0; i < r; i++) {
		go2 (q[i], q[i], 0);
		all += sum[q[i]];
//		printf ("%I64d %d %d\n", sum[q[i]], q[i], ql[i]);
	}
	int a = 0, b = 0, sa = 0, sb = 0, ca = 0, cb = 0;
	ll ra = 0, rb = 0;
	while (gp (a) != b)
		if (sa + sp (a) < sb + sn (b)) { 
			sa += sp (a); 
			a = gp (a); 
			ca += cnt[q[a]];
			ra += (ll)sa * cnt[q[a]]; 
//			printf ("ra += %d * %d\n", sa, cnt[q[a]]);
		} else {
			sb += sn (b); 
			b = gn (b); 
			cb += cnt[q[b]];
			rb += (ll)sb * cnt[q[b]];
		}
	for (int i = 0; i < r; i++) {
		while (sb + sn (b) < sa) { 
			ca -= cnt[q[a]];
			cb += cnt[q[a]];
			ra -= (ll)sa * cnt[q[a]];
			sa -= sn (a); 
			sb += sn (b); 
			rb += (ll)sb * cnt[q[a]];
			a = gn (a); 
			b = gn (b); 
		}
//		printf ("%d %d | %d %d | %I64d %I64d %I64d | %d %d\n", a, b, sa, sb, ra, rb, all, ca, cb);
		res[q[i]] = all + ra + rb;
//		printf ("%d = %I64d\n", q[i] + 1, res[q[i]]);
		go3 (q[i], q[i], 0);
		if (cb == 0) {
			ca -= cnt[q[a]];
			cb += cnt[q[a]];
			ra -= (ll)sa * cnt[q[a]];
			sa -= sn (a); 
			sb += sn (b); 
			rb += (ll)sb * cnt[q[a]];
			a = gn (a); 
			b = gn (b); 
//			printf ("go %d %d %d %d %I64d %I64d %I64d %d %d\n", a, b, sa, sb, ra, rb, all, ca, cb);
		}
		ra += (ll)(ca + cnt[q[i]]) * sn (i);
		rb -= (ll)cb * sn (i);
		ca += cnt[q[i]]; 
		cb -= cnt[q[gn (i)]];
//		printf ("%d\n", sn (i));
		sa += sn (i); 
		sb -= sn (i);
	}
	for (int i = 0; i < n; i++) printf ("%I64d ", res[i]);
	printf ("\n");
	return 0;
}
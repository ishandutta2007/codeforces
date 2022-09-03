#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
 
using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;
 
template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
 
int n;
int m[2];
int p[2][100000];
vii res;
set<pair<ii, int> > all;
set<ii> all2;
int r[2];

int gp (int t, int x) {
	if (p[t][x] != x) p[t][x] = gp (t, p[t][x]);
	re p[t][x];
}

int main () {
	scanf ("%d%d%d", &n, &m[0], &m[1]);
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < n; i++) p[t][i] = i;
		r[t] = n;
		for (int i = 0; i < m[t]; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			int pa = gp (t, a);
			int pb = gp (t, b);
			if (pa != pb) {
				if (rand () & 1) swap (pa, pb);
				p[t][pa] = pb;
				r[t]--;
			}
		}
	}
	while (sz (res) < min (r[0], r[1]) - 1) {
		all.clear ();
		all2.clear ();
		for (int i = 0; i < n; i++) {
			if (all2.count (mp (gp (0, i), gp (1, i)))) continue;
			all2.insert (mp (gp (0, i), gp (1, i)));
			all.insert (mp (mp (gp (0, i), gp (1, i)), i));
//	//		printf ("%d %d %d\n", gp (0, i) + 1, gp (1, i) + 1, i + 1);
		}
		for (auto it = all.begin (); it != all.end (); it++) {
			int a = gp (0, it->fi.fi);
			int b = gp (1, it->fi.se);
			int c = it->se;
//	//		printf ("%d %d %d\n", a + 1, b + 1, c + 1);
			while (true) {
				auto it1 = next (it, 1);
				if (it1 == all.end ()) break;
				int a1 = gp (0, it1->fi.fi);
				int b1 = gp (1, it1->fi.se);
				int c1 = it1->se;
				if (it1->fi.fi != a1 || it1->fi.se != b1) {
					all.erase (it1);
					all.insert (mp (mp (a1, b1), c1));
					continue;
				}
//	//			printf ("	%d %d %d\n", a1 + 1, b1 + 1, c1 + 1);
				if (a != a1 && b != b1) {
					res.pb (mp (c, c1));
					assert (gp (0, c) != gp (0, c1) && gp (1, c) != gp (1, c1));
					p[0][a1] = a;
					p[1][b1] = b;
					all.erase (it1);
					continue;
				}
	    
				auto it2 = next (it1, 1);
				if (it2 == all.end ()) break;
				int a2 = gp (0, it2->fi.fi);
				int b2 = gp (1, it2->fi.se);
				int c2 = it2->se;
//	//			printf ("		%d %d %d\n", a2 + 1, b2 + 1, c2 + 1);
				if (it2->fi.fi != a2 || it2->fi.se != b2) {
					all.erase (it2);
					all.insert (mp (mp (a2, b2), c2));
					continue;
				}
				if (a != a2 && b != b2) {
					res.pb (mp (c, c2));
					assert (gp (0, c) != gp (0, c2) && gp (1, c) != gp (1, c2));
					p[0][a2] = a;
					p[1][b2] = b;
					all.erase (it2);
					continue;
				}
				break;
			}
		}
		cerr << sz (res) << " " << min (r[0], r[1]) << endl;
	}	
	printf ("%d\n", sz (res));
	for (auto& x : res) printf ("%d %d\n", x.fi + 1, x.se + 1);
    re 0;
}
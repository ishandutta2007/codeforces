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
#define next NEXT

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

const int N = 1000010;

int n;
int m;
char h[N];
int p[N];
int q[N];
set<int> allp;
set<int> allq;
int cl[N];
int cr[N];
vii vlp[N];
vii vlq[N];
vii vrp[N];
vii vrq[N];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf (" %s", h);
		n = strlen (h);
		for (int i = 0; i < n; i++) {
			vlp[i].clear ();
			vlq[i].clear ();
			vrp[i].clear ();
			vrq[i].clear ();
			cl[i] = cr[i] = 0;
		}

		int l = 0, r = -1;
		for (int i = 0; i < n; i++) {
			int k = (i > r ? 0 : min (p[l + r - i], r - i + 1));
			while (i + k < n && i - k >= 0 && h[i + k] == h[i - k]) k++;
			p[i] = k--;
			if (p[i] > 1) {
				if (2 * i < n) {
					vlp[i - p[i] + 1].pb (mp (0, i));
					if (i < n) vlp[i + 1].pb (mp (1, i));
				}
				if (2 * i + 1 >= n)	{
					vrp[i + p[i] - 1].pb (mp (0, i));
					if (i > 0) vrp[i - 1].pb (mp (1, i));
				}	
			}	
			if (i + k > r) {
				l = i - k;
				r = i + k;
			}
		}
		l = 0;
		r = -1;
		for (int i = 0; i < n; i++) {
			int k = (i > r ? 0 : min (q[l + r - i + 1], r - i + 1)) + 1;
			while (i + k - 1 < n && i - k >= 0 && h[i + k - 1] == h[i - k]) k++;
			k--;
			q[i] = k;
			if (q[i] > 0) {
				if (2 * i <= n) {
					vlq[i - q[i]].pb (mp (0, i));
					vlq[i].pb (mp (1, i));
				}
				if (2 * i >= n)	{
					vrq[i + q[i] - 1].pb (mp (0, i));
					if (i > 0) vrq[i - 1].pb (mp (1, i));
				}	
		    }
			if (i + k - 1 > r) {
				l = i - k;
				r = i + k - 1;
			}
		}
		{
			allp.clear ();
			allq.clear ();
			for (int i = 0; 2 * i < n; i++) {
//				printf ("addl %d\n", i);
				for (auto& x : vlp[i])
					if (x.fi == 0)
						allp.insert (x.se);
					else
						allp.erase (x.se);	
				for (auto& x : vlq[i])
					if (x.fi == 0)
						allq.insert (x.se);
					else
						allq.erase (x.se);	
				int cur = 1;
				if (!allp.empty ()) {
					int j = *allp.rbegin ();
//					printf ("odd %d -> %d\n", i, j);
					cur = max (cur, 2 * (j - i) + 1);
				}
				if (!allq.empty ()) {
					int j = *allq.rbegin ();
//					printf ("even %d -> %d\n", i, j);
					cur = max (cur, 2 * (j - i));
				}
				cl[i] = cur;
			}
		}
		{
			allp.clear ();
			allq.clear ();
			for (int i = n - 1; 2 * i + 1 >= n; i--) {
				for (auto& x : vrp[i])
					if (x.fi == 0)
						allp.insert (x.se);
					else
						allp.erase (x.se);	
				for (auto& x : vrq[i])
					if (x.fi == 0)
						allq.insert (x.se);
					else
						allq.erase (x.se);	
				int cur = 1;
				if (!allp.empty ()) {
					int j = *allp.begin ();
//					printf ("odd %d -> %d\n", i, j);
					cur = max (cur, 2 * (i - j) + 1);
				}
				if (!allq.empty ()) {
					int j = *allq.begin ();
//					printf ("even %d -> %d\n", i, j);
					cur = max (cur, 2 * (i - j) + 2);
				}
//				printf ("add %d = %d\n", i, cur);
				cr[i] = cur;
			}
		}
		if (cl[0] == n) {
			printf ("%s\n", h);
			continue;
		}
		int ans = 0;
		int both = 0, bl = 0, br = 0;
		for (int i = 0; 2 * i <= n; i++) {
			if (2 * i + cl[i] > ans) {
				ans = 2 * i + cl[i];
				both = i;
				bl = cl[i];
				br = 0;
			}
			if (2 * i + cr[n - i - 1] > ans) {
				ans = 2 * i + cr[n - i - 1];
				both = i;
				bl = 0;
				br = cr[n - i - 1];
			}
			if (h[i] != h[n - i - 1]) break;
		}
//		printf ("%d %d %d\n", both, bl, br);
		assert (ans < n);
		for (int i = 0; i < both; i++) printf ("%c", h[i]);
		for (int i = 0; i < bl; i++) printf ("%c", h[both + i]);
		for (int i = 0; i < br; i++) printf ("%c", h[n - both - br + i]);
		for (int i = 0; i < both; i++) printf ("%c", h[n - both + i]);
		printf ("\n");
	}
	re 0;
}
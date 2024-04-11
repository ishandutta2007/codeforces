#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define re return
#define y0 y2415
#define y1 y346246
#define j0 j23562456
#define j1 j245623456
#define sqrt(x) sqrt (abs (x))

typedef unsigned long long ull;
typedef long long ll;
typedef double D;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <string> vs;

template <class T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }

const ld pi = acos (-1.0);

int n;
int m;
int k;

set<int> all;
int p[150000];

int main()
{
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
    for (int i = 0; i < k; i++) {
    	int t, x;
    	scanf ("%d%d", &t, &x); x--;
    	if (t == 1) {
    		all.insert (p[x]);
    		if (sz (all) > m) all.erase (all.begin ());    		
    	} else {
    		printf ("%s\n", all.count (p[x]) ? "YES" : "NO");
    	}
    }
	return 0;
}
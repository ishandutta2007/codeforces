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

bitset<500100> g[60];

int main()
{
	scanf ("%d", &n);
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		ll a, b;
		scanf ("%I64d%I64d", &a, &b);
		cur ^= a;
		b ^= a;
		for (int j = 0; j < 60; j++)
			g[j][i] = (b >> j) & 1;
	}
	for (int j = 0; j < 60; j++)
		g[j][n] = (cur >> j) & 1;
/*
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j <= n; j++)
			printf ("%d ", (int)g[i][j]);
		printf ("\n");
	}
	printf ("\n");
*/
	int rem = 0;
	for (int i = 0; i < 60 && i < n; i++) {
		if (!g[i][i])
			for (int j = i; j < 60; j++)
				if (g[j].count () - int (g[j][n] == 1) > 0) {
					for (int k = i; k < n; k++)
						if (g[j][k]) {
							if (i != j)
								swap (g[i], g[j]);
							for (int t = 0; t < 60; t++) {
								int tmp = g[t][i];
								g[t][i] = g[t][k];
								g[t][k] = tmp;
                            }
				        	break;
						}
					break;
				}
		if (!g[i][i]) break;
		rem++;
		for (int j = i + 1; j < 60; j++)
			if (g[j][i])
				g[j] ^= g[i];
	}
	for (int i = rem; i < 60; i++)
		if (g[i][n]) {
			printf ("1/1\n");
			re 0;
		}
	cout << ((ll)1 << rem) - 1 << "/" << ((ll)1 << rem) << endl;
	cerr << clock () << endl;
	return 0;
}
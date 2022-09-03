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
string s[2], t[2];

set<string> all;

int go () {
	if (s[0] == t[0] && s[1] == t[1]) re 1;
	if (all.count (s[0] + s[1])) re 0;
	all.insert (s[0] + s[1]);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (s[i][j] == 'X')
				for (int a = 0; a < 2; a++)
					for (int b = 0; b < 2; b++)
						if (a == i || b == j)
							if (s[a][b] != 'X') {
								swap (s[a][b], s[i][j]);
								if (go ()) re 1;
								swap (s[a][b], s[i][j]);
							}
	re 0;
}

int main () {
	for (int i = 0; i < 2; i++) cin >> s[i];
	for (int i = 0; i < 2; i++) cin >> t[i];
	printf ("%s\n", go () ? "YES" : "NO");
	return 0;
}
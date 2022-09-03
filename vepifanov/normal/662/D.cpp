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

map<string, int> all;

int main()
{
	for (int i = 1989; i < 100000; i++) {
		string s = "";
		int j = i;
		while (j) {
			s = char (j % 10 + '0') + s;
			j /= 10;
		}
		for (int k = 1; k <= sz (s); k++)
			if (all.count (s.substr (sz (s) - k, k)) == 0) {
				all[s.substr (sz (s) - k, k)] = i;
				break;
			}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		s.erase (0, 4);
		if (all.count (s)) cout << all[s] << endl; else {
			string w = s;
			w.erase (sz (w) - 4, 4);
			for (int j = 0; j < sz (w); j++) w[j] = '1';
			w += "3098";
			if (s <= w) s = "1" + s;
			cout << s << endl;
		}
	}
	return 0;
}
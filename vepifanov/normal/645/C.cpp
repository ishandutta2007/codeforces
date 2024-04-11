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
string s;
vi v;

int calc (int a, int b, int c) {
	re max (abs (v[a] - v[c]), abs (v[b] - v[c]));
}

int main () {
	cin >> n >> m; m++;
	cin >> s;
	for (int i = 0; i < n; i++)
		if (s[i] == '0')
			v.pb (i);
	int ans = 1e9;
	for (int i = 0, j = 0; i + m <= sz (v); i++) {
		while (j + 1 < i + m && calc (i, i + m - 1, j) >= calc (i, i + m - 1, j + 1)) j++;
		ans = min (ans, calc (i, i + m - 1, j));
	}
	cout << ans << endl;
	return 0;
}
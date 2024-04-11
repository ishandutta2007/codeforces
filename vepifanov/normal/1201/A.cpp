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

int n;
int m;
string s[1000];
int x[1000];
int cnt[5];

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < m; i++) cin >> x[i];
	int ans = 0;
	for (int i = 0; i < m; i++) {
		memset (cnt, 0, sizeof (cnt));
		for (int j = 0; j < n; j++) cnt[s[j][i] - 'A']++;
		int best = 0;
		for (int j = 0; j < 5; j++) best = max (best, cnt[j]);
		ans += best * x[i];
	}
	cout << ans << endl;
	re 0;
}
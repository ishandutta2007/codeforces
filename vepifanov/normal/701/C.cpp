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
string s;

set<char> all;
int cnt[255];

int main () {
	cin >> n >> s;
	for (int i = 0; i < n; i++) all.insert (s[i]);
	int need = sz (all);
	int cur = 0, ans = n;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && cur != need) {
			if (cnt[s[j]] == 0) cur++;
			cnt[s[j]]++;
			j++;
		}
		if (cur == need) ans = min (ans, j - i);
		cnt[s[i]]--;
		if (cnt[s[i]] == 0) cur--;
	}
	printf ("%d\n", ans);
	return 0;
}
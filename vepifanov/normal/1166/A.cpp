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
int cnt[26];

int main () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cnt[s[0] - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		int a = cnt[i] / 2;
		int b = (cnt[i] + 1) / 2;
		ans += a * (a - 1) / 2 + b * (b - 1) / 2;
	}
	cout << ans << endl;
	re 0;
}
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

int main () {
	int tt;
	cin >> tt;
	for (int it = 0; it < tt; it++) {
		ll n;
		cin >> n;
		ll ans = 1e18;
		for (int a = 0; a < 20; a++)
			for (int b = 0; b < 20; b++)
				if (a * 6 + b * 8 < n)
					ans = min (ans, a * 15 + b * 20 + ((n - a * 6 - b * 8 + 9) / 10) * 25);
				else
					ans = min (ans, (ll)a * 15 + b * 20);	
		cout << ans << endl;
	}
		
    re 0;
}
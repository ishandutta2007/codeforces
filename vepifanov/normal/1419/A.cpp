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
char h[10000];
int can[2];

int main () {
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
    	scanf ("%d %s", &n, h);
    	int ans = 0;
    	if (n % 2 == 1) {
    		ans = 2;
    		for (int i = 0; i < n; i += 2)
    			if ((h[i] - '0') % 2 == 1)
    				ans = 1;
    	} else {
    		ans = 1;
    		for (int i = 1; i < n; i += 2)
    			if ((h[i] - '0') % 2 == 0)
    				ans = 2;
    	}
    	printf ("%d\n", ans);
    }
	re 0;
}
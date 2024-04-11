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

const ll MAX = 1e18;

int n;
int m;

int a[200001];

int main()
{
    scanf ("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) scanf ("%d", &a[i]);
    ll cur = 0;
    int pw = 0;
    for (int i = 0; i < n; i++) {
    	if ((cur + a[i]) % 2 != 0) break;
    	cur = (cur + a[i]) / 2;
    	pw++;
    }
    ll delta = 0;
    for (int i = n; i >= pw; i--) {
    	delta = delta * 2 + a[i];
    	if (abs (delta) > MAX) {
    		printf ("0\n");
    		re 0;
    	}
    }
    cur += delta;
//    cout << pw << " " << cur << endl;
    int ans = 0;
    while (pw >= 0 && abs (cur) < MAX) {
    	ll na = a[pw] - cur;
//    	cerr << pw << " " << na << endl;
    	if (abs (na) <= m && (na != 0 || pw != n)) ans++;
    	cur *= 2;
    	pw--;
    }
    printf ("%d\n", ans);
	return 0;
}
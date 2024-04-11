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

int x[16];
int y[16];

int main()
{
    scanf ("%d", &n);
    int cnt = 1;
    for (int i = 0; i < n; i++) {
    	scanf ("%d", &y[i]);
    	cnt = cnt / gcd (cnt, y[i]) * y[i];
    } 
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    int sum = 0;
    for (int i = 0; i < cnt; i++)
    	for (int j = 0; j < n; j++)
    		if ((i % y[j]) == x[j]) {
    			sum++;
    			break;
    		}
    printf ("%.10f\n", (sum + 0.0) / cnt);
	return 0;
}
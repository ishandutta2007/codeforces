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
 
//const int ROLL = 8;
#define ROLL 16
const int K = 127;
 
int n;
int m;
int x[200010];
int p[K + 1][200010];
 
int get (int y) {
	int l = -1, r = n;
	while (r - l > 1) {
		int s = (l + r) / 2;
		if (x[s] >= y) r = s; else l = s;
	}
	re r;
}
 
inline int sub (int x, int l) {
	re x - l;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    sort (x, x + n);
   	for (int j = 0; j <= K; j++)
	    for (int i = n - 1; i >= 0; i--)
    		p[j][i] = p[j][i + 1] ^ (x[i] - j);
    int q;
    scanf ("%d", &q);
    for (int i = 0; i < q; i++) {
    	int l, r;
    	scanf ("%d%d", &l, &r);
    	int cl = get (l);
    	int cr = get (r + 1);
    	int tmp = (p[l & K][cl] ^ p[l & K][cr]) & K;
//    	printf ("%d %d = %d\n", cl, cr, tmp);
    	if (tmp) {
    		printf ("A");
    		continue;
    	}
    	int ccr = cr - ROLL;
    	int cur0 = 0;
    	int cur1 = 0;
    	int cur2 = 0;
    	int cur3 = 0;
    	int cur4 = 0;
    	int cur5 = 0;
    	int cur6 = 0;
    	int cur7 = 0;
    	int cur8 = 0;
    	int cur9 = 0;
    	int cur10 = 0;
    	int cur11 = 0;
    	int cur12 = 0;
    	int cur13 = 0;
    	int cur14 = 0;
    	int cur15 = 0;
    	int j = cl;
    	for (; j <= ccr; j += ROLL) {
    		cur0 ^= sub (x[j], l);//x[j] - l;
    		cur1 ^= sub (x[j + 1], l);
    		cur2 ^= sub (x[j + 2], l);
    		cur3 ^= sub (x[j + 3], l);
    		cur4 ^= sub (x[j + 4], l);
    		cur5 ^= sub (x[j + 5], l);
    		cur6 ^= sub (x[j + 6], l);
    		cur7 ^= sub (x[j + 7], l);
    		cur8 ^= sub (x[j + 8], l);
    		cur9 ^= sub (x[j + 9], l);
    		cur10 ^= sub (x[j + 10], l);
    		cur11 ^= sub (x[j + 11], l);
    		cur12 ^= sub (x[j + 12], l);
    		cur13 ^= sub (x[j + 13], l);
    		cur14 ^= sub (x[j + 14], l);
    		cur15 ^= sub (x[j + 15], l);
    	}
    	int ans = cur0 ^ cur1 ^ cur2 ^ cur3 ^ cur4 ^ cur5 ^ cur6 ^ cur7 ^ cur8 ^ cur9 ^ cur10 ^ cur11 ^ cur12 ^ cur13 ^ cur14 ^ cur15;
    	for (; j < cr; j++) ans ^= sub (x[j], l);
    	if (ans) printf ("A"); else printf ("B");
    }
    printf ("\n");
	re 0;
}
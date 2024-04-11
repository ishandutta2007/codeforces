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
int a00, a11, a01, a10;

int main () {
	cin >> a00 >> a01 >> a10 >> a11;
	int a0 = 0, a1 = 0;
	while (a0 * (a0 - 1) / 2 < a00) a0++;
	while (a1 * (a1 - 1) / 2 < a11) a1++;
	if (a0 == 0 && a01 + a10 != 0) a0++;
	if (a1 == 0 && a01 + a10 != 0) a1++;
	if (a0 + a1 == 0) a0++;
	if (a0 * (a0 - 1) / 2 != a00 || a1 * (a1 - 1) / 2 != a11 || a01 + a10 != a0 * a1) {
		printf ("Impossible\n");
		re 0;
	}
	if (a0 == 0) cout << string (a1, '1') << endl; else 
	if (a1 == 0) cout << string (a0, '0') << endl; else {
		int full = a01 / a0;
		int rem = a01 % a0;
		if (rem == 0) 
			cout << string (a1 - full, '1') + string (a0, '0') + string (full, '1') << endl;
		else
			cout << string (a1 - full - 1, '1') + string (rem, '0') + "1" + string (a0 - rem, '0') + string (full, '1') << endl;	
	}
	return 0;
}
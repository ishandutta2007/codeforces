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
int cnt[1 << 20];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[20], h[20];
		scanf (" %s %s", s, h);
		int mask = 0;
		for (int j = 0; h[j]; j++) mask = mask * 2 + (h[j] - '0') % 2;
		if (s[0] == '?') printf ("%d\n", cnt[mask]); else
		if (s[0] == '+') cnt[mask]++; else cnt[mask]--;
	}
	return 0;
}
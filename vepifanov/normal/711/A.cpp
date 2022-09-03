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
string s[1000];

int main () {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	int ok = 0;
	for (int i = 0; i < n; i++) {
		if (s[i][0] == 'O' && s[i][1] == 'O') {
			ok = 1;
			s[i][0] = s[i][1] = '+';
			break;
		}
		if (s[i][3] == 'O' && s[i][4] == 'O') {
			ok = 1;
			s[i][3] = s[i][4] = '+';
			break;
		}
	}                     
	if (ok) {
		printf ("YES\n");
		for (int i = 0; i < n; i++) cout << s[i] << endl;
	} else printf ("NO\n");
	return 0;
}
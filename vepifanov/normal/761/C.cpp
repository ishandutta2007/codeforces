#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

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
int b0[50];
int b1[50];
int b2[50];

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		b0[i] = b1[i] = b2[i] = 1e8;
		for (int j = 0; j < m; j++) {
			int cur = min (j, m - j);
			if (s[j] >= '0' && s[j] <= '9') b0[i] = min (b0[i], cur);
			if (s[j] >= 'a' && s[j] <= 'z') b1[i] = min (b1[i], cur);
			if (s[j] == '#' || s[j] == '*' || s[j] == '&') b2[i] = min (b2[i], cur);
		}
	}
	int ans = 1e8;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				for (int k = 0; k < n; k++)
					if (i != k && j != k)
						ans = min (ans, b0[i] + b1[j] + b2[k]);
	cout << ans << endl;
	return 0;
}
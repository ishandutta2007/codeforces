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
int k;
char g[1001][1001];
int sum[1001][1001][26];
int p1[300000];
int p2[300000];
int q1[300000];
int q2[300000];
int u[300000];
ll res[1001][1001][27];

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf (" %s", g[i]);
	for (int i = 0; i < k; i++) {
		int i1, j1, i2, j2;
		char c;
		scanf ("%d%d%d%d %c", &i1, &j1, &i2, &j2, &c); i1--; j1--;
		int ch = c - 'a';
		sum[i1][j1][ch]++;
		sum[i2][j1][ch]--;
		sum[i1][j2][ch]--;
		sum[i2][j2][ch]++;
		p1[i] = i1;
		p2[i] = i2;
		q1[i] = j1;
		q2[i] = j2;
		u[i] = ch;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 26; k++) {
				if (i > 0) sum[i][j][k] += sum[i - 1][j][k];
				if (j > 0) sum[i][j][k] += sum[i][j - 1][k];
				if (i > 0 && j > 0) sum[i][j][k] -= sum[i - 1][j - 1][k];
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int rem = k;
			for (int t = 0; t < 26; t++) rem -= sum[i][j][t];
			sum[i][j][g[i][j] - 'a'] += rem;
			int cur = 0, tmp = k;
			for (int t = 0; t < 26; t++) cur += t * sum[i][j][t];
			for (int t = 0; t < 26; t++) {
				res[i][j][t] = cur;
				tmp -= sum[i][j][t];
				cur = cur - tmp + (k - tmp);
			}
			res[i][j][26] = res[i][j][g[i][j] - 'a'];
		}
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			for (int t = 0; t <= 26; t++)
				res[i][j][t] = res[i][j][t] + res[i + 1][j][t] + res[i][j + 1][t] - res[i + 1][j + 1][t];
	ll ans = 1e18;
	for (int i = 0; i < k; i++) {
		int i1 = p1[i];
		int j1 = q1[i];
		int i2 = p2[i];
		int j2 = q2[i];
		int ch = u[i];
		ll cur = res[0][0][26];
		cur = cur - res[i1][j1][26] + res[i2][j1][26] + res[i1][j2][26] - res[i2][j2][26];
		cur = cur + res[i1][j1][ch] - res[i2][j1][ch] - res[i1][j2][ch] + res[i2][j2][ch];
		ans = min (ans, cur);
	}
	cout << ans << endl;
	return 0;
}
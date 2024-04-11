#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int mod = 1000000007;

int n;
int m;
int k;
int f[1000001];
int fi[1000001];
int cnt[1001][1001];

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int main () {
	scanf ("%d%d%d", &n, &m, &k);	
	if (m == 1) {
		printf ("%d\n", power (k, n));
		re 0;
	}
	f[0] = fi[0] = 1;
	for (int i = 1; i <= k; i++) {
		f[i] = ((ll)f[i - 1] * i) % mod;
		fi[i] = power (f[i], mod - 2);
	}
	memset (cnt, 0, sizeof (cnt));
	cnt[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++) {
			cnt[i + 1][j] = (cnt[i + 1][j] + (ll)cnt[i][j] * j) % mod;
			cnt[i + 1][j + 1] = (cnt[i + 1][j + 1] + (ll)cnt[i][j] * (j + 1)) % mod;
		}
	int ans = 0;
	for (int a = 1; a <= n; a++)
		for (int b = 0; b <= a; b++)
			if (2 * a - b <= k) {
				ll tmp = ((ll)f[k] * fi[b]) % mod;
				tmp = (tmp * fi[a - b]) % mod;
				tmp = (tmp * fi[a - b]) % mod;
				tmp = (tmp * fi[k - 2 * a + b]) % mod;
				tmp = (tmp * power (b, n * (m - 2))) % mod;
				tmp = (tmp * cnt[n][a]) % mod;
				tmp = (tmp * cnt[n][a]) % mod;
				ans = (ans + tmp) % mod;
			}
	printf ("%d\n", ans);
	return 0;
}
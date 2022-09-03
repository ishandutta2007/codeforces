#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

const int len = 15;
const int MAX = (1 << len) - 1;

int n;
int m;
int p[8], cnt[1024];
int g[1024][1024];
int g1[1024][1024];
int w[1024][32];
int one[MAX + 1];

inline int calc (int x) {
	re one[x & MAX] + one[x >> len];
}

int main() {
	for (int i = 1; i <= MAX; i++) one[i] = one[i >> 1] + (i & 1);
	scanf ("%d%d", &n, &m);	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		g[a][b] = g[b][a] = 1;
		w[a][b / 30] |= 1 << (b % 30);
		w[b][a / 30] |= 1 << (a % 30);
		cnt[a]++;
		cnt[b]++;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				g1[i][k] += g[i][j] & g[j][k];
	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				ans += (ll)g[i][k] * g1[i][j] * g1[j][k] * g[i][k];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[i][j]) {
				int cur = 0;
				for (int k = 0; k < 32; k++)
					cur += calc (w[i][k] & w[j][k]);
				ans -= 5 * cur * (cnt[i] - 1);
			}
	cout << ans / 10 << endl;
	return 0;
}
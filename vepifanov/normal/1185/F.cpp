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

int n;
int m;
int cnt[1 << 9];
int best[1 << 9][2];
int cost[100000];

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int k;
		scanf ("%d", &k);
		int cur = 0;
		for (int j = 0; j < k; j++) {
			int x;
			scanf ("%d", &x); x--;
			cur |= 1 << x;
		}
		cnt[cur]++;
	}
	for (int i = 0; i < (1 << 9); i++) best[i][0] = best[i][1] = -1;
	for (int i = 0; i < m; i++) {
		int k;
		scanf ("%d%d", &cost[i], &k);
		int cur = 0;
		for (int j = 0; j < k; j++) {
			int x;
			scanf ("%d", &x); x--;
			cur |= 1 << x;
		}
		if (best[cur][0] == -1 || cost[best[cur][0]] > cost[i]) {
			best[cur][1] = best[cur][0];
			best[cur][0] = i;
		} else
		if (best[cur][1] == -1 || cost[best[cur][1]] > cost[i]) best[cur][1] = i;
	}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < (1 << 9); j++)
			if ((j >> i) & 1)
				cnt[j] += cnt[j ^ (1 << i)];
	int ans = -1, sum = 0;
	int ai = 0, aj = 0;
	for (int i = 0; i < (1 << 9); i++)
		for (int j = i; j < (1 << 9); j++)
			if (best[i][0] != -1 && best[j][int (i == j)] != -1) {
				int cur = cnt[i | j];
				if (cur > ans || (cur == ans && sum > cost[best[i][0]] + cost[best[j][int (i == j)]])) {
					ans = cur;
					sum = cost[best[i][0]] + cost[best[j][int (i == j)]];
					ai = best[i][0];
					aj = best[j][int (i == j)];
				}
			}
	printf ("%d %d\n", ai + 1, aj + 1);
	re 0;
}
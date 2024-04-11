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

int n;
int m;
int l[300], v[300][300], t[300][300], q[1001];

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &l[i]);
		for (int j = 0; j < l[i]; j++) {
			scanf ("%d%d", &v[i][j], &t[i][j]);
			if (j > 0) t[i][j] += t[i][j - 1];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int k = 0;
			q[k++] = 0;
			for (int p = 0; p < l[i]; p++) q[k++] = t[i][p];
			for (int p = 0; p < l[j]; p++) q[k++] = t[j][p];
			sort (q, q + k);
			k = unique (q, q + k) - q;
			int a = 0, b = 0, ls = 2, x = 0, y = 0;
			for (int p = 1; p < k; p++) {
				int d = q[p] - q[p - 1];
				while (a < l[i] && t[i][a] < q[p]) a++;
				while (b < l[j] && t[j][b] < q[p]) b++;
				if (a == l[i] || b == l[j]) break;
				x += v[i][a] * d;
				y += v[j][b] * d;
				if (x == m && y == m) break;
				int cs = int (x > y) - int (x < y);
				if (ls == 2) ls = cs; else
				if (ls != cs) {
					ls = cs;
					ans += int (cs != 0);	
				}
				if (x == m || y == m) break;
			}
		}
	printf ("%d\n", ans);
	return 0;
}
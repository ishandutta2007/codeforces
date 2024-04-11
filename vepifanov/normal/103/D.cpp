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

const int MAX = 500;

int n;
int m;
ll sum[MAX + 1][MAX];
int x[300000];
ll res[300000];
vii v[300000];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--;
		if (b >= MAX) {
			for (int j = a; j < n; j += b) res[i] += x[j];
		} else {
			v[a].pb (mp (b, i));
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		int j = i % MAX;
		for (int k = 1; k < MAX; k++)
			sum[j][k] = x[i] + sum[(j + k) % MAX][k];
		for (int t = 0; t < sz (v[i]); t++)
			res[v[i][t].se] = sum[j][v[i][t].fi];
	}
	for (int i = 0; i < m; i++) cout << res[i] << "\n";
	return 0;
}
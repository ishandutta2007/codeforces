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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 200000;

int n;
int m;
int was[N + 1];
int d[N + 1];
int q[N + 1];
int res[N + 1];
int cnt[N + 1];
int ct;

int go (int x) {
	ct++;
	int l = 0, r = 1;
	q[0] = x;
	was[x] = ct;
	d[x] = 0;
	while (l < r) {
		int x = q[l++];
		res[x] += d[x];
		cnt[x]++;
		if (x / 2 >= 1 && was[x / 2] != ct) {
			was[x / 2] = ct;
			d[x / 2] = d[x] + 1;
			q[r++] = x / 2;
		}
		if (x * 2 <= N && was[x * 2] != ct) {
			was[x * 2] = ct;
			d[x * 2] = d[x] + 1;
			q[r++] = x * 2;
		}
	}
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		go (x);
	}
	int ans = 1e9;
	for (int i = 1; i <= N; i++)
		if (cnt[i] == n)
			ans = min (ans, res[i]);
	printf ("%d\n", ans);
    return 0;
}
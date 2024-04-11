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

const int N = 5001;

int n;
int m;
ll rev[N][N];
int x[N];
int y[N];
ll s[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
	s[n] = 0;
	for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + (ll)x[i] * y[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			rev[i][j] = (ll)x[i] * y[j];
			if (i > 0) rev[i][j] += rev[i - 1][j + 1];
		}
	ll sum = s[0];
	ll ans = sum;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			ll cur = sum - (s[i] - s[j + 1]) + rev[j][i];
			if (i > 0) cur -= rev[i - 1][j + 1];
			ans = max (ans, cur);
		}
	printf ("%lld\n", ans);	
    return 0;
}
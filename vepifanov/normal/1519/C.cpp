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

int n;
int m;

vi v[200000];
int x[200000];
int y[200000];
ll s[200001];
ll res[200001];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			v[i].clear ();
			res[i + 1] = 0;
		}	
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
		for (int i = 0; i < n; i++) v[x[i] - 1].pb (y[i]);
		for (int i = 0; i < n; i++) res[i] = 0;
		for (int i = 0; i < n; i++) {
			sort (all (v[i]));
			reverse (all (v[i]));
			s[0] = 0;
			for (int j = 0; j < sz (v[i]); j++) s[j + 1] = s[j] + v[i][j];
			for (int j = 1; j <= sz (v[i]); j++) res[j] += s[sz (v[i]) - sz (v[i]) % j];
		}
		for (int j = 1; j <= n; j++) printf ("%lld ", res[j]);
		printf ("\n");
	}
    return 0;
}
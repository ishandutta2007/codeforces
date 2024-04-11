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
ii x[3000];
ll res[3001];

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &x[i].fi, &x[i].se);
		x[i].fi = -x[i].fi;
	}
	sort (x, x + n);
	for (int i = 0; i < n; i++) res[i] = 1e17;
	res[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		ll cur = res[i + 1] + x[i].se, len = 0;
		for (int j = i; j >= 0; j--) {
			res[j] = min (res[j], cur);
			if (j == 0) break;
			len += x[j].fi - x[j - 1].fi;
			cur += len;
		}
	}	
	cout << res[0] << endl;
	return 0;
}
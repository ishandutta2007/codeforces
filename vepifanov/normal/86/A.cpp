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

ll rev (ll x) {
	ll b = 1;
	while (b <= x) b *= 10;
	re b - x - 1;
}

int main() {
	scanf ("%d%d", &n, &m);	
	ll ans = 0;
	ans = max (ans, rev (n) * n);
	ans = max (ans, rev (m) * m);
	ll cur = 5;
	for (int i = 0; i < 9; i++) {
		if (cur >= n && cur <= m) ans = max (ans, cur * rev (cur));
		cur *= 10;
	}
	cout << ans << endl;
	return 0;
}